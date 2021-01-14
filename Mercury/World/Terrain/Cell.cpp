#pragma once

#include "Cell.h"

namespace merc
{

CellType Cell::GetType() const
{
    return m_type;
}

void Cell::SetType(CellType type)
{
    m_type = type;
}

Robot* Cell::GetRobot() const
{
    return m_robotOnCell;
}

void Cell::SetRobot(Robot* entity)
{
    m_robotOnCell = entity;
}

}
