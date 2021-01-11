#include "World/Terrain/TerrainLoader.h"

namespace merc
{

TerrainLoader::TerrainLoader(std::string fileName)
    : m_fileName(std::move(fileName))
{
}

TerrainLoader::TMap TerrainLoader::Load() const
{
    // TODO:: load terrain... use csv-like format

    return {};
}

}
