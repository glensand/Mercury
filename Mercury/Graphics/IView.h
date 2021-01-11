#pragma once

namespace merc
{

class Terrain;

class IView
{
public:

    virtual ~IView() = default;

    virtual void Render(const Terrain& terrain) = 0;
};

}
