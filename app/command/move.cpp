#include "move.h"
#include "command/commandtype.h"
#include "app/gameinterface.h"
#include "player/player.h"
#include "world/robot/collector.h"

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
