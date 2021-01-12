#include "App.h"
#include "Input/ConsoleInput.h"
#include "Input/ConsoleArgs.h"
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
    m_gameInterface.Input->Process();

    m_gameInterface.CommandServer->OnFrame();

    m_gameInterface.Mode->OnFrame();
}

void App::CreateWorld(ConsoleArgs& args)
{
    // TODO use named args..., inject loader via factory/constructor
    const TerrainLoader loader(args.GetArg(1));
    m_gameInterface.World = new World(loader.Load());
}

void App::CreatePlayer(ConsoleArgs& args)
{
    m_gameInterface.Player = new Player(m_gameInterface);
}

void App::CreateMode(ConsoleArgs& args)
{
    m_gameInterface.Mode = new ManualMode(m_gameInterface);

    // we forced to update view for each simulation step
    // honest async render operation isn't suitable in this case
    m_gameInterface.Mode->SetOnStepCallback([&]
        {
            m_gameInterface.View->Render(m_gameInterface.Player->GetExploredTerrain());
        });
}

void App::CreateView(ConsoleArgs& args)
{
    m_gameInterface.View = new ConsoleView;
}

void App::CreateInput(ConsoleArgs& args)
{
    m_gameInterface.Input = new ConsoleInput;
}

}
