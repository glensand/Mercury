#pragma once

#include <functional>

namespace merc
{

enum class Mode : unsigned char
{
    Manual,
    Scan,
    Grab,

    Count,
};

class IMode
{
public:
    virtual ~IMode() = default;

    virtual Mode GetMode() const = 0;

    virtual void OnFrame() = 0;

    // TODO:: use boost::signal
    virtual void SetOnStepCallback(std::function<void()>&& callback) = 0;
};

}
