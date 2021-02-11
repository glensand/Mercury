/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include <vector>

namespace merc
{

struct GameInterface;
class ICommand;

class CommandServer final
{
public:
    CommandServer(GameInterface& gameInterface);
    ~CommandServer();

    void Execute(ICommand* command);

    void UndoLast();
private:

    GameInterface& m_gameInterface;
    // TODO:: use unique_pointer (bu'r i suppose this kind of ugly mess)
    std::vector<ICommand*> m_appliedCommands; // in case we supposed to use special command (Undo)
};

}
