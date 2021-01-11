#pragma once

#include "Command/ManualModeCommand.h"
#include "World/Robot/Robot.h"

namespace merc
{

class Move final : public ManualModeCommand
{
public:
    Move(Direction direction);
    virtual ~Move() = default;

private:
    virtual void ExecuteImpl(GameInterface& gameInterface) override;

    virtual void UndoImpl(GameInterface& gameInterface) override;

    virtual CommandType GetCommandType() const override;

    Direction m_direction{ Direction::Front };
};

}
