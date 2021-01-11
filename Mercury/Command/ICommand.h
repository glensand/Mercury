#pragma once

namespace merc
{

struct GameInterface;

enum class CommandType : unsigned char;

class ICommand
{
public:
    virtual ~ICommand() = default;
  
    virtual void Execute(GameInterface& gameInterface) = 0;

    virtual void Undo(GameInterface& gameInterface) = 0;

    virtual CommandType GetCommandType() const = 0;
};

}
