#include <Servo.h>
#define echoPin 7
#define trigPin 6
Servo leftservo;
Servo rightservo;  


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  leftservo.attach(9);
  rightservo.attach(10);
}

void loop()
{
  int distance,duration;
  digitalWrite(trigPin, HIGH);
  delay(200);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance=(duration/2)/29.1;
  Serial.println("");
  Serial.println(distance);
  if(distance >7) // for going forward
  { 
   leftservo.write(360); // left wheel forward
   rightservo.write(-360); // right wheel forward 
   }
   else // obstacle detected turn left
  {
   leftservo.write(-360); //left wheel backward
   rightservo.write(-360); // right wheel forward  
  }   
}
