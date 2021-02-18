#include "SapperParser.h"
#include "Input/ParserFactory.h"
#include "Command/SapperSwitch.h"

#include <iostream>
#include <string>

namespace merc
{

REGISTER_PARSER(SapperParser)

ICommand* SapperParser::Parse(std::istream& stream)
{
    std::string OnOff;
    stream >> OnOff;

    if (OnOff == "ON") return new SapperSwitch(true);
    if (OnOff == "OFF") return new SapperSwitch(false);

    return nullptr;
}

}
