#include "CommandParser.h"
#include "Command/ICommand.h"
#include "Command/Scan.h"
#include "Command/ChangeMode.h"
#include "Command/Grab.h"
#include "Command/Move.h"
#include "Command/SapperSwitch.h"

#include <iostream>
#include <string>

// TODO: use std::istream instead of std::cin
namespace merc
{

CommandParser::CommandParser()
{
    InitializeCommandCreators();
}

CommandParser::~CommandParser()
{

}

ICommand* CommandParser::Parse(std::istream& stream)
{
    std::string commandType;
    stream >> commandType;

    const auto creatorIt = m_creators.find(commandType);
    if(creatorIt != std::end(m_creators))
        return creatorIt->second(stream);
    std::cout << "Invalid command: " << commandType << std::endl;
    return nullptr;
}

void CommandParser::InitializeCommandCreators()
{
    m_creators.emplace("MOVE", [] (std::istream& stream) { return ParseMove(stream); });
    m_creators.emplace("SCAN", [] (std::istream&) { return new Scan; });
    m_creators.emplace("GRAB", [] (std::istream&) { return new Grab; });
    m_creators.emplace("SET_MODE", [](std::istream& stream) { return ParseMode(stream); });
    m_creators.emplace("SAPPER", [](std::istream& stream) { return ParseSapper(stream); });
}

ICommand* CommandParser::ParseMove(std::istream& stream)
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

ICommand* CommandParser::ParseMode(std::istream& stream)
{
    std::string modeStr;
    stream >> modeStr;
    std::any argument = 0;
    auto mode = Mode::Count;
    if (modeStr == "manual")
    {
        mode = Mode::Manual;
    }
    else if(modeStr == "auto")
    {
        mode = Mode::Grab;
    }
    else if(modeStr == "scan")
    {
        int n;
        stream >> n;
        argument = n;
    }
    return new ChangeMode(mode, std::move(argument));
}

ICommand* CommandParser::ParseSapper(std::istream& stream)
{
    std::string OnOff;
    stream >> OnOff;

    if (OnOff == "ON") return new SapperSwitch(true);
    if (OnOff == "OFF") return new SapperSwitch(false);

    return nullptr;
}

}
