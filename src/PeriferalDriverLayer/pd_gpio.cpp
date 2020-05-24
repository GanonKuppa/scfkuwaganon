#include <stdint.h>
#include "iodefine.h"
#include "pd_gpio.h"

namespace periferal_driver {
    void initGpio() {
        //未使用ピンの処理
        PORT0.PDR.BYTE = (uint8_t) (PORT0.PDR.BYTE | 0x0F);
        PORT1.PDR.BYTE = (uint8_t) (PORT1.PDR.BYTE | 0x03);
        PORT5.PDR.BYTE = (uint8_t) (PORT5.PDR.BYTE | 0x40);
        PORT6.PDR.BYTE = (uint8_t) (PORT6.PDR.BYTE | 0xFF);
        PORT7.PDR.BYTE = (uint8_t) (PORT7.PDR.BYTE | 0xFF);
        PORT8.PDR.BYTE = (uint8_t) (PORT8.PDR.BYTE | 0xCF);
        PORT9.PDR.BYTE = (uint8_t) (PORT9.PDR.BYTE | 0xFF);
        PORTF.PDR.BYTE = (uint8_t) (PORTF.PDR.BYTE | 0x3F);
        PORTG.PDR.BYTE = (uint8_t) (PORTG.PDR.BYTE | 0xFF);
        PORTJ.PDR.BYTE = (uint8_t) (PORTJ.PDR.BYTE | 0x20);

        //FCLEDピン設定
        PORTD.PDR.BIT.B4 = 1; //B
        PORTD.PDR.BIT.B3 = 1; //G
        PORTD.PDR.BIT.B2 = 1; //R

        //センサLED
        PORTE.PDR.BIT.B0 = 1; //SLED_OUT1
        PORTD.PDR.BIT.B7 = 1; //SLED_OUT2
        PORTD.PDR.BIT.B0 = 1; //SLED_OUT3
        PORT0.PDR.BIT.B7 = 1; //SLED_OUT4
    }

    void setDoutPD4(bool out) {
        PORTD.PODR.BIT.B4 = out;
    }

    void setDoutPD3(bool out) {
        PORTD.PODR.BIT.B3 = out;
    }

    void setDoutPD2(bool out) {
        PORTD.PODR.BIT.B2 = out;
    }

    void setDoutPE0(bool out) {
        PORTE.PODR.BIT.B0 = out;
    }

    void setDoutPD7(bool out) {
        PORTD.PODR.BIT.B7 = out;
    }

    void setDoutPD0(bool out) {
        PORTD.PODR.BIT.B0 = out;
    }

    void setDoutP07(bool out) {
        PORT0.PODR.BIT.B7 = out;
    }

}
