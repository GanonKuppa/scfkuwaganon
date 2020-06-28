#include "radioControlActivity.h"

#ifdef CMTOUT_
namespace activity{    


    std::string RadioControlActivity::getModeName()
    {
        std::string mode_name = "RadioControlActivity";
        return mode_name;
    }

    void RadioControlActivity::onStart(){

    }
    
    
    void RadioControlActivity::onFinish(){

    }


    RadioControlActivity::ELoopStatus RadioControlActivity::loop() {

        return ELoopStatus::CONTINUE;
    }
}

#endif