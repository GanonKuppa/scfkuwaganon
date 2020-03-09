#include "pd_da.h"
#include "hal_da.h"

namespcae hal{
    void initDA(){
#ifndef SILS
        periferal_driver::initDA();
#endif
    }

    void setDA(float da){
#ifndef SILS
        periferal_driver::setDA(da * (DA_RESOLUTION - 1))
#endif
    }
    
    float getDA(){
#ifndef SILS
        return periferal_driver::getDA / (DA_RESOLUTION - 1);
#else 
        return 0;
#endif     
    }

}