#include "manualmodecommand.h"
#include "app/gameinterface.h"
#include "mode/imode.h"

#include <stdexcept>
#include <string>

namespace merc
{

void ManualModeCommand::Execute(GameInterface& gameInterface)
{
    AssertModeValid(gameInterface);

    ExecuteImpl(gameInterface);
}

void ManualModeCommand::Undo(GameInterface& gameInterface)
{
    AssertModeValid(gameInterface);

    UndoImpl(gameInterface);
}

void ManualModeCommand::AssertModeValid(GameInterface& gameInterface) const
{
    if (gameInterface.Mode->GetMode() != Mode::Manual)
    {
        throw std::runtime_error("ManualMode commands is not intended to be execute with mode: "
            + std::to_string(int(gameInterface.Mode->GetMode())));
    }
}

}
