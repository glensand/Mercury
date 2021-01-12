#pragma once

namespace merc
{

class ICommand;

class IInput
{
public:

    virtual ~IInput() = default;

    virtual void Process() = 0;

    virtual ICommand* PopCommand() = 0;
};

}
