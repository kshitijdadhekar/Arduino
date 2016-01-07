
#include <ShiftLCD.h>

/*
 ShiftLCD Library - Hello World

Demonstrates the use a 16x2 LCD display.  The ShiftLCD library works with
all LCD displays that are compatible with the Hitachi HD44780 driver.
There are many of them out there, and you can usually tell them by the
16-pin interface.

This sketch prints "Hello World!" to the LCD
and shows the number of seconds since reset.

 The circuit:

---Shift Register 74HC595---
* SR SER - Pin 14 to Arduino pin PD2
* SR RCK - Pin 12 to Arduino pin PD3
* SR SCK - Pin 11 to Arduino pin PD4
* SR GND - Pin  8 to Ground
* SR VCC - Pin 16 to +5v
* SR OE - Pin 13 to Ground
* SR SCLR - Pin 10 to +5v
-----Shift Reg to LCD--------
* SR QA - Pin 15 to D7 lcd pin 14
* SR QB - Pin 1  to D6 lvd pin 13
* SR QC - Pin 2  to D5 lcd pin 12
* SR QD - Pin 3  to D4 lcd pin 11
* SR QG - Pin 6  to LCD Enable (LCD 1602 Pin 6)
* SR QH - Pin 7  to LCD RS (LCD 1602 Pin 4)
-----LCD HD44780-------------
* Vss to Ground    (LCD 1602 Pin 1)
* Vdd to +5V       (LCD 1602 Pin 2)
* Vo  to 10k Wiper (LCD 1602 Pin 3)
* R/W to Ground    (LCD 1602 Pin 5)
* LEDA  to +5v     (LCD 1602 Pin 15)
* Gnd to LEDK via 330 Ohm resistor  (LCD 1602 Pin 16)

The schematic at this link is correct except that, in this implementation,
The MOSFET circuit is replaced by a 330 ohm resistor (see above).
http://cjparish.blogspot.com/2010/01/controlling-lcd-display-with-shift.html

Library modified from the original LiquidCrystal Library
This example originaly by Tom Igoe, Jul 2009
Example modified for use with ShiftLCD
Chris Parish, January 12th 2010
*/

#define  DATAPIN  2
#define  CLOCKPIN 4
#define  LATCHPIN 3
#define  MAXCOLUMNS  16
#define  MAXLINES  2
#define  FOURBIT  4


ShiftLCD lcd(DATAPIN, CLOCKPIN, LATCHPIN, FOURBIT);

void setup() {
 // set up the LCD's number of rows and columns: 
 lcd.begin(MAXCOLUMNS, MAXLINES);
 // Print a message to the LCD.
 lcd.print("Hello, World!");
}

void loop() {
 // set the cursor to column 0, line 1
 // (note: line 1 is the second row, since counting begins with 0):
 lcd.setCursor(0, 1);  //lcd.setCursor(column, row);
 // print the number of seconds since reset:
 lcd.print(millis()/1000);
}
