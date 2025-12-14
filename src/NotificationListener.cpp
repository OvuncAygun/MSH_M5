#include "../include/NotificationListener.h"
#include <iostream>

NotificationListener::NotificationListener(ILogger* loggerRef) {
    this->logger = loggerRef;
    this->userPreference = LOG_ONLY; // Default
}

NotificationListener::~NotificationListener() {}

void NotificationListener::setPreference(NotificationType pref) {
    this->userPreference = pref;
    if (logger) {
        logger->writeLog("INFO", "Notification preference changed.");
    }
}

void NotificationListener::update(IDevice* device) {
    if (device == NULL) return;

    std::string deviceName = device->getName(); 
    std::string msg = "Status update received from: [" + deviceName + "]";
    
    switch (userPreference) {
        case SMS_SIMULATION:
            sendSMS(msg);
            if (logger) logger->writeLog("SMS", "SMS sent for device update.");
            break;

        case ALARM_SOUND:
            triggerAlarm(msg);
            if (logger) logger->writeLog("ALARM", "Alarm triggered for device update.");
            break;

        case LOG_ONLY:
        default:
            if (logger) logger->writeLog("INFO", "Device update received (Log Only).");
            break;
    }
}

void NotificationListener::sendSMS(const std::string& msg) {
    std::cout << ">>> [SMS SENT]: " << msg << " <<<" << std::endl;
}

void NotificationListener::triggerAlarm(const std::string& msg) {
    std::cout << "!!! [ALARM SOUND]: BEEP BEEP BEEP - " << msg << " !!!" << std::endl;
}