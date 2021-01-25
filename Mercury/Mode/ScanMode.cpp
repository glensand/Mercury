#include "ScanMode.h"
#include "App/GameInterface.h"
#include "World/Robot/Robot.h"
#include "World/Terrain/Terrain.h"
#include "Player/Player.h"

namespace merc
{

ScanMode::ScanMode(GameInterface& gameInterface, std::size_t iterations)
    : AutoMode(gameInterface, Mode::Scan)
    , m_iterations(iterations)
{

}

void ScanMode::OnFrame()
{
    for (std::size_t i{ 0 }; i < m_iterations; ++i)
    {
        if (Step())
        {
            Render();
        }
        else
        {
            break; // no available motions
        }
    }

    m_iterations = 0;
}

bool ScanMode::Step() const
{
    auto&& collector = m_gameInterface.Player->GetCollector();
    const std::vector<CellType> forbiddenCells = { CellType::Bomb, CellType::Rock };
    auto path = FindPath(collector, CellType::Unknown, forbiddenCells);
    if (path.empty())
        return false;

    path.pop_back();
    for (auto&& direction : path)
    {
        collector.Move(direction);
        Render();
    }

    collector.Scan();
    return true;
}

}
