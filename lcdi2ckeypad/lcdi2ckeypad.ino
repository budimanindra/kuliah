//Hello, This is the code to use a 4x4 keypad matrix with and Arduino and show the result on an LCD screen
//You should wire you keypad from 8to1 (keypad pins) to 9to2 Arduino digital pins
//SurtrTech

#include <Keypad.h> //The keypad and LCD i2c libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27 //defining the LCD pins
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '4', '7', '*'},
{'2', '5', '8', '0'},
{'3', '6', '9', '#'},
{'A', 'B', 'C', 'D'}
};

byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3 //if you modify your pins you should modify this too
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3
//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
void setup()
           {
            Serial.begin(9600);
            lcd.begin (16,2);
            lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
            lcd.setBacklight(HIGH);
            lcd.home ();
            lcd.print("Press a key");
            delay(2000);
           }

void loop()
{
         char keypressed = myKeypad.getKey();
         if (keypressed != NO_KEY)
             {
              lcd.clear();
              lcd.print(keypressed);
//            Serial.println(keypressed); Uncomment this to show it on the serial monitor too
              }
}
