#pragma once 

#include "baseModule.h"
#include 

namespace module {
    class BatteryVoltageMonitor : public BaseModule<BatteryVoltageMonitor> {
      public:
        void update();
      private:
        friend class BaseModule<BatteryVoltageMonitor>;
        BatteryVoltageMonitor();
        void _publishMsg();
        float _voltage;
        float _voltage_ave;
        bool _is_low_voltage;
    };

}
