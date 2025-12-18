#include "MSH_M5.h"
#include "LogManager.h"
#include "NotificationListener.h"

MSH_M5::MSH_M5() {}
MSH_M5::~MSH_M5() {}

void MSH_M5::initializeLoggerAndObserver() {
    logger = LogManager::getInstance();
    observer = new NotificationListener(logger);
};

ILogger* MSH_M5::getLogger() {
    return logger;
}

IObserver* MSH_M5::getObserver() {
    return observer;
}