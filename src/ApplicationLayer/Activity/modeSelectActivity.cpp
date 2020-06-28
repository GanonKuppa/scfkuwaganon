#include "modeSelectActivity.h"
#include <stdint.h>
#include <string>

// Module
#include "ledController.h"
#include "activityFactory.h"
#include "gamepad.h"
#include "seManager.h"
#include "baseActivity.h"

namespace activity {

    std::string ModeSelectActivity::getModeName()
    {
        std::string mode_name("ModeSelectActivity");
        return mode_name;
    }

    void ModeSelectActivity::onStart() {
        
    }

    void ModeSelectActivity::onFinish() {
        
    }

    ModeSelectActivity::ELoopStatus ModeSelectActivity::loop() {
        module::Gamepad &gp = module::Gamepad::getInstance();
        
        if(gp.cross_y == 1){
            _mode =  (_mode + 8 + 1) % 8;
            hal::waitmsec(100);
            sound::cursor_move();
        }
        
        if(gp.cross_y == -1){
            _mode =  (_mode + 8 - 1) % 8;
            hal::waitmsec(100);
            sound::cursor_move();
        }

        if(gp.B > 50 && gp.B < 100){
            hal::waitmsec(100);
            sound::confirm();
        }



        turnFcled();
        return ELoopStatus::CONTINUE;
    }

    void ModeSelectActivity::turnFcled() {
//module::LedController& fcled = module::LedController::getInstance();

        //PseudoDialL& dial_L = PseudoDialL::getInstance();
        module::LedController& fcled = module::LedController::getInstance();
        uint8_t mode = _mode;//dial_L.getDialPosition();
        //UMouse& m = UMouse::getInstance();
        //ParameterManager& pm = ParameterManager::getInstance();
        //m.maze.makeFastestMap(0, 0);
        bool ableGoal = false;//m.maze.isExistPath(pm.goal_x, pm.goal_y);

        if(ableGoal) {
            if (mode == 0) fcled.turnFcled(0, 0, 0); //BLACK
            else if (mode == 1) fcled.flashFcled(1, 0, 0, 0.4, 0.1);//RED
            else if (mode == 2) fcled.flashFcled(0, 1, 0, 0.4, 0.1);//GREEN
            else if (mode == 3) fcled.flashFcled(1, 1, 0, 0.4, 0.1);//YELLOW
            else if (mode == 4) fcled.flashFcled(0, 0, 1, 0.4, 0.1);//BLUE
            else if (mode == 5) fcled.flashFcled(1, 0, 1, 0.4, 0.1);//MAGENTA
            else if (mode == 6) fcled.flashFcled(0, 1, 1, 0.4, 0.1);//CYAN
            else if (mode == 7) fcled.flashFcled(1, 1, 1, 0.4, 0.1);//WHITE
        } else {
            if (mode == 0) fcled.turnFcled(0, 0, 0); //BLACK
            else if (mode == 1) fcled.turnFcled(1, 0, 0);//RED
            else if (mode == 2) fcled.turnFcled(0, 1, 0);//GREEN
            else if (mode == 3) fcled.turnFcled(1, 1, 0);//YELLOW
            else if (mode == 4) fcled.turnFcled(0, 0, 1);//BLUE
            else if (mode == 5) fcled.turnFcled(1, 0, 1);//MAGENTA
            else if (mode == 6) fcled.turnFcled(0, 1, 1);//CYAN
            else if (mode == 7) fcled.turnFcled(1, 1, 1);//WHITE
        }

    }


    EActivityColor ModeSelectActivity::modeNum2Color(uint8_t mode) {
        EActivityColor color;
        color = (EActivityColor)mode;
        return color;
    }


}