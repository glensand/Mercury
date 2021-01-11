#include "App/App.h"
#include <exception>
#include <iostream>

namespace merc
{

class ConsoleArgs
{

};

}

int main()
{
    merc::ConsoleArgs args;
    merc::App app;

    try
    {
        app.Open(args);
        app.Run();

    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what();
    }
    catch(...)
    {
        // just ignore...
    }

    return 0;
}