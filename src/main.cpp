#include <iostream>

// Libs in stb style
#define COMMAND_IMPLEMENTATION
#include "./console/command.hpp"
#define ACTION_IMPLEMENTATION
#include "./flow/action.hpp"
#define SERVICE_IMPLEMENTATION
#include "./haproxy/service.hpp"

// Para probar
#define LOG_IMPLEMENTATION
#include "./console/log.hpp"


int main( int argc, char* argv[] )
{
    CONSOLE::Command::showLogo();
    CONSOLE::Command::showHelp();

    for (int i = 1; i < argc; i++){
        std::cout << argv[i] << "\n";
    }

    CONSOLE::Log::error("error in message");
    CONSOLE::Log::info("info");
    CONSOLE::Log::success("success");

    return 0;
}