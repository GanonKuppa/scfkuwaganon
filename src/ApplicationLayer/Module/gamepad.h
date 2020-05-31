#pragma once

#include <stdint.h>


#include "baseModule.h"

namespace module {

    class Gamepad : public BaseModule<Gamepad> {
      public:
        int8_t cross_x;
        int8_t cross_y;
        int8_t L3D_x;
        int8_t L3D_y;
        int8_t R3D_x;
        int8_t R3D_y;
        uint8_t RT;
        uint8_t LT;
        uint32_t A;
        uint32_t B;
        uint32_t Y;
        uint32_t X;
        uint32_t RB;
        uint32_t LB;
        uint32_t BACK;
        uint32_t START;


        bool isConnecting();
        void fetchCommand(uint8_t* command);
        void update(); // 1msec毎に呼ぶこと
        void debug();
        void debug_xinput();

      private:
        bool conStatus;
        uint64_t preRecieveTime;
        uint8_t receiveCommand[16];
        Gamepad();
        friend class BaseModule<Gamepad>;
    };

}

