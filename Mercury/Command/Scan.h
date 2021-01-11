#pragma once

#include "Command/ManualModeCommand.h"

namespace merc
{

class Scan final : public ManualModeCommand
{
public:
    Scan() = default;
    virtual ~Scan() = default;

private:
    virtual void ExecuteImpl(GameInterface& gameInterface) override;

    virtual void UndoImpl(GameInterface& gameInterface) override;

    virtual CommandType GetCommandType() const override;
};

}
