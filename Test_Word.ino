// Test Code! just plug in the arduino and cable and hit upload. when you turn it all on, "test" should show up on the fan

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_DotStarMatrix.h>
#include <Adafruit_DotStar.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif
int State = 0;
int lastState = 0;
#define DATAPIN  13 //set datapin to pin 13 on the Arduino nano
#define CLOCKPIN 11 //set Clockpin to pin 11 on the Arduino nano

// MATRIX DECLARATION:
// Parameter 1 = width of DotStar matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   DS_MATRIX_TOP, DS_MATRIX_BOTTOM, DS_MATRIX_LEFT, DS_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     DS_MATRIX_TOP + DS_MATRIX_LEFT for the top-left corner.
//   DS_MATRIX_ROWS, DS_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   DS_MATRIX_PROGRESSIVE, DS_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type:
//   DOTSTAR_BRG  Pixels are wired for BRG bitstream (most DotStar items)
//   DOTSTAR_GBR  Pixels are wired for GBR bitstream (some older DotStars)

Adafruit_DotStarMatrix matrix = Adafruit_DotStarMatrix(
  1, 10, DATAPIN, CLOCKPIN,
  DS_MATRIX_BOTTOM     + DS_MATRIX_LEFT +
  DS_MATRIX_COLUMNS + DS_MATRIX_PROGRESSIVE,
  DOTSTAR_BRG);
//Adafruit_DotStarMatrix matrix = Adafruit_DotStarMatrix(
//  8, 8,
//  DS_MATRIX_TOP     + DS_MATRIX_RIGHT +
//  DS_MATRIX_COLUMNS + DS_MATRIX_PROGRESSIVE,
//  DOTSTAR_BRG);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) }; // different color options for the text on the fan

void setup() {
   pinMode(2, INPUT); // set the D2 pin on the arduino to recieve input
  matrix.begin(); // initializes LEDS
  matrix.setTextWrap(false); //removes text wrapping
  matrix.setBrightness(255); //sets  brightness to max
  matrix.setTextColor(colors[0]); //sets text color as 0
}

int x    = matrix.width(); // sets the width of the matrix equal to the number of DotStar LEDs
int pass = 0; // sets pass equal to 0

void loop() {
//Where your code goes!
matrix.fillScreen(0); //clears matrix
matrix.setCursor(x, 1); // sets starting point at The second led, 1
matrix.print(F("Test"));  // word in quotations is what will be written. best to keep under 5 letters long
if(--x < -30) {
x = matrix.width();  // sets the color to shuffle or not to shuffle
if(++pass >= 1) pass = 0;
matrix.setTextColor(colors[pass]);
  matrix.show(); // updates DotStar pixels
  
}
State = digitalRead(2); //sets State as the value inputed in the D2 line.
  if (State != LOW){ 
    if (State == HIGH){  // makes the word rewrite and wipes the LEDs everytime the Hall Effect sensor passes the magnet
matrix.begin(); // restarts LEDs
matrix.show(); // Starts LEDs
  }
}
  }
