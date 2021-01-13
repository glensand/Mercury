#pragma once
#include <string>

namespace merc
{

class Terrain;

class IView
{
public:

    virtual ~IView() = default;

    virtual const std::string& ScanConsole() = 0;

    virtual void Render(const Terrain& terrain) = 0;

    virtual void Open() = 0;

    virtual void Close() = 0;
};

}
