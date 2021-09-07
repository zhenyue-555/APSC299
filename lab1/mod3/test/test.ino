#include <Servo.h>
#define forsens 11
#define led 13
Servo mypan,mytilt, mygrip;





int tilt_angle= 20;
//int tilt_2 = 180;
int grip_angle= 0;
int pan_angle= 90;
int maxgrip=0;
int maxpan=0;
int maxtilt =0;
void setup() {
  // put your setup code here, to run once:
  //pinMode(led, OUTPUT);
  //digitalWrite(led, LOW);
//pinMode(forsens, OUTPUT);
//digitalWrite(forsens, LOW);
mypan.attach(8);
mytilt.attach(9);
mygrip.attach(10);
mygrip.write(grip_angle);
mypan.write(pan_angle);
mytilt.write(tilt_angle);
//mytilt.write(tilt_2);
//delayMicroseconds(10);
//pinMode(forsens, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(forsens));
if(digitalRead(forsens)==HIGH){
  digitalWrite(led, HIGH);
}
  else{
    mygrip.write(++grip_angle);
    delay(100);
  }
  

  if( tilt_angle<20)
  {
    tilt_angle = 20;
  }
  if( tilt_angle == 180)
  {
    if(maxgrip==0)
    {
      mygrip.write(++grip_angle);
      if(grip_angle == 180)
      {
       maxgrip =1;
      }
       delay(20);
    }
    else{
      mygrip.write(--grip_angle);
      if(grip_angle == 0)
      {
        maxgrip=0;
      }
      delay(20);
    }
  }
   else{
      mytilt.write(++tilt_angle);
        delay(20);

    }
  

}
