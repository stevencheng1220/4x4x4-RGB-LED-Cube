/******************************************************************************\
| CUBEPROJECT.INO                                                              |
|                                                                              |
| The main project file for the 4x4x4 RGB LED Cube. This project file contains |
| the light patterns, with smaller helper functions such as lighting up one    |
| LED and lighting up a row of LEDs.                                            |
|                                                                              |
| Written by Steven Cheng                                                      |
| Date: October 25th 2019                                                      |
\******************************************************************************/

#include "cubehelper.h"

/* Defining int values for each primary and secondary color  */
#define red 0
#define green 1
#define blue 2
#define yellow 3
#define teal 4
#define purple 5
#define off -7

/* Initialize starting color */
int color = red;
/* Initialize animation time, how many milliseconds until one animation ends and goes onto next one. */
int animationMaxTime = 5000;

void setup() {
  /* Initializes the allocation the memory required for the LED cube buffers. Written by Asher Glick. */
  initCube(); 
}

void loop() {
  /* Program will continuously loop through these four light patterns. */
  boxFade();
  movingDots();
  fallingRows();
  tunnelWarp();
}


/*---------------------------------------------------------------------------*\
|*---------------------------------- PATTERNS -------------------------------*|
\*---------------------------------------------------------------------------*/


/*----------------------------------- BOX FADE ------------------------------*/
/*
 *   This animation fades through all 255 values (colors) of the LEDs, creating
 * different mixtures of each color.
 *   This pattern utilizes a drawBox function, which essentially lights up the whole
 * cube (all 64 LEDs) and syncs them together so that they all emit the same color.
 *   The first for loop slowly lights up the cube, while the second for loop slowly allows
 * the LEDs to fade out. The process repeats.
 */
/*---------------------------------------------------------------------------*/
void boxFade() {
  continuePattern = true;
  int animationSpeed = 30;
  unsigned long startTime = millis();
  while (continuePattern) {
    int color = random(0,6);
    for (int i = 1; i <= 15; i++)  {
      drawBox(color,i,0,0,0,3,3,3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    delay(animationSpeed*20);   
    for (int i = 1; i <= 15; i++) {
      drawBox(color,15-i,0,0,0,3,3,3);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    Serial.println(startTime);
    if (millis()-startTime > animationMaxTime){
      break;
    }
  }
}


/*--------------------------------- MOVING DOTS -----------------------------*/
/*
 *   This animation creates random points of light that move around the cube in
 * random fashion and constantly changes color.
 *   This pattern utilizes the drawLed function, which lights up a single LED at
 * the specified position. 
 *   Similar to the boxFade, the movingDots uses a fade-in, fade-out technique to
 * create transitions.
 */
/*--------------------------------- ---------- -----------------------------*/
void movingDots() {
  continuePattern = true;
  int animationSpeed = 20;
  unsigned long startTime = millis();
  while (continuePattern) {
    int pos = random(0,3);
    int color = random(0,6);
    for (int i = 1; i <= 15; i++)  {
      drawLed(color, i, pos, pos, pos);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    delay(animationSpeed*10);   
    for (int i = 1; i <= 15; i++) {
      drawLed(color, 15-i, pos, pos, pos);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    if (millis()-startTime > animationMaxTime){
      break;
    }
  }
  
}


/*------------------------------- FALLING ROWS --------------------------------*/
/*
 *   This animation lights up each layer in descending order, similar to falling. 
 * Each iteration will change the color of the lights that light up.
 *   This pattern is achieved by creating helper functions called drawRow and diffusedRow.
 * drawRow simply lights up a whole layer of the cube, while diffusedRow fades in each row,
 * then fades out, creating a more fluid transition.
 */
/*--------------------------------- ---------- --------------------------------*/
void fallingRows(){
  continuePattern = true;
  int animationSpeed = 10;
  int brightness = 9;
  unsigned long startTime = millis();

  while (continuePattern){
    int color = random(0,3);
    int sequenceR[] = {0,1,2,3};
    int sequenceG[] = {1,2,3,0};
    int sequenceB[] = {2,3,0,1};

    if (color == red){
      for(int k = 0; k <= 3; k+=1){
          diffusedRow(color, sequenceR[k], animationSpeed);
        }
      }
    else if (color == green){
      for(int k = 0; k <= 3; k+=1){
          diffusedRow(color, sequenceG[k], animationSpeed);
        }
      }
    else if (color == blue){
      for(int k = 0; k <= 3; k+=1){
          diffusedRow(color, sequenceB[k], animationSpeed);
      }
    }
    if (millis()-startTime > animationMaxTime){
      break;
    }
  }
}

/*------------------------------- TUNNEL WARP ---------------------------------*/
/*
 *   This animation lights up the whole cube like the boxFade, but it changes the
 * color of specific LEDs in the cube to create a dynamic feeling, as if the lights
 * are travelling through a tunnel and constantly changing.
 *   This animation is achieved by calling repeatedly a helper function called 
 *   drawBoxWalls, which draws the vertical walls and all four sides of a defined box.
 */
/*-----------------------------------------------------------------------------*/
void tunnelWarp() {
  continuePattern = true;
  int animationSpeed = 100;
  unsigned long startTime = millis();
  
  int color1[]  = {red,red,red,red,blue,blue,blue,blue};
  int bright1[] = {2,4,6,8,2,4,6,8};
  int color2[]  = {blue,blue,blue,blue,red,red,red,red};
  int bright2[] = {8,6,4,2,8,6,4,2};
  
  int index[]   = {0,1,2,3,4,5,6,7};
  
  while (continuePattern) {
    drawBoxWalls(color1[index[0]],bright1[index[0]],1,1,0,2,2,0);
    drawBoxWalls(color2[index[0]],bright2[index[0]],1,1,0,2,2,0);
    drawBoxWalls(color1[index[1]],bright1[index[1]],1,1,1,2,2,1);
    drawBoxWalls(color2[index[1]],bright2[index[1]],1,1,1,2,2,1);
    drawBoxWalls(color1[index[2]],bright1[index[2]],1,1,2,2,2,2);
    drawBoxWalls(color2[index[2]],bright2[index[2]],1,1,2,2,2,2);
    drawBoxWalls(color1[index[3]],bright1[index[3]],1,1,3,2,2,3);
    drawBoxWalls(color2[index[3]],bright2[index[3]],1,1,3,2,2,3);
    
    drawBoxWalls(color1[index[4]],bright1[index[4]],0,0,3,3,3,3);
    drawBoxWalls(color2[index[4]],bright2[index[4]],0,0,3,3,3,3);
    drawBoxWalls(color1[index[5]],bright1[index[5]],0,0,2,3,3,2);
    drawBoxWalls(color2[index[5]],bright2[index[5]],0,0,2,3,3,2);
    drawBoxWalls(color1[index[6]],bright1[index[6]],0,0,1,3,3,1);
    drawBoxWalls(color2[index[6]],bright2[index[6]],0,0,1,3,3,1);
    drawBoxWalls(color1[index[7]],bright1[index[7]],0,0,0,3,3,0);
    drawBoxWalls(color2[index[7]],bright2[index[7]],0,0,0,3,3,0);
    
    flushBuffer();
    clearBuffer();
    for (int i = 0; i < 8; i++){
      index[i] = (index[i]+1)%8;
    }
    delay(animationSpeed); 
    if (millis()-startTime > animationMaxTime){
      break;
    }
  }
}

/*---------------------------------------------------------------------------*\
|*----------------------------- SPECIFIC ACTIONS ----------------------------*|
\*---------------------------------------------------------------------------*/

/*--------------------------------- DRAW LED -------------------------------*/
/*
 * This method turns on LEDs at a specific position of int x, y, and z.
 * The color ranges from 0 to 255, while the brightness ranges from 0 to 255.
 */
/*--------------------------------------------------------------------------*/
void drawLed(int color, int brightness, int x, int y, int z) {
  
  if ((color/3)==0) { // single color (red green blue)
    _cube_buffer[(((color)%3)*64)+(x*16)+(y*4)+z] += brightness;
    _cube_buffer[(((color+1)%3)*64)+(x*16)+(y*4)+z] += 0;
  }
  else if ((color/3)==1) { // double color (teal yellow purple)
    _cube_buffer[(((color)%3)*64)+(x*16)+(y*4)+z] += brightness;
    _cube_buffer[(((color+1)%3)*64)+(x*16)+(y*4)+z] += brightness;
  }
  else if (color == 6){ // all colors (white)
    _cube_buffer[((0)*64)+(x*16)+(y*4)+z] += brightness;
    _cube_buffer[((1)*64)+(x*16)+(y*4)+z] += brightness;
    _cube_buffer[((2)*64)+(x*16)+(y*4)+z] += brightness;
  }
  else if (color == -7) {
    _cube_buffer[((0)*64)+(x*16)+(y*4)+z] = 0;
    _cube_buffer[((1)*64)+(x*16)+(y*4)+z] = 0;
    _cube_buffer[((2)*64)+(x*16)+(y*4)+z] = 0;
  }
}
void drawLed(int color, int x, int y, int z) {
  drawLed(color,255,x,y,z);
}

/*--------------------------------- DRAW BOX -------------------------------*/
/*
 * This method draws a filled in box of the specified color on the cube.
 * Used for fullColorFade.
 */
/*--------------------------------------------------------------------------*/
void drawBox(int color, int brightness, int startx, int starty, int startz, int endx, int endy, int endz) {
  if (startx > endx) swapint(startx,endx);
  if (starty > endy) swapint(starty,endy);
  if (startz > endz) swapint(startz,endz);
  
  for (int i = startx; i <= endx; i++) {
    for (int j = starty; j <= endy; j++) {
      for (int k = startz; k <= endz; k++) {
        drawLed(color,brightness,i,j,k);
      }
    } 
  }
}
void drawBox(int color, int startx, int starty, int startz, int endx, int endy, int endz) {
  drawBox(color,8,startx,starty,startz,endx,endy,endz);
}

/*--------------------------------- DRAW ROW -------------------------------*/
/*
 * This method will fill in a specified layer of the cube.
 */
/*--------------------------------------------------------------------------*/
void drawRow(int color, int brightness, int z){
  for(int i = 0; i <= 3; i+=1){
    for(int j = 0; j <= 3; j+=1){
      drawLed(color, brightness, i, j, z);
    }
  }
}

void drawRow(int color, int z){
  drawRow(color, 8, z);
}

/*---------------------------- DRAW DIFFUSED ROW ---------------------------*/
/*
 * This method utilizes the drawRow method to create a more fluid transition.
 */
/*--------------------------------------------------------------------------*/
void diffusedRow(int color, int level, int animationSpeed){
  for (int i = 3; i <= 15; i++)  {
    drawRow(color, i, 3-level);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
  }
  delay(animationSpeed*10);   
  for (int i = 0; i <= 9; i++) {
    drawRow(color, 9-i, 3-level);
    if (i >= 6){
      drawRow(color, i-6, 2-level);
    }
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
  }
}

/*----------------------------- DRAW BOX WALLS -----------------------------*/
/*
 * This function will draw the vertical walls and all four sides of a defined box.
 */
/*--------------------------------- --------- ------------------------------*/
void drawBoxWalls(int color, int brightness, int startx, int starty, 
                  int startz, int endx, int endy, int endz) {
  if (startx > endx) swapint(startx,endx);
  if (starty > endy) swapint(starty,endy);
  if (startz > endz) swapint(startz,endz);
  
  for (int i = startz; i <= endz; i++) {
    // draw y walls
    for (int j = starty; j <= endy; j++) {
      drawLed(color,brightness,startx,j,i);
      drawLed(color,brightness,endx,j,i);
    }
    // draw x walls
    for (int j = startx; j <= endx; j++) {
      drawLed(color,brightness,j,starty,i);
      drawLed(color,brightness,j,endy,i);
    }
  }
}
void drawBoxWalls(int color, int startx, int starty, int startz, int endx, int endy, int endz) {
  drawBoxWalls(color,255,startx,starty,startz,endx,endy,endz);
}

/*------------------------------- LED CHECKER ------------------------------*/
/*
 * This method is simply a LED checker to see if all LEDs are functioning correctly.
 */
/*--------------------------------------------------------------------------*/
void LEDCheck(){
  continuePattern = true;
  int animationSpeed = 200;
  int color = red;
  int brightness = 9;
  while (continuePattern){
    for(int k = 0; k <= 3; k+=1){
      for(int i = 0; i <= 3; i+=1){
        for(int j = 0; j <= 3; j+=1){
          drawLed(color, brightness, i, j, k);
          flushBuffer();
          clearBuffer();
          delay(animationSpeed);
        }
      }
    }
  }
}
