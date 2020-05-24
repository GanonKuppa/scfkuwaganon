#pragma once

#include "intent.h"
#include "hal_timer.h"
#include <utility>
#include <memory>


namespace activity {

    class BaseActivity {
      public:
        void start(std::unique_ptr<Intent> intent) {
            _lower_limit_loop_msec = 1;
            _intent = std::move(intent);
            onStart();
            while(1) {
                hal::startTimeuCount_sub();
                uint32_t start_msec = hal::getElapsedMsec();
                if(loop() == ELoopStatus::FINISH) break;
                uint32_t end_msec = hal::getElapsedMsec();
                uint32_t elapsed_msec = end_msec - start_msec;
                int32_t wait_msec = _lower_limit_loop_msec - elapsed_msec;
                if(wait_msec > 0) waitmsec(wait_msec);
                hal::endTimeuCount_sub();
            };
            onFinish();
        }

        void start() {
            start(nullptr);
        }

        virtual ~BaseActivity() {};

      protected:
        enum class ELoopStatus {
            CONTINUE = 1,
            FINISH = 0
        }

        virtual ELoopStatus loop() = 0;
        virtual void onStart() = 0;
        virtual void onFinish() = 0;


        uint32_t _lower_limit_loop_msec;
        std::unique_ptr<Intent> _intent;

    };

}
