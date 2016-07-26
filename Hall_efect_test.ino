#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define NUMPIXELS 10
#define DATAPIN    13
#define CLOCKPIN   11
int State = 0;
int lastState = 0;
Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_GBR);

void setup() {
  pinMode(2, INPUT);
  strip.setBrightness(255);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
}

void loop() {
Violet(); // sets base color to violet
  strip.show(); // updates pixels to show color
  State = digitalRead(2); // sets state equal to whatever the hall effect sensor reads
  if (State != LOW){ // if state does not equal high, and if state equals low, set the strip to show blue color. 
    if (State == HIGH){
    strip.show(); // updates pixel color
      Blue ();
      strip.show();
    
  }
}
}
void Delay () {  //sets function Delay to cause a 50 millisecond delay and also update the strip.
  delay(50);
  strip.show();
}
void Violet () { // sets each pixel to be violet
  strip.setPixelColor(0, 125, 0, 255);  strip.setPixelColor(1, 125, 0, 255);
  strip.setPixelColor(2, 125, 0, 255);  strip.setPixelColor(3, 125, 0, 255); 
  strip.setPixelColor(4, 125, 0, 255);  strip.setPixelColor(5, 125, 0, 255);
  strip.setPixelColor(6, 125, 0, 255);  strip.setPixelColor(7, 125, 0, 255);
  strip.setPixelColor(7, 125, 0, 255);  strip.setPixelColor(8, 125, 0, 255);
  strip.setPixelColor(9, 125, 0, 255); 
}

void Blue () { // sets each pixel to be blue
  strip.setPixelColor(0, 0, 255, 0);  strip.setPixelColor(1, 0, 255, 0);
  strip.setPixelColor(2, 0, 255, 0);  strip.setPixelColor(3, 0, 255, 0); 
  strip.setPixelColor(4, 0, 255, 0);  strip.setPixelColor(5, 0, 255, 0);
  strip.setPixelColor(6, 0, 255, 0);  strip.setPixelColor(7, 0, 255, 0);
  strip.setPixelColor(7, 0, 255, 0);  strip.setPixelColor(8, 0, 255, 0);
  strip.setPixelColor(9, 0, 255, 0); 
}
void RedU () {
  strip.setPixelColor(0, 255, 0, 0);  strip.setPixelColor(1, 0, 0, 0); //sets each pixel to be Red, then sets the last pixel to turn off
  Delay();
  strip.setPixelColor(1, 255, 0, 0);  strip.setPixelColor(0, 0, 0, 0);
  Delay();
  strip.setPixelColor(2, 255, 0, 0);  strip.setPixelColor(1, 0, 0, 0);
  Delay();
  strip.setPixelColor(3, 255, 0, 0);  strip.setPixelColor(2, 0, 0, 0);
  Delay();
  strip.setPixelColor(4, 255, 0, 0);  strip.setPixelColor(3, 0, 0, 0); 
  Delay();
  strip.setPixelColor(5, 255, 0, 0);  strip.setPixelColor(4, 0, 0, 0);
  Delay();
  strip.setPixelColor(6, 255, 0, 0);  strip.setPixelColor(5, 0, 0, 0);
  Delay();
  strip.setPixelColor(7, 255, 0, 0);  strip.setPixelColor(6, 0, 0, 0);
  Delay();
  strip.setPixelColor(8, 255, 0, 0);  strip.setPixelColor(7, 0, 0, 0);
  Delay();
  strip.setPixelColor(9, 255, 0, 0);  strip.setPixelColor(8, 0, 0, 0);
  Delay();
}


