 void setup()
 { 
 Serial.begin(9600); 
 }
void loop(){
    float currentValue(analogRead(A0));
    float amps = ((.0049 * currentValue) - 2.5)/.066;
    
    Serial.print("  Raw Value = ");
    Serial.print(currentValue);
    Serial.print("  Amps = ");
    Serial.print(amps);
    Serial.println(" mA");
    delay(400);
}
