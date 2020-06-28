#pragma once

#include <stdint.h>
#include <string>
#include "activityFactory.h"
#include "baseActivity.h"


namespace activity {

    class ModeSelectActivity : public BaseActivity {
      public:
        std::string getModeName();
        void onStart();
        void onFinish();
        ELoopStatus loop();
      private:
        uint8_t _mode;
        void turnFcled();
        EActivityColor modeNum2Color(uint8_t mode);
    };


}