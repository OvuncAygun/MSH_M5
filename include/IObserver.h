#pragma once

#include "IDevice.h"

class IObserver {
public:
    virtual ~IObserver() {}

    virtual void update(IDevice* device) = 0;
};