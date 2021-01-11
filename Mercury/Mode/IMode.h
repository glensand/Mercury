#pragma once

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
};

}
