#include <stdarg.h>
#include <stdio.h>
#include "communication.h"

namespace module {

    Communication::Communication(){};

    void Communication::update(){ 

    }

    int Communication::printfAsync(const char* fmt, ...){
        int len;

        va_list ap;
        va_start(ap, fmt);

#ifndef SILS
        //static char buffer[1000];
        //len = vsprintf(buffer, fmt, ap);
        //putnbyteSCI1(buffer, len);        
#else
        len = printf(fmt, ap);
#endif
        va_end(ap);
        return len;

    }    
    

    int Communication::printfSync(const char* fmt, ...){
        int len;

        va_list ap;
        va_start(ap, fmt);

#ifndef SILS
        //static char buffer[1000];
        //len = vsprintf(buffer, fmt, ap);
        //putnbyteSCI1(buffer, len);        
#else
        len = printf(fmt, ap);
#endif
        va_end(ap);
        return len;
    }
}
