#pragma once

#include <map>

namespace CONSOLE
{
    class Command
    {
        // METHODs
        public:
        static void showLogo();
        static void showHelp();
        static void match( const char *message ); // Change the arguments to (array command, callable callback)

        // CONSTs AND VARs
        private:
        inline static const std::map<const char*, const char*> COMMANDS {
            { "create", "Create certificates" },
            { "renew", "Renew certificates" },
            { "watch", "Loop watching logs" },
            { "help", "Print this help information" },
            { "start", "Start Haproxy" },
            { "stop", "Stop Haproxy" },
            { "restart", "Restart Haproxy" },
            { "log:success", "Throw exit code 0" },
            { "log:error", "Throw exit code 1" },
        };
    };
}

#ifdef COMMAND_IMPLEMENTATION

#define SHOW_IMPLEMENTATION
#include "./show.hpp"

namespace CONSOLE
{
    void Command::showLogo(){
        const char *logo =
        "   __      _\n"
        "  / /  ___| |_ ___     /\\  /\\__ _ _ __  _ __ _____  ___   _\n"
        " / /  / _ \\ __/ __|   / /_/ / _` | '_ \\| '__/ _ \\ \\/ / | | |\n"
        "/ /__|  __/ |_\\__ \\  / __  / (_| | |_) | | | (_) >  <| |_| |\n"
        "\\____/\\___|\\__|___/  \\/ /_/ \\__,_| .__/|_|  \\___/_/\\_\\__,  |\n"
        "                                 |_|                  |___/\n\n";

        std::cout << logo;
    }

    void Command::showHelp(){
        std::cout << "Available commands are explained in the following help:\n";

        for(auto i = Command::COMMANDS.begin(); i != Command::COMMANDS.end(); i++){
            Show::setColorOutput( Show::COLOR_RED );
            std::cout << i->first;
            Show::setColorOutput( Show::COLOR_YELLOW );
            std::cout << " ➔ ";
            Show::setColorOutput( Show::COLOR_RESET );
            std::cout << i->second << "\n";
        }
    }
}

#endif // COMMAND_IMPLEMENTATION