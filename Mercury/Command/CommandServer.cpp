#include "CommandServer.h"
#include "Command/ICommand.h"
#include "App/GameInterface.h"
#include <iostream>

namespace merc
{

CommandServer::CommandServer(GameInterface& gameInterface)
    : m_gameInterface(gameInterface)
{

}

CommandServer::~CommandServer()
{
    for (const auto command : m_appliedCommands)
        delete command;
}

void CommandServer::Execute(ICommand* command)
{
    try
    {
        command->Execute(m_gameInterface);
        m_appliedCommands.push_back(command);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what();
    }
    catch (...)
    {
        // just ignore
    }
}

void CommandServer::UndoLast()
{
    const auto lastCommand = m_appliedCommands.back();
    lastCommand->Undo(m_gameInterface);
    delete lastCommand;
    m_appliedCommands.pop_back();
}

}
