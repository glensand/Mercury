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

    struct Point
    {
        std::size_t X;
        std::size_t Y;

        const Point* Prev{ nullptr };
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

    std::deque<Direction> FindPath(CellType desiredCell, const Point& cur, const std::vector<CellType>& forbiddenCells) const;

    mutable TDirectionMap m_directions;
};

}
