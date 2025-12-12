#pragma once

#include <string>

class ILogger {
public:
    virtual ~ILogger() = default;

    virtual void writeLog(std::string opType, std::string details) = 0;
};