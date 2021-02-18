#include "MoveParser.h"
#include "Input/ParserFactory.h"
#include "Command/Move.h"

#include <iostream>
#include <string>

namespace merc
{
REGISTER_PARSER(MoveParser)

ICommand* MoveParser::Parse(std::istream& stream)
{
    std::string directionStr;
    stream >> directionStr;
    auto direction = Direction::Count;
    if (directionStr == "D") direction = Direction::Down;
    if (directionStr == "U") direction = Direction::Up;
    if (directionStr == "R") direction = Direction::Right;
    if (directionStr == "L") direction = Direction::Left;

    return new Move(direction);
}

}
