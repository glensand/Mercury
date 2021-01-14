#include "Sapper.h"
#include "World/Terrain/Cell.h"
#include "World/IWorld.h"

namespace merc
{

Sapper::Sapper(IWorld& world, Terrain& exploredTerrain)
    : Robot(world, exploredTerrain)
{
        	size_t sapper_x, sapper_y;
	while (true) {
		sapper_x = rand() % (m_exploredTerrain.GetMap()).size();
		sapper_y = rand() % (m_exploredTerrain.GetMap()[0]).size();
		if (( (m_exploredTerrain.GetMap())[sapper_x][sapper_y] != CellType:: Unknown) && (( (m_exploredTerrain.GetMap())[sapper_x][sapper_y] != CellType::Rock) 
			&& (sapper_x != coll_x || sapper_y != coll_y)) {
			break;
		}
	}

}

void Sapper::Delouse()
{
    ClearCell(CellType::Bomb);
}

}
