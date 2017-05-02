#include <Servo.h> //using the servo library

Servo myservo; // create an servo object
int potient = A0;
int potientValue = 0;
int stada = HIGH;
int led = 4;
const int trigpin = 10;
const int echopin = 9;
float cm;
int ypin = A0;
int xpin = A1;
int takki = 5;
int xPosition = 0;
int yPosition = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(2);
  pinMode(led, OUTPUT);
  pinMode(takki, INPUT_PULLUP);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  cm = pulseIn(echopin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  if(cm < 0)
  {
    cm = 0;
  }
  Serial.println(cm);
  potientValue = analogRead(potient);
  potientValue = map(potientValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 

  int i = 0;
  for (int i=0; i<=180; i++){
  myservo.write(i);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  cm = pulseIn(echopin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  if(cm < 0)
  {
    cm = 0;
  }
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  cm = pulseIn(echopin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  if(cm < 0)
  {
    cm = 0;
  }
  if (cm < 21){
    digitalWrite(led, HIGH);
    }
  else{
    digitalWrite(led, LOW);
    }
  delay(15);
    }
  int j = 180;
  for (int j=180; j>=0; j--){
  myservo.write(j);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  
  cm = pulseIn(echopin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  if(cm < 0)
  {
    cm = 0;
  }
  if (cm < 21){
    digitalWrite(led, HIGH);
    }
  else{
    digitalWrite(led, LOW);
    }
  delay(15);
  }
}
