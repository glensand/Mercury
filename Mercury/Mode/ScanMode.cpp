#include "ScanMode.h"

namespace merc
{

ScanMode::ScanMode(GameInterface& gameInterface)
    : ModeBase(gameInterface, Mode::Scan)
{

}

void ScanMode::OnFrame()
{
    // TODO:: scan

    Render();
}

}
