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
    void CreatePlayer(ConsoleArgs& args);
    void CreateMode(ConsoleArgs& args);
    void CreateView(ConsoleArgs& args);
    void CreateInput(ConsoleArgs& args);

    GameInterface m_gameInterface;
};

}
