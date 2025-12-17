#include "../include/LogManager.h"
#include <iostream>
#include <ctime> 


LogManager* LogManager::instance = NULL;

LogManager::LogManager() {
    // REQ4: Sistem basladiginda dosya acilir.
    // ios::app -> Append modu (eski loglari silmez, altina yazar)
    logFile.open("msh_log.txt", std::ios::out | std::ios::app);
    
    if (logFile.is_open()) {
        logFile << "--- MSH System Log Started ---" << std::endl;
    } else {
        std::cerr << "ERROR: Log file could not be opened!" << std::endl;
    }
}

LogManager::~LogManager() {
    close();
}

LogManager* LogManager::getInstance() {

    if (instance == NULL) {
        instance = new LogManager();
    }
    return instance;
}

void LogManager::writeLog(const std::string& opType, const std::string& details) {
    if (logFile.is_open()) {
        // C++98 zaman damgasi
        std::time_t now = std::time(0);
        char* dt = std::ctime(&now);
        
        // Ctime sonundaki \n karakterini temizleme
        std::string timeStr = dt;
        if (!timeStr.empty() && timeStr[timeStr.length() - 1] == '\n') {
            timeStr.erase(timeStr.length() - 1);
        }

        // Format: [ZAMAN] [ISLEM] Detay
        logFile << "[" << timeStr << "] [" << opType << "] " << details << std::endl;
        logFile.flush(); // Garantilemek icin flush
    }
}

void LogManager::close() {
    if (logFile.is_open()) {
        logFile << "--- MSH System Shutdown ---" << std::endl;
        logFile.close();
    }
}