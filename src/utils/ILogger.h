#ifndef PLANETCANNONS_ILOGGER_H
#define PLANETCANNONS_ILOGGER_H

#include <string>

class ILogger {
    public:
        virtual void error(const std::string &message) const = 0;
        virtual void warn(const std::string &message) const = 0;
        virtual void info(const std::string &message) const = 0;
        virtual void debug(const std::string &message) const = 0;

        ILogger() {};
        virtual ~ILogger() {};

    private:
        ILogger(const ILogger&) {};
        void operator=(const ILogger&) {};
};

#endif