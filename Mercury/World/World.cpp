#include "World.h"
#include "Terrain/TerrainLoader.h"

namespace merc
{

World::World(Terrain&& terrain)
    : m_staticTerrain(std::move(terrain))
{

}

Cell& World::GetCell(size_t x, size_t y)
{
    return m_staticTerrain.GetCell(x, y);
}

std::size_t World::GetSizeX() const
{
    return m_staticTerrain.GetMap().size();
}

std::size_t World::GetSizeY() const
{
    return !m_staticTerrain.GetMap().empty() ? m_staticTerrain.GetMap()[0].size() : 0;
}

}
