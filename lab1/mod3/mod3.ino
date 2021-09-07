#include <Servo.h>

Servo mypan, mytilt, mygrip;
int tilt_angle = 20;
int pan_angle = 96;
int grip_angle = 40;
int change;
int forcepin = 11;
int ledpin = 12;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  pinMode(forcepin, OUTPUT);
  mypan.attach(8);
  mytilt.attach(9);
  mygrip.attach(10);
  mypan.write(pan_angle);
  mytilt.write(tilt_angle);
  delay(1000);
  mygrip.write(grip_angle);
  delayMicroseconds(10);
  pinMode(forcepin, INPUT);
}

void loop() {   
  if(tilt_angle < 160)
  {
    mytilt.write(++tilt_angle);
    delay(25.3);
  }
  if(tilt_angle == 160)
  {
    mytilt.write(tilt_angle);
    if(grip_angle == 40)
    {
      change = 0;
    }
    else if (grip_angle == 180)
    {
      change = 1;
    }
    if(change == 0)
    {
      if(grip_angle < 180)
      {
        grip_angle++;
        mygrip.write(grip_angle);
        delay(10);
      }
    }
    else if(change == 1)
    {
      if( grip_angle > 40)
      { 
        grip_angle--;
        mygrip.write(grip_angle);
        delay(10);
      }
    }
  }
  /*Serial.println(digitalRead(forcepin));
  if(digitalRead(forcepin) == HIGH)
  {
    digitalWrite(ledpin, HIGH);
  }
  else
  {
    mygrip.write(++grip_angle);
    digitalRead(forcepin);
  }
  */

  // put your main code here, to run repeatedly:
}
