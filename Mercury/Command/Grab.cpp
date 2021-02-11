#include "Grab.h"
#include "Command/CommandType.h"
#include "App/GameInterface.h"
#include "Player/Player.h"

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
