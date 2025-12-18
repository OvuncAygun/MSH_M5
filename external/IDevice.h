#pragma once

#include "DeviceType.h"

#include <string>
#include <vector>

class IDevice {
public:
    virtual ~IDevice() = default;

    virtual std::string getName() = 0;
    virtual void setName(const std::string& name) = 0;

    virtual std::vector<std::string> getConfig() = 0;
    virtual void setConfig(const std::vector<std::string>& config) = 0;

    virtual bool getPowerState() = 0;
    virtual void setPowerState(bool powerState) = 0;

    virtual bool getOperationState() = 0;
    virtual void setOperationState(bool operationState) = 0;

    virtual DeviceType getDeviceType() = 0;
    virtual void setDeviceType(DeviceType deviceType) = 0;

    virtual int getIndex() = 0;
    virtual void setIndex(int index) = 0;

    virtual void poweron() = 0;
    virtual void poweroff() = 0;
    virtual void detect() = 0;
    
};