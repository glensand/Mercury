#include "Collector.h"
#include "World/IWorld.h"
#include "World/Terrain/Cell.h"
#include "World/Terrain/Terrain.h"

namespace merc
{

Collector::~Collector()
{

}

Collector::Collector(IWorld& world, Terrain& terrain)
    : Robot(RobotType::Collector, world, terrain)
{

}

void Collector::Collect()
{
    ClearCell(CellType::Apple);
}

void Collector::Scan() const
{
    ScanCell(m_x - 1, m_y);
    ScanCell(m_x, m_y + 1);
    ScanCell(m_x + 1, m_y);
    ScanCell(m_x , m_y + 1);
}

bool Collector::CanBeSetOnCell(const Cell& cell) const
{
    return cell.GetType() != CellType::Rock
        && cell.GetType() != CellType::Bomb
        && cell.GetRobot() == nullptr;
}

bool Collector::IsPositionAvailableImpl(size_t x, size_t y) const
{
    return m_exploredTerrain.GetCell(x, y).GetType() != CellType::Bomb;
}

void Collector::ScanCell(size_t x, size_t y) const
{
	if (x >= m_world.GetSizeX() || y >= m_world.GetSizeY())
		return;
	m_exploredTerrain.GetCell(x, y).SetType(m_world.GetCell(x, y).GetType());
}

}
