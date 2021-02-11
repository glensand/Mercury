/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

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
