#include <LedControl.h>

LedControl lc = LedControl(12,11,10,2);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames

// Put values in arrays
byte invader1a[] =
{
  B11111111, // First frame of invader #2
  B11000011,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
};

byte invader2a[] =
{
  B11111111, // First frame of invader #2
  B10000001,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
};

void setup()
{
lc.shutdown(0,false);  // Wake up displays
lc.shutdown(1,false);
lc.setIntensity(0,5);  // Set intensity levels
lc.setIntensity(1,5);
lc.clearDisplay(0);  // Clear Displays
lc.clearDisplay(1);
}


//  Take values in Arrays and Display them
void sinvader1a()
{
  for (int i = 0; i < 8; i++)  
  {
lc.setRow(0,i,invader1a[i]);
  }
}


void sinvader2a()
{
  for (int i = 0; i < 8; i++)
  {
lc.setRow(1,i,invader2a[i]);
  }
}

void loop()
{
// Put #1 frame on both Display
    sinvader1a();
    delay(delayTime);
    sinvader2a();
    delay(delayTime);

}
