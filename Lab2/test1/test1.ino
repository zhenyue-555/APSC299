# include <Arduino_LSM6DS3.h> 
# define E1 6
# define M1 7
# define E2 5
# define M2 4
float x, y, z;
float timest, timend;
float temacc, avacc;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(M1,OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  analogWrite(E1, 255);
  analogWrite(E2, 255);
  digitalWrite(M1, HIGH);
  digitalWrite(M2,HIGH);

  while (!Serial);
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.begin(9600);
     timest = millis()/1000.0;
}


void loop() {

  count++;
  if (IMU.accelerationAvailable()) {
  IMU.readAcceleration(x, y, z);
  timend = millis()/1000.0;
  float xaccel = x * 9.81; 
  temacc = temacc + xaccel;  
  avacc = temacc / count;
  float xvel = avacc*(timend-timest);
  float xpos = xvel*(timend-timest);

    Serial.print(xaccel);
    Serial.print('\t');   
    Serial.print(xvel);
    Serial.print('\t');
    Serial.print(xpos);
    Serial.print('\t');
    Serial.print("\r\n");
    delay(1000);
  }
  // put your main code here, to run repeatedly:

}
