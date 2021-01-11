#include "Scan.h"
#include "Command/CommandType.h"
#include "App/GameInterface.h"
#include "Player/Player.h"

namespace merc
{

void Scan::ExecuteImpl(GameInterface& gameInterface)
{
    gameInterface.Player->GetCollector().Scan();
}

void Scan::UndoImpl(GameInterface& gameInterface)
{

}

CommandType Scan::GetCommandType() const
{
    return CommandType::Scan;
}

}
