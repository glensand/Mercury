#pragma once
#include <string>

namespace merc
{

struct Player;

class IView
{
public:

    virtual ~IView() = default;

    virtual const std::string& ScanConsole() = 0;

    virtual void Render(const Player& player) = 0;

    virtual void Present() = 0;

    virtual void Open() = 0;

    virtual void Close() = 0;
};

}
