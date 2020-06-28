#include "calibrateWallCenterActivity.h"

#ifdef CMTOUT_
namespace activity{    


    std::string CalibrateWallCenterActivity::getModeName()
    {
        std::string mode_name = "CalibrateWallCenterActivity";
        return mode_name;
    }

    void CalibrateWallCenterActivity::onStart(){

    }
    
    
    void CalibrateWallCenterActivity::onFinish(){

    }


    CalibrateWallCenterActivity::ELoopStatus CalibrateWallCenterActivity::loop() {

        return ELoopStatus::CONTINUE;
    }
}

#endif