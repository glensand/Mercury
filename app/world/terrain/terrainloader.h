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
#include <string>

namespace merc
{

class MapLoader;

class TerrainLoader final
{
    using TMap = std::vector<std::vector<Cell>>;
public:
    TerrainLoader(std::string fileName);

    TMap Load() const;

private:

    static CellType DispatchType(char symb);

    std::string m_fileName;
};

}
