#pragma once

#include <stdint.h>

namespace hal {
    void initSPI0();
    void initSPI1();
    uint8_t communicate8bitSPI0(uint8_t transmit);
    uint8_t communicate8bitSPI1(uint8_t transmit);

    void communicateNbyteSPI0(uint8_t* send, uint8_t* recv, uint8_t num);
    void communicateNbyteSPI1(uint8_t* send, uint8_t* recv, uint8_t num);

    void setEnableSPI0(uint8_t en);
    void setEnableSPI1(uint8_t en);

    void useCS0SPI0();
    void useCS1SPI0();


}