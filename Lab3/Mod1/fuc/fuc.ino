# include <Arduino_LSM6DS3.h> 
# define E1 6 //speed right
# define M1 7 //direction
# define E2 5
# define M2 4
//# define leftHighSignal 8
# define leftReadSignal 11
//# define rightHighSignal 10
# define rightReadSignal 12


void setup() {
  // put your setup code here, to run once:
    pinMode(M1,OUTPUT);
    pinMode(M2, OUTPUT);
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    //pinMode(leftHighSignal, OUTPUT);
    //pinMode(rightHighSignal, OUTPUT);
    pinMode(rightReadSignal, INPUT);
    pinMode(leftReadSignal, INPUT);
    //digitalWrite(leftHighSignal, HIGH);
    //digitalWrite(rightHighSignal, HIGH);
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 100);
    analogWrite(E2, 100);
    Serial.begin(9600);
    
//  while (!Serial);
//  if (!IMU.begin()) {
//    Serial.println("Failed to initialize IMU!");
//    while (1);
//  }
    
//     timest = millis()/1000.0;
}

void loop() {
  Forward(); 
  ReactBumpers();
}
  // put your main code here, to run repeatedly:
void ReactBumpers(){
  int rSig = digitalRead(rightReadSignal);
  int lSig = digitalRead(leftReadSignal);
  if( lSig == 0 && rSig == 0){
    Serial.println("Both bumpers hit");
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    delay(2000);
    digitalWrite(M2, HIGH);
    delay(1000);
  }else if(lSig == 0){
    Serial.println("left bumpers hit");
  } else if(rSig == 0){
        Serial.println("right bumpers hit");
  } else {
        Serial.println("NO bumpers hit");
  }
}

void Forward(){
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 100);
  analogWrite(E2, 100);
}
