#ifndef PLANETCANNONS_LOGGER_H
#define PLANETCANNONS_LOGGER_H

#include "ILogger.h"

class Logger : public ILogger {
    public:
        virtual void debug(std::string message);
};

#endif