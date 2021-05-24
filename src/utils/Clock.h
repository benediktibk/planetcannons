#ifndef PLANETCANNONS_CLOCK_H
#define PLANETCANNONS_CLOCK_H

#include <cstdint>

class Clock {
    public:
        Clock();
        void startMeasurement();
        uint64_t getMillisecondsSinceStart();

    private:
        uint64_t getNowInMilliseconds();

    private:
        uint64_t m_startTime;
};

#endif