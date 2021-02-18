/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "Input/IParserFactory.h"

#include <unordered_map>
#include <functional>
#include <string>

namespace merc
{

class ParserConfig;
class ICommandParser;

class ParserFactory final : public IParserFactory
{
    using TCreator = std::function<ICommandParser*()>;
    using TParserCreatorMap = std::unordered_map<std::string_view, TCreator>;
public:

    virtual ICommandParser* Create(std::string_view name) const override;

    static ParserFactory& Instance();

    template<typename T>
    bool RegisterParser(std::string_view name);
private:
    ParserFactory() = default;
    ~ParserFactory() = default;

    TParserCreatorMap m_creators;

    ParserFactory(const ParserFactory&) = delete;
    ParserFactory(ParserFactory&&) = delete;

    ParserFactory& operator=(const ParserFactory&) = delete;
    ParserFactory& operator=(ParserFactory&&) = delete;
};

template <typename T>
bool ParserFactory::RegisterParser(std::string_view name)
{
    m_creators[name] = [] { return new T; };
    return true;
}

}

#define REGISTER_PARSER(ClassName) static const bool ClassName_registered = ParserFactory::Instance().RegisterParser<ClassName>(#ClassName);
