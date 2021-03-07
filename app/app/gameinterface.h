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

class IWorld;
class Player;
class IMode;
class IView;
class ICommandParser;
class CommandServer;

struct GameInterface final
{
    IWorld* World{ nullptr };
    Player* Player{ nullptr };
    IMode* Mode{ nullptr };
    IView* View{ nullptr };
    ICommandParser* CommandParser{ nullptr };
    CommandServer* CommandServer{ nullptr };
};

}
