/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once
#include <string>

namespace merc
{

class Player;

class IView
{
public:

    virtual ~IView() = default;

    virtual const std::string& ScanConsole() = 0;

    virtual void Render(const Player& player) = 0;

    virtual void Present() = 0;

    virtual void Open() = 0;

    virtual void Close() = 0;
};

}
