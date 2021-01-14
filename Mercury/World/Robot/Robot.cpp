#include "Robot.h"
#include "World/Terrain/Cell.h"
#include "World/Terrain/Terrain.h"
#include "World/IWorld.h"

namespace merc
{

Robot::~Robot()
{
    m_world.GetCell(m_x, m_y).SetEntity(nullptr);
}

Robot::Robot(IWorld& world, Terrain& terrain)
    : m_world(world)
    , m_exploredTerrain(terrain)
{

}

void Robot::Move(Direction direction)
{
    const auto& [x, y] = ComputeDesiredPosition(direction);
    Move(x, y);
}

void Robot::Move(size_t x, size_t y)
{
    if (IsPositionAvailable(x, y))
    {
        m_world.GetCell(m_x, m_y).SetEntity(nullptr);
        m_world.GetCell(x, y).SetEntity(this);

        m_x = x;
        m_y = y;
    }
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

void Robot::InitializePosition()
{
    while (true)
    {
        m_x = rand() % m_world.GetSizeX();
        m_y = rand() % m_world.GetSizeY();
        const auto& cell = m_exploredTerrain.GetCell(m_x, m_y);
        if (CanBeSetOnCell(cell))
            break;
    }
}

bool Robot::IsPositionAvailable(size_t x, size_t y) const
{
    const auto& cell = m_world.GetCell(x, y);
    return cell.GetType() != CellType::Rock || cell.GetEntity() == nullptr;
}

std::pair<size_t, size_t> Robot::ComputeDesiredPosition(Direction dir) const
{
    auto x = m_x;
    auto y = m_y;
    if (dir == Direction::Left)
        --x;
    else if (dir == Direction::Right)
        ++x;
    else if (dir == Direction::Up)
        ++y;
    else if (dir == Direction::Down)
        --y;
    return { x , y };
}

}
