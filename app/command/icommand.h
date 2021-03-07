/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

namespace merc
{

struct GameInterface;

enum class CommandType : unsigned char;

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual void Execute(GameInterface& gameInterface) = 0;

    virtual void Undo(GameInterface& gameInterface) = 0;

    virtual CommandType GetCommandType() const = 0;
};

}
