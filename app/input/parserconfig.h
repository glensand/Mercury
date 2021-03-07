/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include <unordered_map>

namespace merc
{

class ParserConfig final
{
    using TCommandNameParserMap = std::unordered_map<std::string, std::string>;
public:

    ParserConfig(std::string_view fileName);
    ParserConfig(ParserConfig&) = delete;

    virtual ~ParserConfig() = default;

    TCommandNameParserMap LoadCommands() const;

private:
    std::string m_configName;
};

}
