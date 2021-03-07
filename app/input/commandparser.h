/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "input/icommandparser.h"

#include <unordered_map>
#include <memory>
#include <string>

namespace merc
{

class ParserConfig;
class IParserFactory;

class CommandParser final : public ICommandParser
{
    using TCommandParserMap = std::unordered_map<std::string, std::unique_ptr<ICommandParser>>;
public:

    CommandParser() = default;
    ~CommandParser() = default;

    virtual ICommand* Parse(std::istream& stream) override;

    void Initialize(const ParserConfig& config, const IParserFactory& factory);
private:
    TCommandParserMap m_parsers;
};

}
