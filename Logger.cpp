#include "Logger.h"
#include <iostream>

using namespace std;

void Logger::debug(const string &message) const {
    cout << message << endl;
}