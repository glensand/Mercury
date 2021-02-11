#include "SapperSwitch.h"
#include "Command/CommandType.h"
#include "App/GameInterface.h"
#include "Player/Player.h"

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
