#pragma once

namespace merc
{

class Cell;

class IWorld
{
public:
    virtual ~IWorld() = default;

    virtual Cell& GetCell(size_t x, size_t y) = 0;

    virtual size_t GetSizeX() const = 0;
    virtual size_t GetSizeY() const = 0;
};

}