#pragma once

#include "World/IEntity.h"

namespace merc
{

enum class CellType : unsigned char
{
    Empty,
    Rock,
    Apple,
    Bomb,

    Count,
};

class Cell final : public IEntity
{
public:
    Cell() = default;

    CellType GetType() const;
    void SetType(CellType type);

    IEntity* GetEntity() const;
    void SetEntity(IEntity* entity);

private:
    IEntity* m_entityOnCell{ nullptr };
    CellType m_type{ CellType::Empty };
};

}
