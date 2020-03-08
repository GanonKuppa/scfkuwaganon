#include "hal_clock.h"
#include "pd_clock.h"

namespace hal {
    void initClock() {
#ifndef SILS
        periferal_driver::initClock();
#endif
    }
}

