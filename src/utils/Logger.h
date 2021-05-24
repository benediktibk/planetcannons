#ifndef PLANETCANNONS_LOGGER_H
#define PLANETCANNONS_LOGGER_H

#include "ILogger.h"

class Logger : public ILogger {
    public:
        virtual void error(const std::string &message) const;
        virtual void warn(const std::string &message) const;
        virtual void info(const std::string &message) const;
        virtual void debug(const std::string &message) const;
};

#endif