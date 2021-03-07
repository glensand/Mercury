/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "world/ientity.h"
#include <utility>

namespace merc
{

enum class CellType : unsigned char;
class Cell;
class IWorld;
class Terrain;

enum class RobotType : unsigned char
{
    Collector,
    Sapper,

    Count,
};

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
    virtual ~Robot();
    Robot(RobotType type, IWorld& world, Terrain& terrain);

    virtual void InitializePosition();

    void Move(Direction direction);
    void Move(size_t x, size_t y);

    void ClearCell(CellType desiredCell);

    std::pair<std::size_t, std::size_t> GetPosition() const;

    size_t GetScore() const;

    RobotType GetType() const;

protected:

    virtual bool CanBeSetOnCell(const Cell& cell) const = 0;

    bool IsPositionAvailable(size_t x, size_t y) const;

    virtual bool IsPositionAvailableImpl(size_t x, size_t y) const = 0;

    std::pair<size_t, size_t> ComputeDesiredPosition(Direction dir) const;

    RobotType m_type;
    IWorld& m_world;
    Terrain& m_exploredTerrain;
    State m_state{ State::Normal };
    size_t m_x{ 0 };
    size_t m_y{ 0 };

    size_t m_score{ 0 };
};

}
