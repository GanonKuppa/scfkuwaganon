/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  umouse_scfkuwaganon                    */
/*      FILE         :  umouse_scfkuwaganon.cpp                */
/*      DESCRIPTION  :  Main Program                           */
/*                                                             */
/*      This file was generated by e2 studio.                  */
/*                                                             */
/***************************************************************/

#include <iodefine.h>
#include <stdio.h>
#include <stdarg.h>

// HardwareAbstractionLayer
#include "hal_clock.h"
#include "hal_gpio.h"
#include "hal_timer.h"
#include "hal_uart.h"
#include "hal_ad.h"
#include "hal_da.h"
#include "hal_flashRom.h"
#include "hal_phaseCounting.h"
#include "hal_pwm.h"
#include "hal_spi.h"
#include "hal_timerInterrupt.h"
#include "hal_wdt.h"

// Module
#include "ledController.h"

// プロトタイプ宣言
void halInit();
void startUpInit();
void object_init();


#ifdef CPPAPP
//Initialize global constructors
extern void __main() {
    static int initialized;
    if (! initialized) {
        typedef void (*pfunc) ();
        extern pfunc __ctors[];
        extern pfunc __ctors_end[];
        pfunc* p;

        initialized = 1;
        for (p = __ctors_end; p > __ctors; )
            (*--p) ();

    }
}
#endif

extern "C" void timerInterrupt0();
extern "C" void timerInterrupt1();

void timerInterrupt0(){
    //http://japan.renesasrulz.com/cafe_rene/f/69/t/1515.aspx 多重割り込み 資料
    __builtin_rx_setpsw('I');

    module::LedController::getInstance().update();
}

void timerInterrupt1(){

}

int main(void) {
    halInit();
    startUpInit();
    while(1) {
        char hoge[100];
        sprintf( &hoge[0], "0123456789\n" );
        // TODO: add application code here
        hal::waitmsec(1000);
        module::LedController::getInstance().turnFcled(false, false, false);
        //hal::setDout2(0);
        hal::waitmsec(1000);
        hal::putnbyteUart0((uint8_t *)hoge, 10);
        hal::putnbyteUart1((uint8_t *)hoge, 10);
        hal::sendDataUart1();
        //hal::setDout2(1);
        module::LedController::getInstance().turnFcled(true, true, true);

    }
    return 0;
}

//各ペリフェラルの初期化
void halInit() {    
    hal::initClock();
    hal::initGpio();
    hal::initTimer();
    hal::initUart0();
    hal::initUart1();
    hal::initAD();
    hal::initDA();
    hal::initFlashRom();
    hal::initPhaseCounting0();
    hal::initPhaseCounting1();
    hal::initPWM0();
    hal::initPWM1();
    hal::initPWM2();
    hal::initPWM3();
    hal::initSPI0();
    hal::initTimerInterrupt0();
    hal::initTimerInterrupt1();
    hal::initWdt();

}


//起動時の処理
void startUpInit() {
    hal::startTimerInterrupt0();
}


void object_init() {    
    //module::LedController::getInstance().setDeltaT(0.00025);
}


