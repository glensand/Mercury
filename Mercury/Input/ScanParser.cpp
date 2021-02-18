#include "ScanParser.h"
#include "Input/ParserFactory.h"
#include "Command/Scan.h"

#include <iostream>
#include <string>

namespace merc
{

REGISTER_PARSER(ScanParser)

ICommand* ScanParser::Parse(std::istream& /*stream*/)
{
    return new Scan;
}

}
