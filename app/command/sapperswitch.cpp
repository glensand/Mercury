#include "sapperswitch.h"
#include "command/commandtype.h"
#include "app/gameinterface.h"
#include "player/player.h"

namespace merc
{

SapperSwitch::SapperSwitch(bool on)
    : m_sapperOn(on)
{

}

void SapperSwitch::Execute(GameInterface& gameInterface)
{
    if(m_sapperOn)
        gameInterface.Player->AddSapper();
    else
        gameInterface.Player->RemoveSapper();
}

void SapperSwitch::Undo(GameInterface&)
{

}

CommandType SapperSwitch::GetCommandType() const
{
    return CommandType::Sapper;
}

}
