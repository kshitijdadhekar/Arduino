#include <IRremote.h>

int RECV_PIN = 11;
int ledpin = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(ledpin,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    digitalWrite(ledpin,HIGH);
    delay(5000);
    digitalWrite(ledpin,LOW);
    irrecv.resume(); // Receive the next value
  }
}
