float sample=0.00; int count=0;
void setup() {
 pinMode(2,OUTPUT);
 Serial.begin(9600);
 digitalWrite(2,HIGH);

}

void loop() {
 for(int i=0;i<150;i++)
{
sample += analogRead(A0); //read the current from sensor
delay(2);
}
sample=sample/150;
float val =(5.0*sample)/1024.0;
float actualval =val-2.5; // offset voltage is 2.5v
float amps =actualval*10;
delay(1000);
count++;
if(count>3 && sample<523)
{
  pinMode(2,LOW);
}
Serial.print("Avalue=");
Serial.print(sample);
Serial.print("\t");
Serial.print("Amps=");
Serial.println(amps);
}
