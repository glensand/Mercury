#pragma once

#include "World/IEntity.h"

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
    Robot* m_robotOnCell{ nullptr };
    CellType m_type{ CellType::Unknown };
};

}
