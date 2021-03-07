#include "grab.h"
#include "command/commandtype.h"
#include "app/gameinterface.h"
#include "player/player.h"

namespace merc
{

void Grab::ExecuteImpl(GameInterface& gameInterface)
{
    gameInterface.Player->GetCollector().Collect();
}

void Grab::UndoImpl(GameInterface&)
{

}

CommandType Grab::GetCommandType() const
{
    return CommandType::Grab;
}

}
