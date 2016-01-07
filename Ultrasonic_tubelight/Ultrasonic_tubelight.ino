#define echoPin1 8
#define trigPin1 9
#define echoPin2 10
#define trigPin2 11
int distance1,distance2,duration1,duration2;
int count1=0;
int count2=0;
int time=0;


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);// tubelight
  pinMode(5, OUTPUT);
  
}

void loop()
{
  time=0;
  sensor1();
  sensor2();
  if(distance1<11 && distance2>11)
  {  
    count1++;
    digitalWrite(3,HIGH);
    delay(100);
  }
   
  // sensor  2 count
  sensor1();
  sensor2();
  if(distance2<11 && distance1>11)
  {
    count2++ 
    digitalWrite(5,HIGH);
    delay(100);
  }
  
  do
  {
   sensor1();
   sensor2();
   time=time+100;
  }
  while(!(distance1<11 && distance2<11) || time=3000); //chutya ruka 3 secs ke liye

  // Serial.print(count1);
  //Serial.print(count2);
  if(count1==count2)
    {
     digitalWrite(4,HIGH);  
    }
 delay(200);
 
   
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
  Serial.print("\t");

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
  Serial.println("CM");

  
 }

