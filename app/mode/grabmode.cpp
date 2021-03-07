#include "GrabMode.h"
#include "app/gameinterface.h"
#include "world/robot/robot.h"
#include "world/terrain/terrain.h"
#include "Player/player.h"

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

void GrabMode::ProcessPath(Robot& robot, const std::deque<Direction>& path)
{
    for (auto&& direction : path)
    {
        robot.Move(direction);
        Render();
    }
}

bool GrabMode::Step()
{
    Delouse();
    return Collect();
}

bool GrabMode::Collect()
{
    auto&& collector = m_gameInterface.Player->GetCollector();
    const std::vector<CellType> forbiddenCells = { CellType::Bomb, CellType::Rock, CellType::Unknown };
    auto path = FindPath(collector, CellType::Apple, forbiddenCells);
    if (path.empty())
        return false;

    ProcessPath(collector, path);
    collector.Collect();
    return true;
}

void GrabMode::Delouse()
{
    const auto sapper = m_gameInterface.Player->GetSapper();
    if (sapper == nullptr)
        return;
    const std::vector<CellType> forbiddenCells = { CellType::Rock, CellType::Unknown };
    auto path = FindPath(*sapper, CellType::Bomb, forbiddenCells);
    if (path.empty())
        return;
    ProcessPath(*sapper, path);
    sapper->Delouse();
}

}
