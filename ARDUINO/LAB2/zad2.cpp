#define B1 2
#define B2 4
bool lB1 = HIGH;
long time = 0;

void setup()
{
  pinMode(B1, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  Serial.println("Start");

}

void loop()
{
  bool cB1 = digitalRead(B1);

  long now = millis();
  if(chB(B1, lB1))
  {
   	 if(digitalRead(B1) == HIGH) format(now - time);
    else time = millis();
  }

  lB1 = cB1;

}

bool chB(int button, bool before){
  if(digitalRead(button) != before)
  {
   	delay(20);
    if(digitalRead(button) != before)
  	{
    	return true;
  	}
  }
  return false;
}

void format(unsigned long t)
{
 char str[12];
 int ms = t % 1000;
 t = t / 1000;
 int h = t / 3600;
 t = t % 3600;
 int m = t / 60;
 int s = t % 60;
 sprintf(str, "%01d:%02d:%02d.%04d", h, m, s, ms);
 Serial.println(str);
}


