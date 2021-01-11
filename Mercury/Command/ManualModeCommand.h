#pragma once

#include "Command/ICommand.h"

namespace merc
{

class ManualModeCommand : public ICommand
{
public:
    ManualModeCommand() = default;
    virtual ~ManualModeCommand() = default;

    virtual void Execute(GameInterface& gameInterface) override final;

    virtual void Undo(GameInterface& gameInterface) override final;

protected:
    virtual void ExecuteImpl(GameInterface& gameInterface) = 0;
    virtual void UndoImpl(GameInterface& gameInterface) = 0;

private:
    void AssertModeValid(GameInterface& gameInterface) const;
};

}
