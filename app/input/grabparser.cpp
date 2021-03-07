#include "GrabParser.h"
#include "input/ParserFactory.h"
#include "Command/Grab.h"

#include <iostream>
#include <string>

namespace merc
{
   
REGISTER_PARSER(GrabParser)

ICommand* GrabParser::Parse(std::istream& /*stream*/)
{
    return new Grab;
}

}
