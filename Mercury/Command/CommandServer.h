#pragma once
#include <vector>

namespace merc
{

struct GameInterface;
class ICommand;

class CommandServer final
{
public:
    CommandServer(GameInterface& gameInterface);
    ~CommandServer();

    void Execute(ICommand* command);

    void UndoLast();
private:

    GameInterface& m_gameInterface;
    // TODO:: use unique_pointer (bu'r i suppose this kind of ugly mess)
    std::vector<ICommand*> m_appliedCommands; // in case we supposed to use special command (Undo)
};

}
