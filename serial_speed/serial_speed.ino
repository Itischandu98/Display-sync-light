//screen pixels at points final code

#include <Adafruit_NeoPixel.h>
#define PIN  6 
//#define 23 5

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 300 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 5000 // Time (in milliseconds) to pause between pixels

void setup() {
  Serial.begin(115200);
  pixels.begin();
}
String str;
String  red,green,blue;
String r[23],g[23],b[23],c[3];
int StringCount = 0, sscount0 = 0, sscount1 = 0, sscount2 = 0;

void loop() {
if (Serial.available() > 0){
  str=Serial.readString();
//  str.trim();
  Serial.println(str);
    while (str.length() > 0)
  {
    int index = str.indexOf(',');
    if (index == -1) // No space found
    {
      c[StringCount++] = str;
      break;
    }
    else
    {
      c[StringCount++] = str.substring(0, index);
      str = str.substring(index+1);
    }
  }
red=c[0];
  while (red.length() > 0)
  {
    int index0 = red.indexOf(' ');
    if (index0 == -1) // No space found
    {
      r[sscount0++] = red;
      break;
    }
    else
    {
      r[sscount0++] = red.substring(0, index0);
      red = red.substring(index0+1);
    }
  }
green=c[1];
  while (green.length() > 0)
  {
    int index1 = green.indexOf(' ');
    if (index1 == -1) // No space found
    {
      g[sscount1++] = green;
      break;
    }
    else
    {
      g[sscount1++] = green.substring(0, index1);
      green = green.substring(index1+1);
    }
  }
blue=c[2];
while (blue.length() > 0)
  {
    int index2 = blue.indexOf(' ');
    if (index2 == -1) // No space found
    {
      b[sscount2++] = blue;
      break;
    }
    else
    {
      b[sscount2++] = blue.substring(0, index2);
      blue = blue.substring(index2+1);
    }
  }
 }
          pixels.clear();
          int testing=0;
         for (int j = 0; j < 23; j++){           
          for(int i=0; i<NUMPIXELS/6; i++) { // For each pixel...
            pixels.setPixelColor(i+testing, pixels.Color(r[j].toInt(), g[j].toInt(), b[j].toInt()));
             // Pause before next pass through loop
            }
            testing=testing+60;
          }
          pixels.show();
          delay(DELAYVAL);
          
  }
