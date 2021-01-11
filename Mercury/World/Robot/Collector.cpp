#include "Collector.h"
#include "World/IWorld.h"
#include "World/Terrain/Cell.h"

namespace merc
{

Collector::Collector(IWorld& world, Terrain& terrain)
    : Robot(world, terrain)
{

}

void Collector::Collect()
{
    ClearCell(CellType::Apple);
}

void Collector::Scan()
{
    // TODO: update terrain
}

}
