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
    m_map = TMap(y, std::vector<Cell>(x));
}

std::size_t Terrain::GetSizeX() const
{
    return m_map.size();
}

std::size_t Terrain::GetSizeY() const
{
    return !m_map.empty() ? m_map[0].size() : 0;
}

bool Terrain::IsCellOnBoard(size_t x, size_t y) const
{
    return x < m_map.size() && y < m_map[0].size();
}


Cell& Terrain::GetCell(size_t x, size_t y)
{
    if (x >= m_map.size() || y >= m_map[x].size())
        throw std::runtime_error("Terrain::GetCell invalid point"); // TODO:: implement own exception classes
    return m_map[y][x];
}

const Cell& Terrain::GetCell(size_t x, size_t y) const
{
    if (x >= m_map.size() || y >= m_map[x].size())
        throw std::runtime_error("Terrain::GetCell invalid point"); // TODO:: implement own exception classes
    return m_map[y][x];
}

const Terrain::TMap& Terrain::GetMap() const
{
    return m_map;
}

}
