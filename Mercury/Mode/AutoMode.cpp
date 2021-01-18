#include "AutoMode.h"
#include "App/GameInterface.h"
#include "World/Robot/Robot.h"
#include "World/Terrain/Terrain.h"
#include "Player/Player.h"

namespace
{
constexpr std::size_t MovesPerSecond{ 3 };
constexpr auto FrameTime{ 1000 * 1.0 / double(MovesPerSecond) };
}

namespace merc
{

AutoMode::AutoMode(GameInterface& gameInterface, Mode modeType)
    : ModeBase(gameInterface, modeType)
{
    m_directions[Direction::Up] = [](const Point& p) { return Up(p); };
    m_directions[Direction::Down] = [](const Point& p) { return Down(p); };
    m_directions[Direction::Left] = [](const Point& p) { return Left(p); };
    m_directions[Direction::Right] = [](const Point& p) { return Right(p); };
}

AutoMode::Point AutoMode::Up(const Point& p)
{
    return { p.X, p.Y - 1, &p };
}

AutoMode::Point AutoMode::Down(const Point& p)
{
    return { p.X, p.Y + 1, &p };
}

AutoMode::Point AutoMode::Right(const Point& p)
{
    return { p.X + 1, p.Y, &p };
}

AutoMode::Point AutoMode::Left(const Point& p)
{
    return { p.X - 1, p.Y, &p };
}

std::deque<Direction> AutoMode::FindPath(CellType desiredCell, const Point& initial) const
{
    std::deque<Direction> directions;
    auto&& terrain = m_gameInterface.Player->GetExploredTerrain();
    for(std::size_t i{ 0 }; i < std::size_t(Direction::Count); ++i)
    {
        const auto nextPoint = m_directions[Direction(i)](initial);
        if (initial.Prev != nullptr && nextPoint.X == initial.Prev->X && nextPoint.Y == initial.Prev->Y)
            continue; // step out do not allowed

        auto&& cell = terrain.GetCell(nextPoint.X, nextPoint.Y);
        if(cell.GetType() == desiredCell)
        {
            directions.emplace_back(Direction(i)); // found whole path to the desired cell
            break;
        }

        if(cell.GetType() != CellType::Bomb && cell.GetType() != CellType::Rock)
        {
            auto&& newDirections = FindPath(desiredCell, nextPoint);
            if(!newDirections.empty()) // found path to the desired cell
            {
                directions.emplace_back(Direction(i));
                for (const auto direction : newDirections) // just insert part of the whole path
                    directions.emplace_back(direction);
                break;
            }
        }
    }

    return directions;
}

std::deque<Direction> AutoMode::FindPath(const Robot& robot, CellType desiredCell) const
{
    const auto [x, y] = robot.GetPosition();
    const auto initialPoint = Point{ x, y };
    return FindPath(desiredCell, initialPoint);
}

}
