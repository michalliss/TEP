#define B1 2
#define B2 4
#define LED 6
String msg = "";
bool blinkflag = false;
bool blinkstate = false;
long blinktimer = 0;
int speed = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start");

}

void loop()
{

  if (Serial.available() > 0)
  {
    msg = Serial.readStringUntil('\n');
    if (msg == "LED ON") {
      Serial.println("Przyjęto LED ON");
      digitalWrite(LED, HIGH);
      blinkflag = false;
    }
    if (msg == "LED OFF") {
      Serial.println("Przyjęto LED OFF");
      digitalWrite(LED, LOW);
      blinkflag = false;
    }
    if (msg == "LED BLINK") {
      Serial.println("Przyjęto LED BLINK");
      blinkflag = true;
    }
    if (msg.length() > 10) {
      String polecenie = msg.substring(0, 10);
      String liczba = msg.substring(10);
      if (polecenie == "LED BLINK ")
      {
        if (isNumerical(liczba)) {
          if (liczba.toInt() != 0) {
            speed = liczba.toInt();
            blinkflag = true;
            Serial.println("Przyjęto LED BLINK " + String(speed));
          }
          else err();
        }
        else err();

      } else err();

    } else err();


  }

  if (blinkflag == true && millis() > blinktimer + speed) {
    blink();
    blinktimer = millis();
  }
  msg = "";

  delay(500);
}

bool isNumerical(String &s) {
  for (int i = 0; i < s.length(); i++) {
    if (!isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

void err() {
  Serial.println("Niepoprawna komenda!");
}

void blink()
{
  if (blinkstate) {
    digitalWrite(LED, HIGH);
    blinkstate = !blinkstate;
  } else {
    digitalWrite(LED, LOW);
    blinkstate = !blinkstate;
  }

}




