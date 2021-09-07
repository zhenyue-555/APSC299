//#define LEDPIN 13//pin definitions
# define E1 6
# define M1 7
# define E2 5
# define M2 4
# define Left 2
# define Right 3
//# define BTNPIN 12

int state = 0;
int val;
float distL = 0, revoL = 0, veloL, distR = 0, revoR = 0, veloR, timest, timeend, countL = 0, countR = 0;
float inputL = 0, inputR=0;

void setup() {
 // pinMode(LEDPIN, OUTPUT);//set led pin as output
  //pinMode(BTNPIN, INPUT);//set button pin as input
  pinMode(Left, INPUT);// set encoder as input
  pinMode(Right, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Left), encoderCountL, CHANGE);// interrupt the movement function
  attachInterrupt(digitalPinToInterrupt(Right), encoderCountR, CHANGE);
  Serial.begin(9600);
  timest = millis()/1000;
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
  analogWrite(E2,115+inputL);
  digitalWrite(M1,HIGH);
  digitalWrite(M2,HIGH);
}


void loop() {
  
    moveMent();
    
    Serial.print(veloL);
    Serial.print("\t");
    Serial.print(veloR);
    Serial.print(" ");
    Serial.print("\r\n");
    delay(1000);
    
}
