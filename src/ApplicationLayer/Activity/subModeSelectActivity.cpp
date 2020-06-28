#include "subModeSelectActivity.h"

#ifdef CMTOUT_
namespace activity{    


    std::string SubModeSelectActivity::getModeName()
    {
        std::string mode_name = "SubModeSelectActivity";
        return mode_name;
    }

    void SubModeSelectActivity::onStart(){

    }
    
    
    void SubModeSelectActivity::onFinish(){

    }


    SubModeSelectActivity::ELoopStatus SubModeSelectActivity::loop() {

        return ELoopStatus::CONTINUE;
    }
}

#endif