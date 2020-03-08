#include <stdint.h>
#include "hal_timer.h"
#include "pd_timer.h"

namespace hal {
    void initTimer() {
#ifndef SILS
        periferal_driver::initCMTW0();
        periferal_driver::initCMTW1();
        periferal_driver::initTPU0();
#endif
    }


    void waitClockCount(uint32_t cCount) {
#ifndef SILS
        periferal_driver::waitClockCount(cCount);
#endif
    }

    void waitusec(uint32_t usec) {
#ifndef SILS
        periferal_driver::waitusec(usec);
#endif
    }

    void waitmsec(uint32_t msec) {
#ifndef SILS
        periferal_driver::waitmsec(msec);
#endif
    }

    void startTimeuCount() {
#ifndef SILS
        periferal_driver::startTimeuCount();
#endif
    }


    uint32_t getTimeuCount(void) {
#ifndef SILS
        return periferal_driver::getTimeuCount();
#else
        return 0;
#endif
    }

    uint32_t endTimeuCount() {
#ifndef SILS
        return periferal_driver::endTimeuCount();
#else
        return 0;
#endif
    }

    void waitClockCount_sub(uint32_t cCount) {
#ifndef SILS
        return periferal_driver::waitClockCount_sub(cCount);
#endif
    }

    void waitusec_sub(uint32_t usec) {
#ifndef SILS
        periferal_driver::waitusec_sub(usec);
#endif
    }

    void waitmsec_sub(uint32_t msec) {
#ifndef SILS
        periferal_driver::waitmsec_sub(msec);
#endif
    }

    void startTimeuCount_sub() {
#ifndef SILS
        periferal_driver::startTimeuCount_sub();
#endif
    }

    uint32_t getTimeuCount_sub(void) {
#ifndef SILS
        return periferal_driver::getTimeuCount_sub();
#else
        return 0;
#endif
    }

    uint32_t endTimeuCount_sub() {
#ifndef SILS
        return periferal_driver::endTimeuCount_sub();
#else
        return 0;
#endif
    }


    uint32_t getElapsedMsec() {
#ifndef SILS
        return periferal_driver::getElapsedMsec();
#else
        return 0;
#endif
    }


    uint32_t getElapsedSec() {
        return getElapsedMsec() / 1000;
    }

}
