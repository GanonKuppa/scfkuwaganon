#pragma once

#include "baseActivity.h"

namespace activity{

    class ModeSelectActivity : public BaseActivity {
      public:
        void onStart(){}

        ELoopStatus loop() {
            return ELoopStatus::CONTINUE;
        }

        void onFinish(){}
    };


}