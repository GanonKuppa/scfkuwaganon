#pragma once

#include <stdint.h>

//#include <deque>
#include <queue>

namespace periferal_driver {

    void initSCI1();
    void put1byteSCI1(char c);
    void putnbyteSCI1(const char* buf, int len);

    void initSCIFA9();
    void putnbyteSCIFA9(const uint8_t* buf, uint16_t len);
    void recieveDataSCIFA9();
    void sendDataSCIFA9();

    extern uint8_t recieveBuff[512];
    extern uint16_t recieveBuffCount;

//下dequeを受信バッファにしてみたがうまく動かなかった。
//extern deque<uint8_t> recieveBuff;//受信用データバッファ

}
