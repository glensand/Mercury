#include "SapperSwitch.h"
#include "Command/CommandType.h"
#include "App/GameInterface.h"
#include "Player/Player.h"
#include <stdexcept>

namespace merc
{

SapperSwitch::SapperSwitch(CommandType type)
    : m_type(type)
{

}

void SapperSwitch::Execute(GameInterface& gameInterface)
{
    if (m_type == CommandType::SapperOff)
        gameInterface.Player->RemoveSapper();
    else if (m_type == CommandType::SapperOn)
        gameInterface.Player->AddSapper();
    else
        throw std::runtime_error("SapperSwitch::Execute: invalid command type");
}

void SapperSwitch::Undo(GameInterface& gameInterface)
{

}

CommandType SapperSwitch::GetCommandType() const
{
    return m_type;
}

}
