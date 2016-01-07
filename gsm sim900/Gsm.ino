//Connections for the following code
// gsm module needs external power supply; powering the GSM module with your arduino board is not recommended
// RX of GSM -> TX of Arduino
// TX of GSM -> RX of Arduino
// Gnd of GSm -> Gnd of Arduino

char phone_no[]="10 digit number";
void setup()
{
Serial.begin(9600);  //Open Serial Connection at baudrate 9600
delay(2000);
Serial.println("AT"); // Wake up GSM
delay(3000); // this delay is very important as GSM modules take time to wake
Serial.print("ATD"); //Dial the phone number using ATD command
Serial.print(phone_no);
Serial.println(";"); // Semicolon is a must at the end
delay(10000);
// you can use this -> Serial.println(“ATH”); to hang the call
}
void loop()
{
// empty loop.If you enter the above code here,the call will be made FOR EVER repeatedly.
//Take Caution while coding under loop.At some condition you’ve to terminate the Call
}
