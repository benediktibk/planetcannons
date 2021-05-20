#include "Logger.h"
#include <iostream>

using namespace std;

void Logger::error(const string &message) const {
    cerr << message << endl;
}

void Logger::warn(const string &message) const {
    cerr << message << endl;
}

void Logger::info(const string &message) const {
    cout << message << endl;
}

void Logger::debug(const string &message) const {
    cout << message << endl;
}