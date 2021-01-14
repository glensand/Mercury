#pragma once

#include "World/IWorld.h"
#include "World/Terrain/Terrain.h"
#include <string>

namespace merc
{

class Cell;

class World final : public IWorld
{
public:
    World(Terrain&& terrain);

    virtual const Terrain& GetTerrain() const override;

    virtual Cell& GetCell(size_t x, size_t y) override;

    virtual size_t GetSizeX() const override;
    virtual size_t GetSizeY() const override;

private:
    Terrain m_staticTerrain;
};

}
