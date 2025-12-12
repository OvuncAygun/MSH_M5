#pragma once

#include "ILogger.h"
#include "IObserver.h"

class MSH_M5 {
public:
    MSH_M5();
    ~MSH_M5();

    ILogger* getLogger();
    IObserver* getObserver();
};