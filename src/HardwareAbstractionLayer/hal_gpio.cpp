#include "hal_gpio.h"

#ifndef SILS
#include "pd_gpio.h"
#endif

namespace hal{

    void initGpio(){
#ifndef SILS
        periferal_driver::initGpio();
        setDout0(false);
        setDout1(false);
        setDout2(false);
        setDout3(false);
        setDout4(false);
        setDout5(false);
        setDout6(false);
#endif
    }

    void setDout0(bool out){
#ifndef SILS
        periferal_driver::setDoutPD4(out);
#endif
    }

    void setDout1(bool out){
#ifndef SILS
        periferal_driver::setDoutPD3(out);
#endif
    }

    void setDout2(bool out){
#ifndef SILS
        periferal_driver::setDoutPD2(out);
#endif
    }

    void setDout3(bool out){
#ifndef SILS
        periferal_driver::setDoutPE0(out);
#endif
    }

    void setDout4(bool out){
#ifndef SILS
        periferal_driver::setDoutPD7(out);
#endif
    }

    void setDout5(bool out){
#ifndef SILS
        periferal_driver::setDoutPD0(out);
#endif
    }

    void setDout6(bool out){
#ifndef SILS
        periferal_driver::setDoutP07(out);
#endif
    }

    void setDout7(bool out){

    }

}

