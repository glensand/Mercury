#include "App.h"
#include "Input/ConsoleInput.h"
#include "World/World.h"
#include "World/Terrain/TerrainLoader.h"
#include "Player/Player.h"
#include "Command/CommandServer.h"
#include "Mode/ManualMode.h"
#include "Graphics/ConsoleView.h"

namespace merc
{

App::~App()
{

}

void App::Open(ConsoleArgs& args)
{
    CreateWorld(args);
    CreateInput(args);
    CreatePlayer(args);
    CreateMode(args);
    CreateView(args);
}

void App::Run() const
{
    for(;;)
    {
        OnFrame();
    }
}

void App::OnFrame() const
{
    m_gameInterface.Input->Scan();

    m_gameInterface.CommandServer->OnFrame();

    m_gameInterface.Mode->OnFrame();
}

void App::CreateWorld(ConsoleArgs& args)
{
    const TerrainLoader loader(""); // TODO extract file name, inject loader via factory/constructor
    m_gameInterface.World = new World(loader.Load());
}

void App::CreatePlayer(ConsoleArgs& args)
{
    m_gameInterface.Player = new Player(m_gameInterface);
}

void App::CreateMode(ConsoleArgs& args)
{
    m_gameInterface.Mode = new ManualMode(m_gameInterface);
}

void App::CreateView(ConsoleArgs& args)
{
    m_gameInterface.View = new ConsoleView;
}

void App::CreateInput(ConsoleArgs& args)
{
    m_gameInterface.Input = new ConsoleInput();
}

}
