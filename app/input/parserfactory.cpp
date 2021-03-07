#include "parserfactory.h"
#include <stdexcept>

namespace merc
{

ParserFactory& ParserFactory::Instance()
{
    static ParserFactory instance;
    return instance;
}

ICommandParser* ParserFactory::Create(std::string_view name) const
{
    const auto parserIt = m_creators.find(name);
    if (parserIt == std::cend(m_creators))
        throw std::runtime_error(std::string("ParserFactory::Create: unknown type name ") + name.data());
    return parserIt->second();
}

}
