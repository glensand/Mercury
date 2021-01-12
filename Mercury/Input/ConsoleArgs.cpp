#include "ConsoleArgs.h"
#include <stdexcept>

namespace merc
{

ConsoleArgs::ConsoleArgs(int argc, char** argv)
    : m_argsCount(argc)
    , m_args(argv)
{

}

const char* ConsoleArgs::GetArg(unsigned index) const
{
    if (index >= m_argsCount)
        throw std::runtime_error("ConsoleArgs: arg index out of range");
    return m_args[index];
}

}
