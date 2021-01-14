#pragma once

#include "World/Terrain/Terrain.h"
#include "World/Robot/Collector.h"
#include "World/Robot/Sapper.h"
#include <memory>

namespace merc
{

struct GameInterface;

class Player final
{
public:
    Player(GameInterface& gameInterface);

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
