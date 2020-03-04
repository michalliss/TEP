#define B1 2
#define B2 4
int counter = 0;
#define inputCount 2
int inputPins[inputCount] = {2, 4};
bool inputState[inputCount] = {HIGH, HIGH};
bool inputFlags[inputCount] = {HIGH, HIGH};
bool lastInputState[inputCount] = {HIGH, HIGH};
unsigned long lastDebounceTime[inputCount];

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

  /*
  if (bP(B1) && bP(B2))
  {
    blink(6, 200, counter);
    Serial.println("dwa na raz");
    bW(B1, B2);
  }

  else if (bP(B1))
  {
    counter++;
    Serial.println(counter);
    bW(B1);
  }

  else if (bP(B2))
  {
    counter--;
    Serial.println(counter);
    bW(B2);
  }

  delay(50);
  */

  setInput();

  if (inputFlags[0] == LOW && inputFlags[1] == LOW)
  {
    blink(6, 200, counter);
    Serial.println("dwa na raz");
    inputFlags[0] = HIGH;
    inputFlags[1] = HIGH;
  }

  if (inputFlags[0] == LOW)
  {
    counter++;
    Serial.println(counter);
    inputFlags[0] = HIGH;
  }

  if (inputFlags[1] == LOW)
  {
    counter--;
    Serial.println(counter);
    inputFlags[1] = HIGH;
  }
}

void setInput()
{
  for (int i = 0; i < inputCount; i++)
  {
    int reading = digitalRead(inputPins[i]);
    if (reading != lastInputState[i])
    {
      lastDebounceTime[i] = millis();
    }

    if ((millis() - lastDebounceTime[i]) > 50)
    {
      if (reading != inputState[i])
      {
        inputState[i] = reading;
        if (inputState[i] == LOW)
        {
          inputFlags[i] = LOW;
        }
      }
    }

    lastInputState[i] = reading;
  }
}

bool bW(int button)
{
  delay(20);
  while (bP(button))
    ;
  delay(20);
}

bool bW(int button1, int button2)
{
  delay(20);
  while (bP(button1) && bP(button2))
    ;
  delay(20);
}

bool bP(int button)
{
  return digitalRead(button) == LOW;
}

void blink(int pin, int duration, int times)
{
  for (int i = 0; i < times; i++)
  {
    digitalWrite(6, HIGH);
    delay(duration);
    digitalWrite(6, LOW);
    delay(duration);
  }
}
