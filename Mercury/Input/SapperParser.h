/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "Input/ICommandParser.h"

namespace merc
{

class SapperParser final : public ICommandParser
{
public:

    SapperParser() = default;
    virtual ~SapperParser() = default;

    virtual ICommand* Parse(std::istream& stream) override;
};

}
