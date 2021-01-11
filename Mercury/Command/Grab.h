#pragma once

#include "Command/ManualModeCommand.h"

namespace merc
{

class Grab final : public ManualModeCommand
{
public:
    Grab() = default;
    virtual ~Grab() = default;

private:
    virtual void ExecuteImpl(GameInterface& gameInterface) override;

    virtual void UndoImpl(GameInterface& gameInterface) override;

    virtual CommandType GetCommandType() const override;
};

}
