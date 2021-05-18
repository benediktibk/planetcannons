#ifndef PLANETCANNONS_ILOGGER_H
#define PLANETCANNONS_ILOGGER_H

#include <string>

class ILogger {
    public:
        virtual void debug(std::string message) = 0;
};

#endif