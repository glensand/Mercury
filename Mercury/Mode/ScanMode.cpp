#include "ScanMode.h"

namespace merc
{

ScanMode::ScanMode(GameInterface& gameInterface, std::size_t iterations)
    : ModeBase(gameInterface, Mode::Scan)
    , m_iterations(iterations)
{

}

void ScanMode::OnFrame()
{
    for(std::size_t i{ 0 }; i < m_iterations && CanStep(); ++i)
    {
        Step();

        Render();
    }
}

bool ScanMode::CanStep() const
{
    return true;
}

void ScanMode::Step()
{

}

}
