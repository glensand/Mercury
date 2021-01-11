#pragma once

#include "Command/ICommand.h"
#include "Mode/IMode.h"

namespace merc
{

class ChangeMode final : public ICommand
{
public:
    ChangeMode(Mode mode);
    virtual ~ChangeMode() = default;

private:
    virtual void Execute(GameInterface& gameInterface) override;

    virtual void Undo(GameInterface& gameInterface) override;

    virtual CommandType GetCommandType() const override;

    IMode* CreateByType(GameInterface& gameInterface) const;

    Mode m_mode;
};

}
