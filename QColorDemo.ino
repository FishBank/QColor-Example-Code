/* QColor-Demo

Fades red, green, and blue colors to create a wide range of other colors.

modified by Quin (Qtechknow)
original code by James Harton (https://gist.github.com/jamesotron)
*/

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int value = 1;
 
void setup() {
  // Start off with the LED off.
  setColorRgb(0,0,0);
}
 
void loop() {
  unsigned int rgbColor[3];
 
  // Start off with red.
  rgbColor[0] = 255;
  rgbColor[1] = 0;
  rgbColor[2] = 0;  
 
  // Choose the colors to increment and decrement.
  for (int decColor = 0; decColor < 3; decColor += 1) {
    int incColor = decColor == 2 ? 0 : decColor + 1;
 
    // cross-fade the two colors.
    for(int i = 0; i < 255; i += 1) {
      rgbColor[decColor] -= 1;
      rgbColor[incColor] += 1;
      
      setColorRgb(rgbColor[0], rgbColor[1], rgbColor[2]);  // set the colors
      delay(10);
        }
    }
}
 
void setColorRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);            // tell the pins to fade
  analogWrite(greenPin, green);        // so that they make new colors!
  analogWrite(bluePin, blue);
 }
