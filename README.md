# 4x4x4-RGB-LED-Cube

Background
	Creating the cube requires 64 LEDs, as each edge consists of 4 LEDs. The LEDs assembled in this cube are RGB LEDs, which can display a spectrum of colors utilizing different shades of red, green, and blue. Each RGB LED consist of 4 separate color pins: red, green, blue, and the anode, which is connected to the voltage supply to light up the LED. 
	To allow these LEDs to light up at different times, a concept called Charlieplexing is utilized. Charlieplexing is a technique for driving multiplexed display in which relatively few pins on a microcontroller (in our case an Arduino Uno) are used. In our case, Charlieplexing enables us to control 64 LEDs with only 16 inputs, and the details of this capability will be explored further in the document.
	This cube is a variant of the a 4x4x4 tri-color LED Cube designed and created by Asher Glick and Kevin Baker, who were one of the first ones to create LED cubes. The instructions for their cube can be found at: https://aglick.com/charliecube.html

Building a Charlieplexed 64 RGB LED cube can be broken down into several groups:/n
1. Assembling an LED column /n
2. Assembling the cube /n
3. Creation of the box (3D modeling) /n
4. Programming
