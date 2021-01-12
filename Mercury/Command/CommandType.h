#pragma once

namespace merc
{

enum class CommandType : unsigned char
{
    Move,
    Grab,
    Scan,
    SetMode,
    Sapper,

    Count,
};

}
