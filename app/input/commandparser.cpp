#include "commandparser.h"
#include "input/parserconfig.h"
#include "input/iparserfactory.h"

#include <iostream>
#include <string>

namespace merc
{

ICommand* CommandParser::Parse(std::istream& stream)
{
    std::string commandType;
    stream >> commandType;

    const auto creatorIt = m_parsers.find(commandType);
    if(creatorIt != std::end(m_parsers))
        return creatorIt->second->Parse(stream);
    std::cout << "Invalid command: " << commandType << std::endl;
    return nullptr;
}

void CommandParser::Initialize(const ParserConfig& config, const IParserFactory& factory)
{
    const auto& commands = config.LoadCommands();
    for(const auto& [command, parserName] : commands)
    {
        m_parsers.emplace(command, factory.Create(parserName));
    }
}

}
