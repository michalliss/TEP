#define B1 2
#define B2 4
int counter = 0;

void setup()
{
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  Serial.println("asdf");
  bool lastB1 = HIGH;
  bool lastB2 = HIGH;
}

void loop()
{
  if(bP(B1) && bP(B2))
  {
    blink(6, 200, counter);
    Serial.println("dwa na raz");
    bW(B1, B2);
  }


  else if(bP(B1))
  {
     counter++;
     Serial.println(counter);
     bW(B1);
  }

  else if(bP(B2))
  {
     counter--;
     Serial.println(counter);
     bW(B2);
  }

  delay(50);

}

bool bW(int button){
  	delay(20);
  	while(bP(button));
    delay(20);
}

bool bW(int button1, int button2){
  	delay(20);
  	while(bP(button1) && bP(button2));
    delay(20);
}

bool bP(int button){
  return digitalRead(button) == LOW;
}




void blink(int pin, int duration, int times)
{
  for(int i = 0;i< times;i++){
    digitalWrite(6, HIGH);
  	delay(duration);
  	digitalWrite(6, LOW);
 	delay(duration);
  }
}
