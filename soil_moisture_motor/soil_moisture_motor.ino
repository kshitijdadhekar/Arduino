

int sensorPin = A0;    // select the input pin for the potentiometer
int pumppin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
 
  Serial.begin(9600);
  pinMode(pumppin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  
  
  if(sensorValue<300)
  {
    digitalWrite(pumppin, HIGH);
  }
  else
  {
    digitalWrite(pumppin, LOW);
  }

  
}
