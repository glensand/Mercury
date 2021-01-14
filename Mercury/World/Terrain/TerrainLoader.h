#pragma once

#include "World/Terrain/Cell.h"
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
