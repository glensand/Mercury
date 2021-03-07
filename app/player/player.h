/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "world/terrain/terrain.h"
#include "world/robot/collector.h"
#include "world/robot/sapper.h"
#include <memory>

namespace merc
{

struct GameInterface;

class Player final
{
public:
    explicit Player(GameInterface& gameInterface);

    Sapper* GetSapper() const;
    void AddSapper();
    void RemoveSapper();

    Collector& GetCollector();
    const Collector& GetCollector() const;

    const Terrain& GetExploredTerrain() const;

private:
    std::unique_ptr<Sapper> m_sapper;
    Collector m_collector;

    GameInterface& m_gameInterface;
    Terrain m_exploredTerrain;
};

}
