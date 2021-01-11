#pragma once

namespace merc
{

class IWorld;
class Player;
class IMode;
class IView;
class IInput;
class CommandServer;

struct GameInterface final
{
    IWorld* World{ nullptr };
    Player* Player{ nullptr };
    IMode* Mode{ nullptr };
    IView* View{ nullptr };
    IInput* Input{ nullptr };
    CommandServer* CommandServer{ nullptr };
};

}
