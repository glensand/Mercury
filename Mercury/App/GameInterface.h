#pragma once

namespace merc
{

class IWorld;
class Player;
class IMode;
class IView;
class ICommandParser;
class CommandServer;

struct GameInterface final
{
    IWorld* World{ nullptr };
    Player* Player{ nullptr };
    IMode* Mode{ nullptr };
    IView* View{ nullptr };
    ICommandParser* CommandParser{ nullptr };
    CommandServer* CommandServer{ nullptr };
};

}
