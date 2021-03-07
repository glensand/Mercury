/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "world/terrain/cell.h"
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
