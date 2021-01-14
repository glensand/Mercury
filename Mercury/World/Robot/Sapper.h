#pragma once

#include "World/Robot/Robot.h"

namespace merc
{

class Terrain;

class Sapper final : public Robot
{
public:
    virtual ~Sapper() = default;
    Sapper(IWorld& world, Terrain& exploredTerrain);

    void Delouse();
    size_t coll_x{ 0 }, coll_y{0};
};

}
