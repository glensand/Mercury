/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "world/ientity.h"

namespace merc
{

class Robot;

enum class CellType : unsigned char
{
    Empty,
    Rock,
    Apple,
    Bomb,
    Unknown,

    Count,
};

class Cell final : public IEntity
{
public:
    Cell() = default;

    CellType GetType() const;
    void SetType(CellType type);

    Robot* GetRobot() const;
    void SetRobot(Robot* entity);

private:
    CellType m_type{ CellType::Unknown };
    Robot* m_robotOnCell{ nullptr };
};

}
