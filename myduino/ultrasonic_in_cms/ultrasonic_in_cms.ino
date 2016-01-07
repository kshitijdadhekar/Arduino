#define echoPin1 9
#define trigPin1 8
#define echoPin2 11
#define trigPin2 10
int distance1,distance2;
int duration1,duration2;


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  sensor1();
  sensor2();
  delay(100);
}
void sensor1()
{
  int distance1,duration1;
  digitalWrite(trigPin1, HIGH);
  delay(50);
  digitalWrite(trigPin1, LOW);
  duration1=pulseIn(echoPin1, HIGH);
  distance1=(duration1/2)/29.1;
  Serial.print(distance1);
  Serial.print("CM");
  if(distance1 <=10 && distance1>0)
  {
     digitalWrite(3,HIGH);
     delay(10);
     Serial.println("\tObstacle at 10cms");
  }
  else
  {
    digitalWrite(3,LOW); 
    Serial.println("\tNo obstacle at 10cms");
  }  
    
 }
void sensor2()
{
  int distance2,duration2;
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin2, LOW);
  duration2=pulseIn(echoPin2, HIGH);
  distance2=(duration2/2)/29.1;
  Serial.print(distance2);
  Serial.print("CM");
  if(distance2 <=10 && distance2>0)
  {
     digitalWrite(5,HIGH);
     delay(100);
     Serial.println("\tObstacle at 10cms");
  }
  else
  {
    digitalWrite(5,LOW); 
    Serial.println("\tNo obstacle at 10cms");
  }  
   
 }
 
 
