#include <Keypad.h>
long num;
char phone_no[]="8976169385";
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','-'},
  {'C','0','~','D'}
};
byte rowPins[ROWS] = {
   2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {
  6, 7, 8, 9}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int count=0;
void setup() {
Serial.begin(9600); // put your setup code here, to run once:
Serial.println("AT"); // Wake up GSM
delay(2000);
Serial.println("AT+CLIP=1\r");
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY)
  {

    Serial.println(key);
    count++;
    if (count==17)
    {
      count=0;
    }
  }
  if (key=='A')
  {
    Serial.println("ATA");
  
  }
}
