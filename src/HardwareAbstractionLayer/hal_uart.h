#pragma once

#include <stdint.h>

namespace hal {
    void initUart0();
    void put1byteUart0(uint8_t c);
    void putnbyteUart0(const uint8_t* buf, uint16_t len);
    void recieveDataUart0();
    void sendDataUart0(); //この関数はタイマ割り込み関数内で周期的に呼び出すこと


    void initUart1();
    void put1byteUart1(uint8_t c);
    void putnbyteUart1(const uint8_t* buf, uint16_t len);
    void recieveDataUart1();
    void sendDataUart1(); //この関数はタイマ割り込み関数内で周期的に呼び出すこと

}



