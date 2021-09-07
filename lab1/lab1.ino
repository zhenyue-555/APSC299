# define LEDPIN 7
# define Touch 8
int analogPin = A3;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  pinMode(Touch, INPUT);
}

void loop() {
  int Button = digitalRead(Touch);
  int Led = digitalRead(LEDPIN);
  Serial.println(val);
  if(Button == 0)
  {
    while(true){
    val = analogRead(analogPin);
    digitalWrite(LEDPIN, HIGH);
    delay (val);
    digitalWrite(LEDPIN, LOW);
    delay(val);
    }
  }
  else
  {
    digitalWrite(LEDPIN, LOW);
  }
  // put your main code here, to run repeatedly:
}
