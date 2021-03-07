#include "world.h"
#include "terrain/terrainloader.h"

namespace merc
{

World::World(Terrain&& terrain)
    : m_staticTerrain(std::move(terrain))
{

}

const Terrain& World::GetTerrain() const
{
    return m_staticTerrain;
}

Cell& World::GetCell(size_t x, size_t y)
{
    return m_staticTerrain.GetCell(x, y);
}

std::size_t World::GetSizeX() const
{
    return m_staticTerrain.GetSizeX();
}

std::size_t World::GetSizeY() const
{
    return m_staticTerrain.GetSizeY();
}

}
