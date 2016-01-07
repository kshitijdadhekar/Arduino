int Leftmotorforward=8;
int Leftmotorbackward=9;
int Rightmotorforward=10;
int Rightmotorbackward=11;

void setup()
{
 Serial.begin(9600);
  pinMode(Leftmotorforward,OUTPUT);
  pinMode(Leftmotorbackward,OUTPUT);
  pinMode(Rightmotorforward,OUTPUT);
  pinMode(Rightmotorbackward,OUTPUT);

}

void loop()
{
 
int value = analogRead(A0);
Serial.println(value);
delay(100);
  if(value<=900)
  {
    movefan();
  }
moveleft();
}  

void moveForward()
{
  
  digitalWrite(Leftmotorforward,HIGH);
  digitalWrite(Leftmotorbackward,LOW);
  digitalWrite(Rightmotorforward,HIGH);
  digitalWrite(Rightmotorbackward,LOW);
  
}
void moveBackward()
{

  digitalWrite(Leftmotorforward,LOW);
  digitalWrite(Leftmotorbackward,HIGH);
  digitalWrite(Rightmotorforward,LOW);
  digitalWrite(Rightmotorbackward,HIGH);
}
void movefan()
{
  
  digitalWrite(Leftmotorforward,LOW);
  digitalWrite(Leftmotorbackward,LOW);
  digitalWrite(Rightmotorforward,LOW);
  digitalWrite(Rightmotorbackward,HIGH);
  delay(10000);
  
}
void moveleft()

{
 
  digitalWrite(Leftmotorforward,LOW);
  digitalWrite(Leftmotorbackward,HIGH);
  digitalWrite(Rightmotorforward,HIGH);
  digitalWrite(Rightmotorbackward,LOW);
  delay(50);
  digitalWrite(Leftmotorforward,LOW);
  digitalWrite(Leftmotorbackward,LOW);
  digitalWrite(Rightmotorforward,LOW);
  digitalWrite(Rightmotorbackward,LOW);
  delay(1000);
  

}



void moveStop()
{
  
  digitalWrite(Leftmotorforward,LOW);
  digitalWrite(Leftmotorbackward,LOW);
  digitalWrite(Rightmotorforward,LOW);
  digitalWrite(Rightmotorbackward,LOW);
}
