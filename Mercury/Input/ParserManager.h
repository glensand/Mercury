/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "Input/ICommandParser.h"

#include <unordered_map>
#include <memory>
#include <string>

namespace merc
{

class ParserConfig;
class ICommandParser;

class ParserManager final : public ICommandParser
{
    using TParserNameMap = std::unordered_map<std::string, std::unique_ptr<ICommandParser>>;
    using TCommandParserMap = std::unordered_map<std::string, ICommandParser>;
public:

    virtual ICommand* Parse(std::istream& stream) override;

    static ParserManager& Instance();

    bool RegisterParser(const char* name, ICommandParser* parser);

    void Initialize(const ParserConfig& config);
private:
    ParserManager() = default;
    ~ParserManager() = default;

    TParserNameMap  m_parserContainer;
    TParserNameMap  m_comandParser;

    ParserManager(const ParserManager&) = delete;
    ParserManager(ParserManager&&) = delete;

    ParserManager& operator=(const ParserManager&) = delete;
    ParserManager& operator=(ParserManager&&) = delete;
};

}

#define REGISTER_PARSER(ClassName) static const bool ClassName_registered = ParserManager::Instance().RegisterParser(#ClassName, new ClassName);
