# define E1 6
# define M1 7
# define E2 5
# define M2 4
# define Left 2
# define Right 3

  int detect = 0;
  int Button = 0;
  int lef = 0;
  int rig = 0;
  float count1 = 0;
  float count2 = 0;
  float velocity1, velocity2;
  int startMills = 0;
  float var1;
  float var2;
  float desiredspeed = 2;
  float actualspeed1, actualspeed2;
  float K = 0.15;
  float fuck1, fuck2;
  float current1, current2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(M1,OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  lef = digitalRead(Left);
  rig = digitalRead(Right);
  interrupts();
  attachInterrupt(0, myfunction1, CHANGE);
  attachInterrupt(1, myfunction2, CHANGE);
  digitalWrite(M1, HIGH);
  digitalWrite(M2,HIGH);
  analogWrite(E1, 150);
  analogWrite(E2, 150);
  current1 = 150;
  current2 = 150;
}

void loop() {
      CountspeedL();
      CountspeedR();
      Serial.print("velocity1 is ");
      Serial.println(velocity1);
      Serial.print("velocity2 is ");
      Serial.println(velocity2);
      Serial.print("Pwm1 is ");
      Serial.println(actualspeed1);
      Serial.print("Pwm2 is ");
      Serial.println(actualspeed2);
      Serial.print("fuck1 ");
      Serial.println(fuck1);
      Serial.print("fuck2 ");
      Serial.println(fuck2);
      delay(1000);
  
}
void myfunction1()
  {
    if(lef != digitalRead(Left))
    {
       lef = digitalRead(Left);
       count1++;
    }
}
void myfunction2()
  {
    if(rig != digitalRead(Right))
    {
       rig = digitalRead(Right);
       count2++;
    }
  }
void CountspeedL()
{
  var1 = (count1 / 16);
  int currentMills = (micros() - startMills) / 1000000;
  velocity1 = (var1 / currentMills)*3.25 * 2 * PI;
  actualspeed1 = K * (desiredspeed - velocity1);
  fuck1 = (actualspeed1/velocity1)*255;
  current1 = current1 + fuck1;  
  analogWrite(E2,current1);
  Serial.print("current1 ");
  Serial.println(current1);
}

void CountspeedR()
{
  var2 = count2 / 16;
  int currentMills = (millis() - startMills) / 1000;
  velocity2 = (var2 / currentMills)*3.25 * 2 * PI;
  actualspeed2 = K * (desiredspeed - velocity2);
  fuck2 = (actualspeed2/velocity2)*255;
  //current2= current2 + fuck2;
  analogWrite(E1,current2);
}
  //do a count variable, count and use if loop for it to be count 0 to 48 then 48 to 80 then else for it to move forward or backward and spin for step 3, basiclly change up the button for it to trigger to 
  //go forward first
  // put your main code here, to run repeatedly:
 
