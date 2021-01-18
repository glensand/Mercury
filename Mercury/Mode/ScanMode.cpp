#include "ScanMode.h"
#include "App/GameInterface.h"
#include "World/Robot/Robot.h"
#include "World/Terrain/Terrain.h"
#include "Player/Player.h"

namespace merc
{

ScanMode::ScanMode(GameInterface& gameInterface, std::size_t iterations)
    : AutoMode(gameInterface, Mode::Scan, iterations)
    , m_iterations(iterations)
{

}

bool ScanMode::Step()
{
    auto&& collector = m_gameInterface.Player->GetCollector();
    auto path = FindPath(collector, CellType::Unknown);
    if (path.empty())
        return false;

    path.pop_back();
    for(auto&& direction : path)
        collector.Move(direction);
    collector.Scan();
    return true;
}

}
