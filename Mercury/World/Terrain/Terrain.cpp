#include "World/Terrain/Terrain.h"
#include <stdexcept>

namespace merc
{

Terrain::Terrain(TMap&& map)
    : m_map(std::move(map))
{

}

Terrain::Terrain()
{

}

void Terrain::Resize(size_t x, size_t y)
{
    m_map.clear();
    m_map.resize(x);
    for (auto&& r : m_map)
        r = std::vector<Cell>(y);
}

Cell& Terrain::GetCell(size_t x, size_t y)
{
    if (x >= m_map.size() || y >= m_map[x].size())
        throw std::runtime_error("Terrain::GetCell invalid point"); // TODO:: implement own exception classes
    return m_map[x][y];
}

const Terrain::TMap& Terrain::GetMap() const
{
    return m_map;
}

}
