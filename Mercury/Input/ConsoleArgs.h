#pragma once

namespace merc
{

class ConsoleArgs final
{
public:
    ConsoleArgs(int argc, char** argv);

    const char* GetArg(unsigned index) const;

private:
    unsigned m_argsCount;
    char** m_args;
};

}
