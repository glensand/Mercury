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

class Terrain;

class Sapper final : public Robot
{
public:
    virtual ~Sapper() = default;
    Sapper(IWorld& world, Terrain& exploredTerrain);

    virtual void InitializePosition() override;

    void Delouse();
private:
    virtual bool CanBeSetOnCell(const Cell& cell) const override;

    virtual bool IsPositionAvailableImpl(size_t x, size_t y) const override;
};

}
