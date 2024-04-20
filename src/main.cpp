#include <Arduino.h>
#include <SPI.h>
#include "SPI_23LCV512.h"

//pin connections
//SO
#define DATAIN 23
#define CLK 18
#define CS 5
//SI
#define DATAOUT 19

LCV512 SRAM;

void setup() 
{
  //spi.setClockDivider(divider)
  Serial.begin(115200);
  SRAM.begin(CS);

  delay(3000);
} 

void loop() 
{
  Serial.println(SRAM.get_mode());
  uint32_t buffer[MAX_ADDRESS];
  SRAM.write_sequential(0x00, buffer);

  // for(int i = 0 ;i<5;i++)
  // {
  //   Serial.print(buffer[i]); Serial.print(" ");
  // }
  // Serial.println(" Actual buffer");
  
  // SRAM.write_sequential(0x00, buffer);
  // for(int i = 0 ;i<5;i++)
  // { 
  //   buffer[i] = 0;
  //   Serial.print(buffer[i]); Serial.print(" ");
  // }
  // Serial.println(" After");
  // SRAM.read_sequential(0x00, buffer);

  // for(int i = 0 ;i<5;i++)
  // {
  //   Serial.print(buffer[i]); Serial.print(" ");
  // }

   Serial.println("Done\n");
  
  while(1);
}