#pragma once

#include "IDevice.h"

class IObserver {
public:
    virtual ~IObserver() = default;

    virtual void update(IDevice* device) = 0;
};