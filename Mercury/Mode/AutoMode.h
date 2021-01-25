#pragma once

#include "ModeBase.h"
#include <deque>
#include <unordered_map>

namespace merc
{

class Robot;
enum class CellType : unsigned char;
enum class Direction : unsigned char;

class AutoMode : public ModeBase
{
public:

    struct Point final
    {
        std::size_t X;
        std::size_t Y;

        const Point* Prev{ nullptr };

        bool operator==(const Point& p) const
        {
            return p.X == X && p.Y == Y;
        }
    };

    using TDirectionMap = std::unordered_map<Direction, std::function<Point(const Point& p)>>;

    AutoMode(GameInterface& gameInterface, Mode modeType);

    virtual ~AutoMode() = default;

protected:

    std::deque<Direction> FindPath(const Robot& robot, CellType desiredCell, const std::vector<CellType>& forbiddenCells) const;

private:

    static Point Up(const Point& p);
    static Point Down(const Point& p);
    static Point Right(const Point& p);
    static Point Left(const Point& p);

    bool ExploreMap(std::deque<Point>& points, CellType desiredCell, const std::vector<CellType>& forbiddenCells) const;

    std::deque<Direction> Convert(const std::deque<Point>& points) const;
    Direction ComputeDirection(const Point& from, const Point& to) const;
    mutable TDirectionMap m_directions;
};

}
