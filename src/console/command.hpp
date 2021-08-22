#pragma once

#include <map>
#include <vector>

namespace CONSOLE
{
    class Command
    {
        // METHODs
        public:
        static void setArgs( int argc, char** args );

        static void showLogo();
        static void showHelp();
        template <size_t COMMANDS_NUM>
        static void match( const char** commands, void (*function)() );

        static void matchSingle( const char* command, void (*function)() );

        // CONSTs AND VARs
        inline static std::vector<char*> m_args { };
        inline static size_t m_argc { 0 };

        private:
        static constexpr size_t COMMAND_COUNT { 9 };

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
#include <cstring>

namespace CONSOLE
{
    void Command::showLogo(){
        const char *logo =
        "\n   __      _\n"
        "  / /  ___| |_ ___     /\\  /\\__ _ _ __  _ __ _____  ___   _\n"
        " / /  / _ \\ __/ __|   / /_/ / _` | '_ \\| '__/ _ \\ \\/ / | | |\n"
        "/ /__|  __/ |_\\__ \\  / __  / (_| | |_) | | | (_) >  <| |_| |\n"
        "\\____/\\___|\\__|___/  \\/ /_/ \\__,_| .__/|_|  \\___/_/\\_\\__,  |\n"
        "                                 |_|                  |___/\n\n";

        std::cout << logo;
    }

    void Command::showHelp(){
        std::cout << "Available commands are explained in the following help:\n";

        for(auto command = COMMANDS.begin(); command != COMMANDS.end(); command++){
            Show::setColorOutput( Show::COLOR_RED );
            std::cout << command->first;
            Show::setColorOutput( Show::COLOR_YELLOW );
            std::cout << " ➔ ";
            Show::setColorOutput( Show::COLOR_RESET );
            std::cout << command->second << "\n";
        }
    }

    void Command::setArgs( int argc, char** args ) {
        if ( argc < 2 ) return;

        Command::m_argc = argc - 1;

        Command::m_args.reserve( Command::m_argc );
        
        for (size_t i = 0; i < Command::m_argc; i++ ){
            Command::m_args[i] = args[i + 1];
        }
    }
    template <size_t COMMANDS_NUM>
    void Command::match( const char** commands, void (*function)() ) {
        for ( size_t i = 0; i < Command::m_argc; i++ ) {
            for ( size_t j = 0; j < COMMANDS_NUM; j++ ){
                if ( strcmp( m_args[i], commands[j] ) == 0 ){
                    function();
                    return;
                }
            }
        }
    }

    void Command::matchSingle( const char* command, void (*function)() ) {
        for ( size_t i = 0; i < Command::m_argc; i++ ) {
            if ( strcmp( m_args[i], command ) == 0 ){
                function();
                return;
            }
        }
    }
}

#endif // COMMAND_IMPLEMENTATION