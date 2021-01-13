#include "ConsoleInput.h"
#include "Command/ICommand.h"
#include "Command/Scan.h"
#include "Command/ChangeMode.h"
#include "Command/Grab.h"
#include "Command/Move.h"
#include "Command/SapperSwitch.h"
#include <iostream>
#include <string>

// TODO: use std::istream instead of std::cin
namespace merc
{

ConsoleInput::ConsoleInput()
{
    InitializeCommandCreators();
}

ConsoleInput::~ConsoleInput()
{
    delete m_command;
}

void ConsoleInput::Process()
{
    std::string commandType;
    std::cin >> commandType;

    const auto creatorIt = m_creators.find(commandType);
    if(creatorIt != std::end(m_creators))
    {
        m_command = creatorIt->second();
    }
    else
    {
        std::cout << "Invalid command: " << commandType << std::endl;
    }
}

ICommand* ConsoleInput::PopCommand()
{
    const auto command = m_command;
    m_command = nullptr;
    return command;
}

void ConsoleInput::InitializeCommandCreators()
{
    m_creators.emplace("MOVE", [] { return ScanMove(); });
    m_creators.emplace("SCAN", [] { return new Scan; });
    m_creators.emplace("GRAB", [] { return new Grab; });
    m_creators.emplace("SET_MODE", [] { return ScanMode(); });
    m_creators.emplace("SAPPER", [] { return ScanSapper(); });
}

ICommand* ConsoleInput::ScanMove()
{
    std::string directionStr;
    std::cin >> directionStr;
    auto direction = Direction::Count;
    if (directionStr == "D") direction = Direction::Down;
    if (directionStr == "U") direction = Direction::Up;
    if (directionStr == "R") direction = Direction::Right;
    if (directionStr == "L") direction = Direction::Left;

    return new Move(direction);
}

ICommand* ConsoleInput::ScanMode()
{
    std::string modeStr;
    std::cin >> modeStr;
    std::any argument = 0;
    auto mode = Mode::Count;
    if (modeStr == "manual")
    {
        mode = Mode::Manual;
    }
    else if(modeStr == "auto")
    {
        mode = Mode::Grab;
    }
    else if(modeStr == "scan")
    {
        int n;
        std::cin >> n;
        argument = n;
    }
    return new ChangeMode(mode, std::move(argument));
}

ICommand* ConsoleInput::ScanSapper()
{
    std::string OnOff;
    std::cin >> OnOff;

    if (OnOff == "ON") return new SapperSwitch(true);
    if (OnOff == "OFF") return new SapperSwitch(false);

    return nullptr;
}

}
