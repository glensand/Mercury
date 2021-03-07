#include "manualmode.h"
#include "app/gameinterface.h"

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
