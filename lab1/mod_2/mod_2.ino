# define E1 6
# define M1 7
# define E2 5
# define M2 4
# define Touch 12
# define Left 2
# define Right 3
# define LEDPIN 13

int detect = 0;
int Button = 0;
int lef = 0;
int rig = 0;
int count = 0;
int velocity = 0;
//int startMills;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Touch, INPUT);
  pinMode(M1,OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(LEDPIN, OUTPUT);
  lef = digitalRead(Left);
  rig = digitalRead(Right);
  attachInterrupt(0, myfunction, CHANGE);
  interrupts();
  //startMills = millis();
}

void loop() {
  Button = digitalRead(Touch);
  Serial.println(Button);
  if(Button == 0)
  {
     detect = 1;
  }
  if(Button == 1 && detect == 1)
  {
    forward();
    
    if(count >= 48 && count <80)
    {
      backward();
    }
   else if(count >= 80 && count < 88)
   {
      spin90();
   }
   else if(count >= 88)
   {
      pause();
    //int currentMills = millis() - startMills;
    //velocity = (count / 16)/currentMills;
    //Serial.println(velocity);
   }
  }
  //do a count variable, count and use if loop for it to be count 0 to 48 then 48 to 80 then else for it to move forward or backward and spin for step 3, basiclly change up the button for it to trigger to 
  //go forward first
  // put your main code here, to run repeatedly:
}
void forward()
{
    digitalWrite(M1, HIGH);
    digitalWrite(M2,HIGH);
    analogWrite(E1, 127);
    analogWrite(E2, 127);
}
void backward()
{
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, 127);
    analogWrite(E2, 127);
}
void spin90()
{
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 127);
    analogWrite(E2, 127);
}
void pause()
{
    analogWrite(E1, 0);
    analogWrite(E2, 0);
}
void myfunction()
{
  if(lef != digitalRead(Left))
  {
    digitalWrite(LEDPIN, HIGH);
    lef = digitalRead(Left);
    count ++;
  }
  else
  {
    digitalWrite(LEDPIN, LOW);
  }
}
