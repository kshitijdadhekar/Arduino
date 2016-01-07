
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600); // serial connection begins!!
  Serial.println("Connection Successful !");
}

void loop()
{
   if(Serial.available()>0)
   {
      int data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a': LEDON();break; // when a is pressed on the app on your smart phone
        case 'b': LEDOFF();break; // when b is pressed on the app on your smart phone
        default : break;
      }
   }
   delay(50);
}

void LEDON() // function when 'a' is pressed
{
  Serial.println("LED ON!");
  digitalWrite(13,HIGH); // onboard led on
}

void LEDOFF() // function when 'b' is presse
{
  Serial.println("LED OFF"); // onboard led off
  digitalWrite(13,LOW); 
}


