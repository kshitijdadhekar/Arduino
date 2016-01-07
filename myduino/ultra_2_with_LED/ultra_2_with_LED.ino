#define echoPin1 7
#define trigPin1 6

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(13,OUTPUT);

}

void loop()
{
  sensor1();
  
  delay(100);
}
 
  
void sensor1()
{
  int distance1,duration1;
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin1, LOW);
  duration1=pulseIn(echoPin1, HIGH);
  distance1=(duration1/2)/29.1;
  Serial.print(distance1);
  Serial.print("CM");
  delay(100);
  /*if(distance1 <=10)
  {
     digitalWrite(13,HIGH);
     delay(50);
     Serial.println("\tObstacle at 10cms");
  }
  else
  {
     digitalWrite(13,LOW); 
    Serial.println("\tNo obstacle at 10cms");
  }  
*/
} 



