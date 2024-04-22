
#include <Arduino.h>
#include <SPI.h>
#include "SPI_23LCV512.h"

uint8_t LCV512::begin(uint8_t CS)
{
    SPI.begin();
    SS = CS;
    pinMode(SS, OUTPUT);
    set_mode(64); //set the default sequential mode

    // SPI.setClockDivider(2);

    return 1;
}

// 00 = Byte mode                   (0)
// 10 = Page mode                   (128)
// 01 = Sequential mode (default)   (64)
// 11 = Reserved                    (255)
void LCV512:: set_mode(uint8_t mode)
{
    digitalWrite(SS, 0);
    SPI.transfer(0x01);     //write mode instruction
    SPI.transfer(mode);     //select mode
    digitalWrite(SS, 1);

}

uint8_t LCV512::get_mode()
{
    digitalWrite(SS, 0);
    SPI.transfer(0x05);             //read mode instruction
    uint8_t mode = SPI.transfer(0); //get the mode
    digitalWrite(SS, 1);
    return mode;
}

bool LCV512::write_byte(uint16_t address, int8_t data)
{
    digitalWrite(SS, 0);
    SPI.transfer(0x02);      // write instruction
    SPI.transfer16(address); // address
    SPI.transfer(data);      // data out
    digitalWrite(SS, 1);

    return 1;
}

uint8_t LCV512::read_byte(uint16_t address)
{
    digitalWrite(SS, 0);
    SPI.transfer(0x03);             // read instruction
    SPI.transfer16(address);        // address
    uint8_t data = SPI.transfer(0); // data in
    digitalWrite(SS, 1);

    return data;
}


bool LCV512::write_sequential(uint16_t address, uint32_t *buffer)
{
    digitalWrite(SS, 0);
    SPI.transfer(0x02);      // read instruction
    SPI.transfer16(address); // address
    for(int i = 0; i < MAX_ADDRESS; i++)
    {
        SPI.transfer32(buffer[i]);      // data in
    }
    digitalWrite(SS, 1);

    return 1;
}

bool LCV512::read_sequential(uint16_t address, uint32_t *buffer)
{
    digitalWrite(SS, 0);
    SPI.transfer(0x03);      // read instruction
    SPI.transfer16(address); // address

    for(int i = 0; i < MAX_ADDRESS-1; i++)
    {
        buffer[i] = SPI.transfer32(0);      // data out
    }
    digitalWrite(SS, 1);
    
    return 1;
}
