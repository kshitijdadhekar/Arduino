 #include<Servo.h>
int c1,c2,c5;
Servo myservo;
void setup() {
pinMode(3,INPUT); // left-right
pinMode(5,INPUT); // front-back
pinMode(6,INPUT); // servo pan
pinMode(7,OUTPUT); // pudhe
pinMode(8,OUTPUT); // maage
pinMode(10,OUTPUT); // aju
pinMode(11,OUTPUT); // baju
pinMode(9,OUTPUT); // servo out
myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
myservo.write(90);

Serial.begin(9600);
}
void loop() {
c1=(pulseIn(3,HIGH));
c2=(pulseIn(5,HIGH));
c5=(pulseIn(6,HIGH));
print1();
saglikade();
//pudhe_mage();
//aju_baju();
servopan();
}

void print1()
{
Serial.print(c1);
Serial.print("\t");
Serial.print(c2);
Serial.print("\t");
Serial.println(c5);
delay(200);
}

void saglikade()
{
if(c2>1550 && c2<1650)
{
digitalWrite(7,HIGH); // right forward
digitalWrite(10,HIGH); // left forward

}
else if(c2>1651 && c2<1850)
{
digitalWrite(7,HIGH); // rgiht forward
digitalWrite(10,HIGH); //left forward

}
else if(c2<1300 && c2 >1100)
{
  digitalWrite(8,HIGH); // right backward
  digitalWrite(11,HIGH);// left backward
  
}
else if(c2<1099 && c2 >999)
{
  digitalWrite(8,HIGH); // right backward
  digitalWrite(11,HIGH); // left backward
}   
else if(c1>1550 && c1<1650) //right turn
{
 digitalWrite(10,HIGH); //left forward
//  digitalWrite(8,HIGH); // right backward  

}
else if(c1>1651 && c1<1850) //right turn
{
  digitalWrite(10,HIGH); //left forward
//  digitalWrite(8,HIGH); // right backward

}
else if(c1<1300 && c1 >1100) //left turn
{
// digitalWrite(11,HIGH); // left backward
digitalWrite(7,HIGH); // right forward
}
else if(c1<1099 && c1  >999) //left turn
{
 //  digitalWrite(11,HIGH); // left backward
digitalWrite(7,HIGH); // right forward
}   
 
else
{
digitalWrite(7,LOW);
digitalWrite(8,LOW);  
digitalWrite(10,LOW);
digitalWrite(11,LOW); 
}
 
}

/*void aju_baju()
{
if(c1>1550 && c1<1650)
{
digitalWrite(10,HIGH);
}
else if(c1>1651 && c1<1850)
{
digitalWrite(10,HIGH);
}
else if(c1<1300 && c1 >1100)
{
  digitalWrite(11,HIGH);
}
else if(c1<1099 && c1  >999)
{
  digitalWrite(11,HIGH);
}
else
{

digitalWrite(10,LOW);
digitalWrite(11,LOW);
}  
}*/

void servopan()
{
c5= map(c5,1850,1025,180,0); 
  myservo.write(c5 );
}
