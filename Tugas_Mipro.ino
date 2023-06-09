//Ultrasonik
#include <Wire.h>
#define SOUND_SPEED 0.034
long duration;
float distanceCm;
const int trigPin = 5;
const int echoPin = 18;

//TrafficLED
#define LIGHT_1_RED 15
#define LIGHT_1_YELLOW 2
#define LIGHT_1_GREEN 4

//#define GREEN_LIGHT 0
//#define YELLOW_LIGHT 1
//#define RED_LIGHT 2

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LIGHT_1_RED, OUTPUT);
  pinMode(LIGHT_1_YELLOW, OUTPUT);
  pinMode(LIGHT_1_GREEN, OUTPUT);
}

// the loop function runs over and over again forever
void loop(){
//---------Bagian Ultrasonik-----------//
          digitalWrite(trigPin, LOW);
          delayMicroseconds(5);
          // Sets the trigPin on HIGH state for 10 micro seconds
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          
          // Reads the echoPin, returns the sound wave travel time in microseconds
          duration = pulseIn(echoPin, HIGH);
          
          // Calculate the distance
          distanceCm = duration * SOUND_SPEED/2;
          
          // Prints the distance in the Serial Monitor
          Serial.print("Jarak Anda : ");
          Serial.print(distanceCm);
          Serial.println(" cm");
          delay(500); 

 //---------Bagian LED Traffic-----------//
  if(distanceCm <= 10)
  { 
    digitalWrite(LIGHT_1_RED, HIGH);
    digitalWrite(LIGHT_1_YELLOW, LOW);
    digitalWrite(LIGHT_1_GREEN, LOW);
  }
  else if(distanceCm > 10 && distanceCm <= 20)
  {
    digitalWrite(LIGHT_1_RED, LOW);
    digitalWrite(LIGHT_1_YELLOW, HIGH);
    digitalWrite(LIGHT_1_GREEN, LOW);
  } 
  else
  {
    digitalWrite(LIGHT_1_RED, LOW);
    digitalWrite(LIGHT_1_YELLOW, LOW);
    digitalWrite(LIGHT_1_GREEN, HIGH);
  } 
}
