#include "ConsoleInput.h"
#include "Command/ICommand.h"

namespace merc
{

ConsoleInput::~ConsoleInput()
{
    for (const auto command : m_commands)
        delete command;
}

void ConsoleInput::Scan()
{
    // TODO...
}

ICommand* ConsoleInput::PopCommand()
{
    const auto command = m_commands.back();
    m_commands.pop_back();
    return command;
}

}
