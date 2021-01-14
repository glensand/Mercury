#pragma once

#include "World/Robot/Robot.h"

namespace merc
{

class Collector final : public Robot
{
public:
    virtual ~Collector();
    Collector(IWorld& world, Terrain& terrain);

    void Collect();

    void Scan() const;

private:
    virtual bool CanBeSetOnCell(const Cell& cell) const override;

    virtual bool IsPositionAvailableImpl(size_t x, size_t y) const override;

    void ScanCell(size_t x, size_t y) const;
};

}
