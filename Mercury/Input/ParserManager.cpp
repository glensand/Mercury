#include "ParserManager.h"
#include "Input/ParserConfig.h"

#include <iostream>
#include <string>

namespace merc
{

ICommand* ParserManager::Parse(std::istream& stream)
{
    std::string commandType;
    stream >> commandType;

    const auto creatorIt = m_comandParser.find(commandType);
    if(creatorIt != std::end(m_comandParser))
        return creatorIt->second->Parse(stream);
    std::cout << "Invalid command: " << commandType << std::endl;
    return nullptr;
}

ParserManager& ParserManager::Instance()
{
    static ParserManager instance;
    return instance;
}

void ParserManager::Initialize(const ParserConfig& config)
{
    const auto& commands = config.LoadCommands();
    for(const auto& [command, parserName] : commands)
    {
        const auto parserIt = m_parserContainer.find(parserName);
        if (parserIt == std::end(m_parserContainer))
            throw std::runtime_error("ParserManager::Initialize: uninitialized command parser " + parserName);
        m_comandParser.emplace(command, m_parserContainer[parserName].get());
    }
}

bool ParserManager::RegisterParser(const char* name, ICommandParser* parser)
{
    if (m_parserContainer.count(name) == 0)
    {
        m_parserContainer[name].reset(parser);
    }
    return true;
}

}
