#include "Move.h"
#include "Command/CommandType.h"
#include "App/GameInterface.h"
#include "Player/Player.h"
#include "World/Robot/Collector.h"

namespace merc
{

Move::Move(Direction direction)
    : m_direction(direction)
{

}

void Move::ExecuteImpl(GameInterface& gameInterface)
{
    gameInterface.Player->GetCollector().Move(m_direction);
}

void Move::UndoImpl(GameInterface&)
{
    // get opposite direction and move...
}

CommandType Move::GetCommandType() const
{
    return CommandType::Move;
}

}
