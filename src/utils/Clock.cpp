#include "Clock.h"
#include <chrono>

Clock::Clock() :
    m_startTime(0) {
}

void Clock::startMeasurement() {
    m_startTime = getNowInMilliseconds();
}

uint64_t Clock::getMillisecondsSinceStart() {
    return getNowInMilliseconds() - m_startTime;
}

uint64_t Clock::getNowInMilliseconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}