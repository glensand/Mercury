#pragma once

namespace merc
{

class ICommand;

class IInput
{
public:

    virtual ~IInput() = default;

    virtual void Scan() = 0;

    virtual ICommand* PopCommand() = 0;
};

}
