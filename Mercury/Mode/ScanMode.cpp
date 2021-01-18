#include "ScanMode.h"
#include "App/GameInterface.h"
#include "World/Robot/Robot.h"
#include "World/Terrain/Terrain.h"
#include "Player/Player.h"
#include <thread>

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
        const auto begin = std::chrono::steady_clock::now();
        if (Step())
        {
            Render();
        }
        else
        {
            break; // no available motions
        }
        const auto end = std::chrono::steady_clock::now();
        const auto curFrameTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::this_thread::sleep_for(curFrameTime);
    }
}

bool ScanMode::Step() const
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
