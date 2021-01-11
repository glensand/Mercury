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
    return true;
}

}
