#define isensor1 3 // ir sensor no. one on pin no. 3
#define isensor2 4 // ir sensor no. two on pin no. 4
#define isensor3 5 // ir sensor no. three on pin no. 5
#define isensor4 6 // ir sensor no. four on pin no. 6
#define led1 7 // led no. one on pin no. 7
#define led2 8 // led no. two on pin no. 8
#define led3 9 // led no. three on pin no. 9
#define led4 13 // led no. four on pin no. 10

void setup()
{
Serial.begin(9600);  // put your setup code here, to run once:
pinMode(isensor1,INPUT);
pinMode(isensor2,INPUT);
pinMode(isensor3,INPUT);
pinMode(isensor4,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
}

void loop() 
{
 
 if(digitalRead(isensor1)==LOW)
  {
    digitalWrite(led1,HIGH);
    Serial.println("sens1");
   }
  else
   {
     digitalWrite(led1,LOW);
    } 
    
    if(digitalRead(isensor2)==LOW)
  {
    digitalWrite(led2,HIGH);
   }
  else
   {
     digitalWrite(led2,LOW);
    } 
    
    if(digitalRead(isensor3)==LOW)
  {
    digitalWrite(led3,HIGH);
   }
  else
   {
     digitalWrite(led3,LOW);
    }
    
    if(digitalRead(isensor4)==LOW)
  {
    digitalWrite(led4,HIGH);
   }
  else
   {
     digitalWrite(led4,LOW);
    }
  // put your main code here, to run repeatedly:

}
