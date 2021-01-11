#include "GrabMode.h"

namespace merc
{

GrabMode::GrabMode(GameInterface& gameInterface)
    : ModeBase(gameInterface, Mode::Grab)
{

}

void GrabMode::OnFrame()
{
    // TODO:: simulate

    Render();
}

}
