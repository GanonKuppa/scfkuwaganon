#pragma once

#ifdef CMTOUT_

#include <stdint.h>

#include "baseActivity.h"


namespace activity {

    class SearchRunActivity : public BaseActivity {
      public:
        std::string getModeName();
        void onStart();
        void onFinish();
        ELoopStatus loop();
    };


}

#endif