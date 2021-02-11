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

bool GrabMode::Step() const
{
    auto&& collector = m_gameInterface.Player->GetCollector();
    const std::vector<CellType> forbiddenCells = { CellType::Bomb, CellType::Rock, CellType::Unknown };
    auto path = FindPath(collector, CellType::Apple, forbiddenCells);
    if (path.empty())
        return false;

    for (auto&& direction : path)
    {
        collector.Move(direction);
        Render();
    }

    collector.Collect();
    return true;
}

}
