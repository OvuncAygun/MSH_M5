#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include "ILogger.h"
#include <fstream>
#include <string>


class LogManager : public ILogger {
private:
    static LogManager* instance; // Singleton
    std::ofstream logFile;       // File writing tool

    
    LogManager(); // Private constructor to not make another instance

public:
    
    virtual ~LogManager();
    
    static LogManager* getInstance();

    void writeLog(const std::string& opType, const std::string& details); // Save logs 

    
    void close(); // Close the file 
};

#endif // LOGMANAGER_H