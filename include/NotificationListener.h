#ifndef NOTIFICATIONLISTENER_H
#define NOTIFICATIONLISTENER_H

#include "IObserver.h"
#include "ILogger.h"
#include "NotificationType.h"
#include <string>

// Observer Pattern: Cihazlardan gelen guncellemeleri dinler.
class NotificationListener : public IObserver {
private:
    ILogger* logger;                  // Object for log operations
    NotificationType userPreference;  // Log, SMS, Alarm

    // Simulations
    void sendSMS(const std::string& msg);
    void triggerAlarm(const std::string& msg);

public:
    // Constructor: Logger'i disaridan (Dependency Injection) veya Singleton'dan alir.
    NotificationListener(ILogger* loggerRef);
    virtual ~NotificationListener();

    // Kullanici tercihini degistirmek icin (REQ9)
    void setPreference(NotificationType pref);

    void update(IDevice* device);
};

#endif 