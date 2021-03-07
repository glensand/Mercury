/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "world/iworld.h"
#include "world/terrain/terrain.h"
#include <string>

namespace merc
{

class Cell;

class World final : public IWorld
{
public:
    explicit World(Terrain&& terrain);

    virtual const Terrain& GetTerrain() const override;

    virtual Cell& GetCell(size_t x, size_t y) override;

    virtual size_t GetSizeX() const override;
    virtual size_t GetSizeY() const override;

private:
    Terrain m_staticTerrain;
};

}
