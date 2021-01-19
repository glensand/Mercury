#pragma once

#include "World/Terrain/Cell.h"
#include <vector>

namespace merc
{

class TerrainLoader;

class Terrain final
{
    using TMap = std::vector<std::vector<Cell>>;
public:
    Terrain(TMap&& map);
    Terrain();

    void Resize(size_t x, size_t y);

    std::size_t GetSizeX() const;
    std::size_t GetSizeY() const;

    bool IsCellOnBoard(size_t x, size_t y) const;

    Cell& GetCell(size_t x, size_t y);
    const Cell& GetCell(size_t x, size_t y) const;

    const TMap& GetMap() const;
private:
    TMap m_map;
};

}
