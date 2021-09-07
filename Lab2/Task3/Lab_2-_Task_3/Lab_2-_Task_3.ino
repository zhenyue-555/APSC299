//#define LEDPIN 13//pin definitions
#include <Arduino_LSM6DS3.h> 
# define E1 6
# define M1 7
# define E2 5
# define M2 4
# define Left 2
# define Right 3

int state = 0;
int val;
float distL = 0, revoL = 0, veloL, distR = 0, revoR = 0, veloR, timest, timeend, countL = 0, countR = 0;
float inputL = 0, inputR=0;
float x, y, z;
float tim,vel,pos;
float temtime;
float endtime;
void setup() {
 // pinMode(LEDPIN, OUTPUT);//set led pin as output
//  pinMode(BTNPIN, INPUT);//set button pin as input
  pinMode(Left, INPUT);// set encoder as input
  pinMode(Right, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Left), encoderCountL, CHANGE);// interrupt the movement function
  attachInterrupt(digitalPinToInterrupt(Right), encoderCountR, CHANGE);
  
 
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }
    
  Serial.begin(9600);
  
   timest = millis()/1000.0;
}

void encoderCountL() {
  countL += 1.0;
  revoL = countL/16.0;
  distL = revoL*3.25*2*3.1415;
  timeend = millis()/1000.0;
  veloL = distL/(timeend - timest);
}


void encoderCountR() {
  countR += 1.0;
  revoR = countR/16.0;
  distR = revoR*3.25*2*3.1415;
  timeend = millis()/1000.0;
  veloR = distR/(timeend - timest);
}
/*
void drivestraight(){
 veloL = distL/(timeend - timest);
 veloR = distR/(timeend - timest);
 inputL = (20 - veloL)*(128/veloL);
 inputR = (20 - veloR)*(128/veloR);

  }
*/
void moveMent(){
  veloL = distL/(timeend - timest);
  veloR = distR/(timeend - timest);
  inputL = (20 - veloL)*(128/veloL);
  inputR = (20 - veloR)*(128/veloR);
  analogWrite(E1,100+inputR);
  analogWrite(E2,89+inputL);
  digitalWrite(M1,HIGH);
  digitalWrite(M2,HIGH);
}


void loop() {
  endtime = millis()/1000.0;
  moveMent();
  if (IMU.accelerationAvailable()) {
  IMU.readAcceleration(x, y, z);
  /*tim = timeend - timest;
  Serial.print("time is");
  Serial.println(tim);
  */
  float xaccel = x * 9.81; 
  //temacc = temacc + xaccel;  
  //avacc = temacc / count;
  float xvel = xaccel*(endtime-temtime);
  vel = vel + xvel;
  float xpos = xvel*(endtime-temtime);
  pos = pos + xpos;
  Serial.print("enocer left ");
  Serial.print(veloL);
  Serial.print('\t');
  Serial.print("encoder right "); 
  Serial.println(veloR);
  Serial.print("the accelartion is ");
  Serial.println(xaccel);
  Serial.print("the velocity is ");   
  Serial.println(vel*10);
  Serial.print("the position is ");
  Serial.println(pos);
  delay(1000);
  temtime = endtime;
  }
}
