#include <iostream>
#include <Eigen>
#include <thread>
#include <windows.h>
#include <stdint.h>
#include "sendData2Sim.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <time.h>

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


uint16_t time_count = 0;
float delta_t = 0.00025;
float x = 0.0;
float y = 0.0;
float ang = 0.0;
float v = 0.0;

void timeInterrupt0() {
    module::LedController::getInstance().update();
    time_count ++;
    x += delta_t * 0.1;
    y += delta_t * 0.1;
    ang += delta_t * 10;
}


void worker() {
    std::chrono::system_clock::time_point  start, end; // 型は auto で可
    start = std::chrono::system_clock::now(); // 計測開始時間

    // ループを25msec / delta_t = 80回進める
    for(int i=0;i<100;i++){
        timeInterrupt0();
    }
    
    while(1){
        end = std::chrono::system_clock::now();  // 計測終了時間
        double elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
        if(elapsed > 25 * 1000){
            std::cout << elapsed << std::endl;
            break; //25msec経過していたら抜ける
        } 
    }

    worker();
}


int main() {    
    sim::initSimConnection();
    std::thread t1(worker);
    ////////////////////////////////////////////////////
    halInit();
    startUpInit();

    while(1) {

        module::LedController::getInstance().update();
        //auto activity = ActivityFactory::createModeSelect();
        //activity->start();
        std::cout << __PRETTY_FUNCTION__  << time_count << std::endl;
        time_count ++;
        Sleep(30);


        sim::setRobotPos(x, y, ang, v);
    }
    
    sim::finalizeSimConnection();
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
    module::LedController::getInstance().setDeltaT(0.00025);
}
