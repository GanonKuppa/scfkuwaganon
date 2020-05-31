#pragma once

#include <stdint.h>

#include "baseActivity.h"
#include "activityFactory.h"

namespace activity {

    class ModeSelectActivity : public BaseActivity {
      public:
        void onStart();
        void onFinish();
        ELoopStatus loop();
      private:
        uint8_t _mode;
        void turnFcled();
        EActivityColor modeNum2Color(uint8_t mode);
    };


}