#pragma once

#include "World/Robot/Robot.h"

namespace merc
{

class Collector final : public Robot
{
public:
    virtual ~Collector() = default;
    Collector(IWorld& world, Terrain& terrain);

    void Collect();

    void Scan();

private:
    size_t m_score{ 0 };
};

}
