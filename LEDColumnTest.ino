/******************************************************************************\
| LEDCOLUMNTEST.INO                                                            |
|                                                                              |
| This project file tests each individual LED column's red, green, and blue    |
| light.                                                                       |
|                                                                              |
| Written by Steven Cheng                                                      |
| Date: October 25th 2019                                                      |
\******************************************************************************/

/* Initializes red, green, blue, and anode pin numbers. */
int redPin = 0;
int greenPin = 0;
int bluePin = 0;
int ANODE = 0;
#define COMMON_ANODE

/* Sets up inputs and outputs on Arduino microcontroller. */
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
  pinMode(ANODE, OUTPUT);
  digitalWrite(ANODE, HIGH); 
}

/* Tests bottom LED */
void testCase1(){ redPin = 8; greenPin = 9; bluePin = 6; ANODE = 7; }

/* Tests second LED from bottom up */
void testCase2(){ redPin = 7; greenPin = 8; bluePin = 9; ANODE = 6; }

/* Tests second LED from top up */
void testCase3(){ redPin = 6; greenPin = 7; bluePin = 8; ANODE = 9; }

/* Tests top LED */
void testCase4(){ redPin = 9; greenPin = 6; bluePin = 7; ANODE = 8; }

/* Function that sets the color of the LED */
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

/* Function iterates through the pattern of red, green, then blue light of LED */
void colorCheck(){
  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(0, 0, 0); // turn off
  delay(1000);
}

/* Continuous loop for light test */
void loop() {
  testCase1(); colorCheck();
  testCase2(); colorCheck();
  testCase3(); colorCheck();
  testCase4(); colorCheck(); 
}
