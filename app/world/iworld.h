/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

namespace merc
{

class Cell;
class Terrain;

class IWorld
{
public:
    virtual ~IWorld() = default;

    virtual Cell& GetCell(size_t x, size_t y) = 0;

    virtual const Terrain& GetTerrain() const = 0;

    virtual size_t GetSizeX() const = 0;
    virtual size_t GetSizeY() const = 0;
};

}