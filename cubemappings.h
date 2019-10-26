/******************************************************************************\
| MAPPINGS.H                                                                   |
|                                                                              |
| Creates the mappings and positions for the LED cube.                         | 
|                                                                              |
| Written by Steven Cheng, with references to Asher Glick's Charliecube.       |
| Date: October 25th 2019                                                      |
\******************************************************************************/

#ifndef _CUBEMAPPINGS_H_
#define _CUBEMAPPINGS_H_

/*------------------------------ PIN PORT MAPPINGS --------------------------*/
/*
 *   This header maps all 16 LED columns to individual ports in the Arduino
 *   microcontroller.
 *   The reason why each "P" has 3 components is because they dictate the blue,
 *   green, and red components of the LED.
 */
/*---------------------------------------------------------------------------*/
#define P1B 0x00
#define P1C 0x00
#define P1D 0x04

#define P2B 0x00
#define P2C 0x00
#define P2D 0x08

#define P3B 0x00
#define P3C 0x00
#define P3D 0x10

#define P4B 0x00
#define P4C 0x00
#define P4D 0x20

#define P5B 0x00
#define P5C 0x00
#define P5D 0x40

#define P6B 0x00
#define P6C 0x00
#define P6D 0x80

#define P7B 0x01
#define P7C 0x00
#define P7D 0x00

#define P8B 0x02
#define P8C 0x00
#define P8D 0x00

#define P9B 0x04
#define P9C 0x00
#define P9D 0x00

#define P10B 0x08
#define P10C 0x00
#define P10D 0x00

#define P11B 0x10
#define P11C 0x00
#define P11D 0x00

#define P12B 0x20
#define P12C 0x00
#define P12D 0x00

#define P13B 0x00
#define P13C 0x01
#define P13D 0x00

#define P14B 0x00
#define P14C 0x02
#define P14D 0x00

#define P15B 0x00
#define P15C 0x04
#define P15D 0x00

#define P16B 0x00
#define P16C 0x08
#define P16D 0x00

#endif
