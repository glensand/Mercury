#pragma once

#include "World/IEntity.h"

namespace merc
{

enum class CellType : unsigned char;
class Cell;
class IWorld;
class Terrain;

enum class Direction : unsigned char
{
    Left,
    Right,
    Up,
    Down,

    Count,
};

enum class State : unsigned char
{
    Normal,
    Exploded,
};

class Robot : public IEntity
{
public:
    virtual ~Robot() = default;
    Robot(IWorld& world, Terrain& terrain);

    void Move(Direction direction);
    void Move(size_t x, size_t y);

    void ClearCell(CellType desiredCell);

    size_t GetScore() const;

protected:

    bool IsPositionAvailable(size_t x, size_t y);

    IWorld& m_world;
    Terrain& m_exploredTerrain;
    State m_state{ State::Normal };
    size_t m_x{ 0 };
    size_t m_y{ 0 };

    size_t m_score{ 0 };
};

}
