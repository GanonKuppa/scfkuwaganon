#include "pd_wdt.h"
#include "hal_wdt.h"

namespace hal{
    void resetWdt(){
#ifndef SILS
        periferal_driver::resetWdt();
#endif
    }

    void initWdt(){
#ifndef SILS
        periferal_driver::initWdt();
#endif
    }

    void startWdt(){
#ifndef SILS
        periferal_driver::startWdt();
#endif
    }
}