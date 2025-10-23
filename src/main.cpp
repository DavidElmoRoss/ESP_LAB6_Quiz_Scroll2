/*
 Title:       This program scrolls a message on the 4 digit display
Description: This program uses the setSegments() function to scroll
             text characters across the 4 digit display.
             The hex values for these characters are in a char array.
             You must add 3 HEX values to complete the message:
                   dEtEctEd  where tEd are missing.
            
*/

//INCLUDE SECTION
#include <Arduino.h>
#include <TM1637Display.h>

//DEFINE SECTION
#define CLK  33                // The ESP32 pin GPIO33 connected to CLK
#define DIO  32                // The ESP32 pin GPIO32 connected to DIO
#define Colon_On 0x40          // mask value to turn ON Colon on display
#define Colon_Off 0x00         // mask value to turn OFF Colon on display

//HARDWARE DEFINITION SECTION
TM1637Display segment = TM1637Display(CLK, DIO);

// Global Variables
uint8_t i;          // index_value defined as having 8 bit data values

unsigned char SEG_DONE[] =    // This has the scrolling message
{
 0x00,0x00,0x00,0x00,          
 0x5e,0x79,0x78,0x79,0x58,    
                            // add HEX values for   tEd
 0x00,0x00,0x00,0x00          // 4 trailing blanks
};

void setup()
{
 segment.setBrightness(4);    // set the brightness to 4 in range (0:dimmest, 7:brightest)
 segment.clear();             // clear the 4 digit display
}

void loop() 
{
  for(i=0;i<9;++i)             // modify loop for 3 more values
  {
     segment.setSegments(SEG_DONE+i);  
     delay(500);                         // we are scrolling the message every 0.5 seconds
   }
  
}
