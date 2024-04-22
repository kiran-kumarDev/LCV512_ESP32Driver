#include <Arduino.h>
#include <SPI.h>
#include "SPI_23LCV512.h"

//pin connections
#define DATAIN 23     //SO
#define CLK 18
#define CS 5
#define DATAOUT 19    //SI

void print_data(uint32_t *buffer);

LCV512 SRAM;
void setup() 
{
  Serial.begin(115200);
  SRAM.begin(CS);

  delay(3000);
} 


void loop() 
{
  Serial.println(SRAM.get_mode());
  uint32_t *buffer = (uint32_t*)malloc(MAX_ADDRESS * sizeof(uint32_t));
  

  free(buffer);
  
  Serial.println("Reached to END\n");
  while(1);
}








void print_data(uint32_t *buffer)
{
  for (int i = 0; i < MAX_ADDRESS; i++)
  {
    Serial.print(buffer[i]);
    Serial.print(" ");
  }
  Serial.println(" Actual buffer");

  SRAM.write_sequential(0x00, buffer);
  for (int i = 0; i < MAX_ADDRESS; i++)
  {
    buffer[i] = 0;
    Serial.print(buffer[i]);
    Serial.print(" ");
  }
  Serial.println(" After");
  SRAM.read_sequential(0x00, buffer);

  for (int i = 0; i < MAX_ADDRESS; i++)
  {
    Serial.print(buffer[i]);
    Serial.print(" ");
  }
  Serial.println("Done\n");
}