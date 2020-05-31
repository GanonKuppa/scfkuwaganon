#include "modeSelectActivity.h"
#include <stdint.h>
// Module
#include "ledController.h"
#include "activityFactory.h"

namespace activity {


    void ModeSelectActivity::onStart() {

    }

    void ModeSelectActivity::onFinish() {

    }

    ModeSelectActivity::ELoopStatus ModeSelectActivity::loop() {
        return ELoopStatus::CONTINUE;
    }

    void ModeSelectActivity::turnFcled() {
//module::LedController& fcled = module::LedController::getInstance();

        //PseudoDialL& dial_L = PseudoDialL::getInstance();
        module::LedController& fcled = module::LedController::getInstance();
        uint8_t mode = 0;//dial_L.getDialPosition();
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