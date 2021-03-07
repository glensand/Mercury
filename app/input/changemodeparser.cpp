#include "changemodeparser.h"
#include "input/parserfactory.h"
#include "command/changemode.h"

#include <iostream>
#include <string>

namespace merc
{

REGISTER_PARSER(ChangeModeParser)

ICommand* ChangeModeParser::Parse(std::istream& stream)
{
    std::string modeStr;
    stream >> modeStr;
    std::any argument = 0;
    auto mode = Mode::Count;
    if (modeStr == "manual")
    {
        mode = Mode::Manual;
    }
    else if (modeStr == "auto")
    {
        mode = Mode::Grab;
    }
    else if (modeStr == "scan")
    {
        mode = Mode::Scan;
        int n;
        stream >> n;
        argument = n;
    }
    return new ChangeMode(mode, std::move(argument));
}

}
