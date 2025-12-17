#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

class ILogger {
public:
    virtual ~ILogger() {}

    virtual void writeLog(const std::string& opType, const std::string& details) = 0;
};

#endif 