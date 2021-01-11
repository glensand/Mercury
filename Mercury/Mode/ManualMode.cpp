#include "ManualMode.h"
#include "App/GameInterface.h"

namespace merc
{

ManualMode::ManualMode(GameInterface& gameInterface)
    : ModeBase(gameInterface, Mode::Manual)
{

}

void ManualMode::OnFrame()
{
    // TODO:: simulate

    Render();
}

}
