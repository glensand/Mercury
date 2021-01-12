#pragma once

#include "Command/ICommand.h"

namespace merc
{

class SapperSwitch final : public ICommand
{
public:
    SapperSwitch(bool on);
    virtual ~SapperSwitch() = default;

private:
    virtual void Execute(GameInterface& gameInterface) override;

    virtual void Undo(GameInterface& gameInterface) override;

    virtual CommandType GetCommandType() const override;

    bool m_sapperOn;
};

}
