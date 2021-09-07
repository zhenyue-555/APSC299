#include <Arduino_LSM6DS3.h>
#define M1 7
#define M2 4
#define E1 6
#define E2 5
#define IRS A5
int V;

void setup() {
  // put your setup code here, to run once:
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(IRS,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  V =  analogRead(IRS);
  Serial.println(V);
  if (V >= 510)
  {
    forward();
    delay(300);
    rotateLeft();
    delay(2000);
    stop1();
    delay(100000);
  }
}



void forward(){
  digitalWrite(M1, HIGH);
  analogWrite(E1, 200);
  digitalWrite(M2, HIGH);
  analogWrite(E2, 200);
}

void backward(){
  digitalWrite(M1, LOW);
  analogWrite(E1, 200);
  digitalWrite(M2, LOW);
  analogWrite(E2, 200);
}

void rotateLeft(){
  digitalWrite(M1, HIGH);
  analogWrite(E1, 200);
  digitalWrite(M2, LOW);
  analogWrite(E2, 200);
}

void rotateRight(){
  digitalWrite(M1, LOW);
  analogWrite(E1, 200);
  digitalWrite(M2, HIGH);
  analogWrite(E2, 200);
}
void stop1()
{
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}
