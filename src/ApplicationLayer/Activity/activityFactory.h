#pragma once

#include "BaseActivity.h"

#include <stdint.h>
#include <memory>

enum class EActivityColor : uint8_t {
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7
};

class ActivityFactory {
    public:
    static std::unique_ptr<BaseActivity> create(EActivityColor name);
    static std::unique_ptr<BaseActivity> cteateSubModeSelect();
    static std::unique_ptr<BaseActivity> cteateModeSelect();

};
