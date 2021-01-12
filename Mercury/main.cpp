#include "App/App.h"
#include "Input/ConsoleArgs.h"
#include <exception>
#include <iostream>

int main(int argc, char* argv[])
{
    merc::ConsoleArgs args{ argc, argv };
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