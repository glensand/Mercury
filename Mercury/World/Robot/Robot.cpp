#include "Robot.h"
#include "World/Terrain/Cell.h"
#include "World/Terrain/Terrain.h"
#include "World/IWorld.h"

namespace merc
{

Robot::~Robot()
{
    m_exploredTerrain.GetCell(m_x, m_y).SetRobot(nullptr);
}

Robot::Robot(RobotType type, IWorld& world, Terrain& terrain)
    : m_type(type)
    , m_world(world)
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
        m_exploredTerrain.GetCell(m_x, m_y).SetRobot(nullptr);
        m_exploredTerrain.GetCell(x, y).SetRobot(this);

        m_x = x;
        m_y = y;
    }
}

void Robot::ClearCell(CellType desiredCell)
{
    auto&& cell = m_exploredTerrain.GetCell(m_x, m_y);

    if (cell.GetType() == desiredCell)
    {
        cell.SetType(CellType::Empty);
        ++m_score;
    }
}

std::pair<std::size_t, std::size_t> Robot::GetPosition() const
{
    return { m_x, m_y };
}

size_t Robot::GetScore() const
{
    return m_score;
}

RobotType Robot::GetType() const
{
    return m_type;
}

void Robot::InitializePosition()
{
    while (true)
    {
        const auto x = rand() % m_world.GetSizeX();
        const auto y = rand() % m_world.GetSizeY();
        auto&& cell = m_world.GetCell(x, y);
        if (CanBeSetOnCell(cell))
        {
            Move(x, y);
            m_exploredTerrain.GetCell(x, y).SetType(cell.GetType());
            break;
        }
    }
}

bool Robot::IsPositionAvailable(size_t x, size_t y) const
{
    if (!m_world.GetTerrain().IsCellOnBoard(x, y))
        return false;
    const auto& cell = m_world.GetCell(x, y);
    return cell.GetType() != CellType::Rock && cell.GetRobot() == nullptr
        && IsPositionAvailableImpl(x, y);
}

bool Robot::IsPositionAvailableImpl(size_t x, size_t y) const
{
    return true;
}

std::pair<size_t, size_t> Robot::ComputeDesiredPosition(Direction dir) const
{
    auto x = m_x;
    auto y = m_y;
    if (dir == Direction::Left)
        x = x > 0 ? x - 1 : 0;
    else if (dir == Direction::Right)
        ++x;
    else if (dir == Direction::Up)
        y = y > 0 ? y - 1 : 0;
    else if (dir == Direction::Down)
        ++y;
    return { x , y };
}

}
