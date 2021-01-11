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

IEntity* Cell::GetEntity() const
{
    return m_entityOnCell;
}

void Cell::SetEntity(IEntity* entity)
{
    m_entityOnCell = entity;
}

}
