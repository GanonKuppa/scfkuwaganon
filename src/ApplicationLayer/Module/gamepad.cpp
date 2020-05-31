#include <stdio.h>
#include <XInput.h>
#include <windows.h>

#include "hal_timer.h"

#include "gamepad.h"

namespace module {


    Gamepad::Gamepad():
        cross_x(0),
        cross_y(0),
        L3D_x(0),
        R3D_x(0),
        R3D_y(0),
        RT(0),
        LT(0),
        A (0),
        B (0),
        Y (0),
        X (0),
        RB(0),
        LB(0),
        BACK(0),
        START(0),
        conStatus(false),
        preRecieveTime(0)
    {}



    bool Gamepad::isConnecting() {
#ifndef SILS
        if(hal::getElapsedMsec() - preRecieveTime < 200) {
            return true;
        } else {
            return false;
        }
#else
        static XINPUT_CAPABILITIES dummy;
        if(XInputGetCapabilities(0,0, &dummy) == 0) {
            return true;
        } else {
            return false;
        }
#endif

    }







    void Gamepad::fetchCommand(uint8_t* command) {
        if(command[3] == 254 && command[4] == 253) {
            preRecieveTime = hal::getElapsedMsec();
            for(uint8_t i=0; i<16; i++) {
                receiveCommand[i] = command[i];
            }
        }
    };

    //1msec毎に呼ぶこと
    void Gamepad::update() {
#ifndef SILS
        uint8_t* command = receiveCommand;
        if((command[6] & 0x01) == 1) A++;
        else A = 0;
        if(((command[6] & 0x02) >> 1) == 1) B++;
        else B = 0;
        if(((command[6] & 0x04) >> 2) == 1) X++;
        else X= 0;
        if(((command[6] & 0x08) >> 3) == 1) Y++;
        else Y = 0;
        if(((command[6] & 0x10) >> 4) == 1) RB++;
        else RB = 0;
        if(((command[6] & 0x20) >> 5) == 1) LB++;
        else LB = 0;
        if(((command[6] & 0x40) >> 6) == 1) BACK++;
        else BACK = 0;
        if(((command[6] & 0x80) >> 7) == 1) START++;
        else START = 0;
        RT = command[7];
        LT = command[8];
        cross_x = command[9]  - 128;
        cross_y = command[10] - 128;
        R3D_x = command[11] - 128;
        R3D_y = command[12] - 128;
        L3D_x = command[13] - 128;
        L3D_y = command[14] - 128;
#else
        preRecieveTime = hal::getElapsedMsec();
        XINPUT_STATE state;
        XInputGetState(0, &state);
        uint16_t wButtons = state.Gamepad.wButtons;
        if((wButtons & 0x1000) == 0x1000) A++;
        else A = 0;
        if((wButtons & 0x2000) == 0x2000) B++;
        else B = 0;
        if((wButtons & 0x4000) == 0x4000) X++;
        else X= 0;
        if((wButtons & 0x8000) == 0x8000) Y++;
        else Y = 0;
        if((wButtons & 0x0200) == 0x0200) RB++;
        else RB = 0;
        if((wButtons & 0x0100) == 0x0100) LB++;
        else LB = 0;
        if((wButtons & 0x0020) == 0x0020) BACK++;
        else BACK = 0;
        if((wButtons & 0x0010) == 0x0010) START++;
        else START = 0;

        RT = state.Gamepad.bRightTrigger;
        LT = state.Gamepad.bLeftTrigger;

        if((wButtons & 0x0004) == 0x0004) cross_x = 1;
        else if((wButtons & 0x0008) == 0x0008) cross_x = -1;
        else cross_x = 0;

        if((wButtons & 0x0001) == 0x0001) cross_y = 1;
        else if((wButtons & 0x0002) == 0x0002) cross_y = -1;
        else cross_y = 0;

        R3D_x = state.Gamepad.sThumbRX / 256;
        R3D_y = state.Gamepad.sThumbRY / 256;
        L3D_x = state.Gamepad.sThumbLX / 256;
        L3D_y = state.Gamepad.sThumbLY / 256;

#endif
        if(!isConnecting()) {
            A = 0;
            B = 0;
            X = 0;
            Y = 0;
            RB = 0;
            LB = 0;
            BACK = 0;
            START = 0;
            RT = 0;
            LT = 0;
            cross_x = 0;
            cross_y = 0;
            R3D_x = 0;
            R3D_y = 0;
            L3D_x = 0;
            L3D_y = 0;
        }
    };


    void Gamepad::debug() {
#ifndef SILS
        //printfAsync("A:%d, B:%d, X:%d, Y:%d, RT:%d, LT:%d  \n", A,B,X,Y,RT,LT);
#else
        printf("==================\n");
        printf("A:%d, B:%d, X:%d, Y:%d, RB:%d, LB:%d  \n", A,B,X,Y,RB,LB);
        printf("cross_x:%d, cross_y:%d \n", cross_x, cross_y);
        printf("R3D_x:%d, R3D_y:%d, L3D_x:%d, L3D_y:%d, RT:%d, LT:%d  \n", R3D_x,R3D_y,L3D_x,L3D_y,RT,LT);
#endif
    };

    void Gamepad::debug_xinput() {
#ifdef SILS
        XINPUT_STATE state;
        XInputGetState(0, &state);
        printf("==================\n");
        printf("wButtons: %x \n", state.Gamepad.wButtons);
        printf("sThumbLX: %d \n", state.Gamepad.sThumbLX);
        printf("sThumbLY: %d \n", state.Gamepad.sThumbLY);
        printf("sThumbRX: %d \n", state.Gamepad.sThumbRX);
        printf("sThumbRY: %d \n", state.Gamepad.sThumbRY);
        printf("bRightTrigger: %d \n", state.Gamepad.bRightTrigger);
        printf("bLeftTrigger: %d \n", state.Gamepad.bLeftTrigger);
#endif
    }

}