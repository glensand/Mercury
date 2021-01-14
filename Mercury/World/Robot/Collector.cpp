#include "Collector.h"
#include "World/IWorld.h"
#include "World/Terrain/Cell.h"

namespace merc
{

Collector::Collector(IWorld& world, Terrain& terrain)
    : Robot(world, terrain)
{
        	size_t length = m_world.GetSizeX;
	size_t width = m_world.GetSizeY;
	while (true) {
		size_t x = (rand() % (width - 1)) + 1;
		size_t y = (rand() % (length - 1)) + 1;
		Cell b = m_world.GetCell(x, y);
		if (b.GetType != CellType::Bomb && b.GetType != CellType::Rock) {
			m_x = x;
			m_y = y;
			break;
		}
	}

}

void Collector::Collect()
{
    ClearCell(CellType::Apple);
}

void Collector::Scan()
{
    // TODO: update terrain
        (m_exploredTerrain.GetCell(m_x - 1, m_y)).SetType((m_world.GetCell(m_x - 1, m_y)).GetType());
    (m_exploredTerrain.GetCell(m_x, m_y + 1)).SetType((m_world.GetCell(m_x, m_y + 1)).GetType());
    (m_exploredTerrain.GetCell(m_x + 1, m_y)).SetType((m_world.GetCell(m_x + 1, m_y)).GetType());
    (m_exploredTerrain.GetCell(m_x , m_y + 1)).SetType((m_world.GetCell(m_x , m_y + 1)).GetType());
}

}
