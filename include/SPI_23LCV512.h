#ifndef SPI_23LCV512
#define SPI_23LCV512
#include <cstdint>
#define MAX_ADDRESS 16384
class LCV512
{
    private:
        uint8_t SS;
    
    public:
        uint8_t begin(uint8_t CS);
        void set_mode(uint8_t mode);
        uint8_t get_mode();

        bool write_byte(uint16_t address, int8_t data);
        uint8_t read_byte(uint16_t address);

        bool read_sequential(uint16_t address, uint32_t *buffer);
        bool write_sequential(uint16_t address, uint32_t *buffer);

        
};

#endif