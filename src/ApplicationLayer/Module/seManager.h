#include "baseModule.h"
#include <memory>
#include <stdint.h>



namespace module {

    enum class ESoundEffect : uint8_t {
        START_UP = 0,

        CURSOR_MOVE = 1,

        ON_ACTIVITY = 2,
        END_ACTIVITY = 3,

        SE_CONFIRM = 4,
        SE_POSITIVE = 5,
        SE_NEGATIVE = 6,
        SE_ERROR = 7,
        SE_GOAL = 8,
        SE_CONNECT = 9,
        SE_
    };



    class SeManager : public BaseModule<SeManager> {
      public:
        void update();

        enum

      private:
        friend class BaseModule<SeManager>;
        SeManager();
    };
}
