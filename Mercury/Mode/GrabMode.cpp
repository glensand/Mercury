#include "GrabMode.h"
#include "App/GameInterface.h"
#include "World/Robot/Robot.h"
#include "World/Terrain/Terrain.h"
#include "Player/Player.h"

namespace merc
{

GrabMode::GrabMode(GameInterface& gameInterface)
	: AutoMode(gameInterface, Mode::Grab)
{

}

void GrabMode::OnFrame()
{
    while(Step())
    {
        Render();
    }
}

bool GrabMode::Step()
{
    auto&& collector = m_gameInterface.Player->GetCollector();
    auto path = FindPath(collector, CellType::Apple);
    if (path.empty())
        return false;

    for (auto&& direction : path)
        collector.Move(direction);
    collector.Collect();
    return true;
}

}
