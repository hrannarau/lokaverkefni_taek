#include <Servo.h> //using the servo library

Servo myservo; // create an servo object
int potient = A0;
int potientValue = 0;
int stada = HIGH;
int led = 4;
const int trigpin = 10;
const int echopin = 9;
float cm;
int xpin = A1;
int takki = 13;
int xPosition = 0;
int yPosition = 0;
int manual = 0;

int takki_stada = HIGH;
int takki_stada_adur = LOW;

int snua = 0;
int snuningur = 0;

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
  Serial.print("Cm: ");
  Serial.println(cm);
  potientValue = analogRead(potient);
  potientValue = map(potientValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  int i = 0;
  if (manual == 0) {
    
  if(snuningur == 180){
      snua = 1;
    } else if(snuningur == 0){
      snua = 0;
    }

  if(snua == 0){
    snuningur++;
    snuningur++;
    } else {
        snuningur--;
        snuningur--;
      }
  myservo.write(snuningur);
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
    
    takki_stada = digitalRead(takki);
      Serial.print("Takki:");
  Serial.println(takki_stada);
    if(takki_stada == LOW && takki_stada_adur == HIGH) {
      if(manual == 1) {
        manual = 0;
  
      } else {
        manual = 1;
      }

  }
  if(manual == 1) {
      xPosition = analogRead(xpin);
      xPosition = map(xPosition, 0, 1023, 0, 180);
      Serial.print("X: ");
      Serial.println(xPosition);
      myservo.write(xPosition);
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
  
  Serial.print("manual: ");
  Serial.println(manual);
  takki_stada_adur = takki_stada;
  }
