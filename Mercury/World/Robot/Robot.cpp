#include "Robot.h"
#include "World/Terrain/Cell.h"
#include "World/IWorld.h"

namespace merc
{

Robot::Robot(IWorld& world, Terrain& terrain)
    : m_world(world)
    , m_exploredTerrain(terrain)
{
}

void Robot::Move(Direction direction)
{
    switch (direction) {
    case Direction::Right: {
       if( !IsPositionAvailable(m_x + 1, m_y)) return;
        ++m_x;	
        break;	
    }
    case Direction::Left: {	
        if (!IsPositionAvailable(m_x - 1, m_y)) return;
        --m_x;
        break; }
    case Direction::Down: {
        if (!IsPositionAvailable(m_x, m_y - 1)) return;
        --m_y;	
        break;	}
    case up: {
        if (!IsPositionAvailable(m_x, m_y + 1)) return;
        ++m_y;	
        break;	}
    default: { return; }
    }

    if (IsRobotOnBorder(m_x, m_y)) {
        if ((m_world.GetSizeX >= x + 1) || (m_world.GetSizeX >= y + 1))
            m_exploredTerrain.Resize(x + 1, y + 1);
    }

    return;

}

void Robot::Move(size_t x, size_t y)
{

    // TODO implement motion

    m_x = x;
    m_y = y;
}

void Robot::ClearCell(CellType desiredCell)
{
    auto&& cell = m_world.GetCell(m_x, m_y);

    if (cell.GetType() == desiredCell)
    {
        cell.SetType(CellType::Empty);
        ++m_score;
    }
}

size_t Robot::GetScore() const
{
    return m_score;
}

bool Robot::IsPositionAvailable(size_t x, size_t y)
{
       Cell c = (m_exploredTerrain.GetCell(x, y)).GetType;
    if (c == CellType::Bomb || c == CellType::Rock ) return false;
    return true;
}
    
    bool Robot::IsRobotOnBorder(size_t x, size_t y)
{
    if ((x  == ( (m_exploredTerrain.GetMap()).size() - 1)) || (x == 0)) {
        return true;
    }
    if ((y  == ( (m_exploredTerrain.GetMap())[0].size() - 1)) || (y  == 0)) {
        return true;
    }
    return false;
}

}
