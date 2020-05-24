#include <stdint.h>
#include "hal_flashRom.h"

#ifndef SILS
#include "pd_flashRom.h"
#endif
namespace hal {

    bool initFlashRom() {
#ifndef SILS
        return periferal_driver::initDataFlash();
#else
        return true;
#endif
    }

    uint8_t readFlashRom(uint32_t org) {
#ifndef SILS
        return periferal_driver::readDataFlash(org);
#else
        return 0;
#endif
    }

    bool readFlashRom(uint32_t org, void* dst, uint32_t len) {
#ifndef SILS
        return periferal_driver::readDataFlash(org, dst, len);
#else
        return true;
#endif
    }

    bool eraseCheckFlashRom(uint32_t org, uint32_t len) {
#ifndef SILS
        return periferal_driver::eraseCheckDataFlash(org, len);
#else
        return true;
#endif
    }

    bool eraseFlashRom(uint32_t org) {
#ifndef SILS
        return periferal_driver::eraseDataFlash(org);
#else
        return true;
#endif
    }

    bool eraseAllFlashRom() {
#ifndef SILS
        return periferal_driver::eraseAllDataFlash();
#else
        return true;
#endif
    }

    bool writeFlashRom(uint32_t org, const void* src, uint32_t len) {
#ifndef SILS
        return periferal_driver::writeDataFlash(org, src, len);
#else
        return true;
#endif
    }

    bool writeFlashRom(uint32_t org, uint8_t data) {
#ifndef SILS
        return periferal_driver::writeDataFlash(org, data);
#else
        return true;
#endif
    }


}
