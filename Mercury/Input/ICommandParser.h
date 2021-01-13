#pragma once
#include <istream>

namespace merc
{

class ICommand;

class ICommandParser
{
public:

    virtual ~ICommandParser() = default;

    virtual ICommand* Parse(std::istream& stream) = 0;
};

}
