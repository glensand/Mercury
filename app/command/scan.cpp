#include "scan.h"
#include "command/commandtype.h"
#include "app/gameinterface.h"
#include "player/player.h"

namespace merc
{

void Scan::ExecuteImpl(GameInterface& gameInterface)
{
    gameInterface.Player->GetCollector().Scan();
}

void Scan::UndoImpl(GameInterface&)
{

}

CommandType Scan::GetCommandType() const
{
    return CommandType::Scan;
}

}
