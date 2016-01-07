int Leftmotorforward=6;
int Leftmotorbackward=7;
int Rightmotorforward=8;
int Rightmotorbackward=9;

void setup()
{
  Serial.begin(9600);
  pinMode(Leftmotorforward,OUTPUT);
  pinMode(Leftmotorbackward,OUTPUT);
  pinMode(Rightmotorforward,OUTPUT);
  pinMode(Rightmotorbackward,OUTPUT);
  Serial.println("Connection Successful !");
}

void loop()
{
   if(Serial.available()>0)
   {
      int data= Serial.read();
      switch(data)
      {
        case 'U': moveForward();break;
        case 'D': moveBackward();break;
        case 'L': moveLeft();break;
        case 'R': moveRight();break;
        case 'C': moveStop();break;
        default : break;
      }
    }
    delay(50);
}  
void moveForward()
{
  Serial.println("Moving Forward");
  digitalWrite(Leftmotorforward,HIGH);
  digitalWrite(Leftmotorbackward,LOW);
  digitalWrite(Rightmotorforward,HIGH);
  digitalWrite(Rightmotorbackward,LOW);
}
void moveBackward()
{
  Serial.println("Moving Backward");
  digitalWrite(Leftmotorforward,LOW);
  digitalWrite(Leftmotorbackward,HIGH);
  digitalWrite(Rightmotorforward,LOW);
  digitalWrite(Rightmotorbackward,HIGH);
}
void moveLeft()
{
  Serial.println("Moving Left");
  digitalWrite(Leftmotorforward,LOW);
  digitalWrite(Leftmotorbackward,HIGH);
  digitalWrite(Rightmotorforward,HIGH);
  digitalWrite(Rightmotorbackward,LOW);
}
void moveRight()
{
  Serial.println("Moving Right");
  digitalWrite(Leftmotorforward,HIGH);
  digitalWrite(Leftmotorbackward,LOW);
  digitalWrite(Rightmotorforward,LOW);
  digitalWrite(Rightmotorbackward,HIGH);
}

void moveStop()
{
  Serial.println("Stopping");
  digitalWrite(Leftmotorforward,LOW);
  digitalWrite(Leftmotorbackward,LOW);
  digitalWrite(Rightmotorforward,LOW);
  digitalWrite(Rightmotorbackward,LOW);
}
