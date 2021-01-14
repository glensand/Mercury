#include "App.h"
#include "Input/CommandParser.h"
#include "Input/ConsoleArgs.h"
#include "World/World.h"
#include "World/Terrain/TerrainLoader.h"
#include "Player/Player.h"
#include "Command/CommandServer.h"
#include "Mode/ManualMode.h"
#include "Graphics/SfmlView.h"

#include <sstream>

namespace merc
{

App::~App()
{
    delete m_gameInterface.Player;
    delete m_gameInterface.World;
    delete m_gameInterface.CommandParser;
    delete m_gameInterface.CommandServer;
    delete m_gameInterface.View;
    delete m_gameInterface.Mode;
}

void App::Open(ConsoleArgs& args)
{
    CreateWorld(args);
    CreateInput();
    CreateCommandServer();
    CreatePlayer();
    CreateMode();
    CreateView();
}

void App::Run() const
{
    OnFirstFrame();

    for(;;)
    {
        OnFrame();
    }
}

void App::Render() const
{
    m_gameInterface.View->Render(*m_gameInterface.Player);
}

void App::OnFirstFrame() const
{
    Render();
}

void App::OnFrame() const
{
    if(const auto command = ScanCommand())
    {
        m_gameInterface.CommandServer->Execute(command);

        m_gameInterface.Mode->OnFrame();
    }
}

ICommand* App::ScanCommand() const
{
    auto&& inputCommand = m_gameInterface.View->ScanConsole();
    std::stringstream commandStream(inputCommand);
    return m_gameInterface.CommandParser->Parse(commandStream);
}

void App::CreateWorld(ConsoleArgs& args)
{
    // TODO use named args..., inject loader via factory/constructor
    const TerrainLoader loader(args.GetArg(1));
    m_gameInterface.World = new World(loader.Load());
}

void App::CreatePlayer()
{
    m_gameInterface.Player = new Player(m_gameInterface);
}

void App::CreateMode()
{
    m_gameInterface.Mode = new ManualMode(m_gameInterface);

    // we forced to update view for each simulation step
    // honest async render operation isn't suitable in this case
    m_gameInterface.Mode->SetOnStepCallback([&]
        {
            Render();
        });
}

void App::CreateView()
{
    m_gameInterface.View = new SfmlView;

    m_gameInterface.View->Open();
}

void App::CreateInput()
{
    m_gameInterface.CommandParser = new CommandParser;
}

void App::CreateCommandServer()
{
    m_gameInterface.CommandServer = new CommandServer(m_gameInterface);
}

}
