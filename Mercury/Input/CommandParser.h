/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "ICommandParser.h"
#include <unordered_map>
#include <functional>

namespace merc
{

enum class CommandType : unsigned char;

class CommandParser final : public ICommandParser
{
    using TCreator = std::function<ICommand*(std::istream& stream)>;
public:
    CommandParser();
    ~CommandParser();

    virtual ICommand* Parse(std::istream& stream) override;

private:

    void InitializeCommandCreators();

    static ICommand* ParseMove(std::istream& stream);
    static ICommand* ParseMode(std::istream& stream);
    static ICommand* ParseSapper(std::istream& stream);

    std::unordered_map<std::string, TCreator> m_creators;
};

}
