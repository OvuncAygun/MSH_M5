#pragma once

#include "../external/IDevice.h"

class IObserver {
public:
    virtual ~IObserver() {}

    virtual void update(IDevice* device) = 0;
};