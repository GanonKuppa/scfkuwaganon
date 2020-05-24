#pragma once

namespace periferal_driver {
    void initGpio();

    void setDoutPD4(bool out);
    void setDoutPD3(bool out);
    void setDoutPD2(bool out);
    void setDoutPE0(bool out);
    void setDoutPD7(bool out);
    void setDoutPD0(bool out);
    void setDoutP07(bool out);
}