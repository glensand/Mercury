#include "AutoMode.h"
#include "App/GameInterface.h"
#include "World/Robot/Robot.h"
#include "World/Terrain/Terrain.h"
#include "Player/Player.h"

#include <algorithm>
#include <vector>

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

bool AutoMode::ExploreMap(std::deque<Point>& points, CellType desiredCell, const std::vector<CellType>& forbiddenCells) const
{
    const auto& cur = points.back();
    auto&& terrain = m_gameInterface.Player->GetExploredTerrain();
    for (std::size_t i{ 0 }; i < std::size_t(Direction::Count); ++i)
    {
        const auto point = m_directions[Direction(i)](cur);
        if (!terrain.IsCellOnBoard(point.X, point.Y) || std::find(std::cbegin(points), std::cend(points), point) != std::cend(points))
            continue;
        auto&& cell = terrain.GetCell(point.X, point.Y);
        if (cell.GetRobot() != nullptr)
            continue;
        if(cell.GetType() == desiredCell)
        {
            points.emplace_back(point);
            return true;
        }
        if(std::find(std::cbegin(forbiddenCells), std::cend(forbiddenCells), cell.GetType()) == std::cend(forbiddenCells))
        {
            points.emplace_back(point);
            if (ExploreMap(points, desiredCell, forbiddenCells))
                return true;
        }
    }

    return false;
}

std::deque<Direction> AutoMode::Convert(const std::deque<Point>& points) const
{
    std::deque<Direction> result;
    auto* point = &points.back();
    while(point->Prev != nullptr)
    {
        result.push_front(ComputeDirection(*point->Prev, *point));
        point = point->Prev;
    }
    return result;
}

Direction AutoMode::ComputeDirection(const Point& from, const Point& to) const
{
    for (std::size_t i{ 0 }; i < std::size_t(Direction::Count); ++i)
    {
        if (m_directions[Direction(i)](from) == to)
            return Direction(i);
    }

    return Direction::Count;
}

std::deque<Direction> AutoMode::FindPath(const Robot& robot, CellType desiredCell, const std::vector<CellType>& forbiddenCells) const
{
    std::deque<Point> points;
    std::deque<Direction> directions;
    const auto& [x, y] = robot.GetPosition();
    points.emplace_back(Point{ x, y });
    if(ExploreMap(points, desiredCell, forbiddenCells))
    {
        directions = Convert(points);
    }
    return directions;
}

}
