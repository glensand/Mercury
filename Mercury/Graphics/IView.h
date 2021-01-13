#pragma once

namespace merc
{

class Terrain;

class IView
{
public:

    virtual ~IView() = default;

    virtual void Render(const Terrain& terrain) = 0;

    virtual void Open() = 0;

    virtual void Close() = 0;
};

}
