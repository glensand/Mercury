#include "Sapper.h"
#include "World/Terrain/Cell.h"
#include "World/Terrain/Terrain.h"
#include "World/IWorld.h"

namespace merc
{

Sapper::Sapper(IWorld& world, Terrain& exploredTerrain)
    : Robot(RobotType::Sapper, world, exploredTerrain)
{
    InitializePosition();
}

void Sapper::InitializePosition()
{
    while (true)
    {
        const auto x = rand() % m_exploredTerrain.GetSizeX();
        const auto y = rand() % m_exploredTerrain.GetSizeY();
        auto&& cell = m_exploredTerrain.GetCell(x, y);
        if (CanBeSetOnCell(cell))
        {
            Move(x, y);
            break;
        }
    }
}

void Sapper::Delouse()
{
    ClearCell(CellType::Bomb);
}

bool Sapper::CanBeSetOnCell(const Cell& cell) const
{
	return cell.GetType() != CellType::Unknown
        && cell.GetType() != CellType::Rock
        && cell.GetRobot() == nullptr;
}

bool Sapper::IsPositionAvailableImpl(size_t, size_t) const
{
    return true;
}


}
