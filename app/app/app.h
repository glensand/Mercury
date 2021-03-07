/* Copyright (C) 2021 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com, or visit : https://github.com/glensand/Mercury
 */

#pragma once

#include "gameinterface.h"

namespace merc
{

class ICommand;
class ConsoleArgs;

class App final
{
public:

    App() = default;
    ~App();

    void Open(ConsoleArgs& args);

    void Run() const;

private:

    void Render() const;
    void OnFirstFrame() const;
    void OnFrame() const;
    ICommand* ScanCommand() const;

    // TODO: it is better to use factory for each module
    void CreateWorld(ConsoleArgs& args);
    void CreatePlayer();
    void CreateMode();
    void CreateView();
    void CreateInput();
    void CreateCommandServer();

    GameInterface m_gameInterface;
};

}
