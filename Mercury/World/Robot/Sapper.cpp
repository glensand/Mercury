#include "Sapper.h"
#include "World/Terrain/Cell.h"
#include "World/IWorld.h"

namespace merc
{

Sapper::Sapper(IWorld& world, Terrain& exploredTerrain)
    : Robot(world, exploredTerrain)
{

}

void Sapper::Delouse()
{
    ClearCell(CellType::Bomb);
}

}
