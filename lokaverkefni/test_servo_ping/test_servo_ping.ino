/*
  Adapted From: Analog Input by David Cuartielles and Tom Igoe
  Author: Malcolm Knapp
  Project: Ultrasonic Sensor to Servo 
  Date: 4/10/14
  Version: 0.1
  Description: This code shows how to use a Ultrasonic Distance Sensor to 
               control the "blink" rate of a servo. In this case "blink" means
               moving between two positions.

 */
// ---------- included libraries ------------ 
#include <Servo.h>
#include <NewPing.h>

// ---------- hardware pin defines  ----------- 
int triggerPin = 12;      // select the pin for ultrasonic trigger
int echoPin = 11;      // select the pin for echo

// ---------- variable initialization  ----------- 
int delayTime = 0; //variable that holds the delay time in milliseconds
int scaling = 1;
unsigned int uS = 0;      // holds the time it took for the pulse to be recived
unsigned int distance = 0; // holds the distance in centimeters
int maxValue = 200;    // in centimeter
int minValue = 0;      // in centimeter
int maxDistance = 200;   // in centimeters

// ---------- library initialization  -----------  
Servo myservo;  // create servo object to control a servo a maximum of eight servo objects can be created 
NewPing sonar(triggerPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
  // declare hardware connections
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // Input
  delay(50);  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  distance = uS / US_ROUNDTRIP_CM;  // convert time to distance
  // Debugging
  Serial.print("uS value: "); Serial.println(uS);
  Serial.print("Distance (cm): "); Serial.println(distance);

  // Processing 
  //Scaling
  delayTime = map (distance, minValue, maxValue, 200, 1023);
  Serial.print ("Delay in milliseconds: "); Serial.println (delayTime);
  // Modes
  // None - put new modes here

  // Output 
  myservo.write(155); 
  delay(delayTime); 
  myservo.write(30);
  delay(delayTime);    
}
