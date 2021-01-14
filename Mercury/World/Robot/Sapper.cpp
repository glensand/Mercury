#include "Sapper.h"
#include "World/Terrain/Cell.h"
#include "World/Terrain/Terrain.h"
#include "World/IWorld.h"

namespace merc
{

Sapper::Sapper(IWorld& world, Terrain& exploredTerrain)
    : Robot(world, exploredTerrain)
{
    InitializePosition();
}

void Sapper::Delouse()
{
    ClearCell(CellType::Bomb);
}

bool Sapper::CanBeSetOnCell(const Cell& cell) const
{
	return cell.GetType() != CellType::Unknown
        && cell.GetType() != CellType::Rock
        && cell.GetEntity() == nullptr;
}

}
