#pragma once

#ifdef CMTOUT_

#include <stdint.h>

#include "baseActivity.h"
#include "activityFactory.h"

namespace activity {

    class SubModeSelectActivity : public BaseActivity {
      public:
        std::string getModeName();
        void onStart();
        void onFinish();
        ELoopStatus loop();
    };


}
#endif