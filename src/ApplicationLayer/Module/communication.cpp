#include <stdarg.h>
#include <stdio.h>
#include "communication.h"

namespace module {

    Communication::Communication(){};

    void Communication::update(){ 

    }

    int Communication::printfAsync(const char* fmt, ...){
        int len = 0;

        va_list ap;
        va_start(ap, fmt);
        static char buffer[1000];
        len = vsprintf(buffer, fmt, ap);

#ifndef SILS
        //putnbyteSCI1(buffer, len);        
#else
        printf("%s", buffer);
#endif
        va_end(ap);
        return len;
    }    
    

    int Communication::printfSync(const char* fmt, ...){
        int len = 0;

        va_list ap;
        va_start(ap, fmt);
        static char buffer[1000];
        len = vsprintf(buffer, fmt, ap);

#ifndef SILS
        //putnbyteSCI1(buffer, len);        
#else
        len = printf("%s", buffer);
#endif
        va_end(ap);
        return len;
    }
}
