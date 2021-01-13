#pragma once

#include "GameInterface.h"

namespace merc
{

class ConsoleArgs;

class App final
{
public:

    App() = default;
    ~App();

    void Open(ConsoleArgs& args);

    void Run() const;

private:

    void OnFrame() const;

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
