#pragma once

#include "IInput.h"
#include <vector>

namespace merc
{

class ConsoleInput final : public IInput
{
public:
    ConsoleInput() = default;
    ~ConsoleInput();

    virtual void Scan() override;

    virtual ICommand* PopCommand() override;

private:
    std::vector<ICommand*> m_commands;
};

}
