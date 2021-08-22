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
    CONSOLE::Command::setArgs( argc, argv );
    CONSOLE::Command::showLogo();

    constexpr size_t help_num = 3;
    const char* help_commands[help_num] = {"help", "-h", "--help"};
    
    CONSOLE::Command::match<help_num>( help_commands, [](){
        CONSOLE::Command::showHelp();
    });

    CONSOLE::Command::matchSingle( "create", [](){
        FLOW::Action::createCerts();
        std::cout << "test create\n";
    });

    CONSOLE::Command::matchSingle( "renew", [](){
        FLOW::Action::renewCerts();
        std::cout << "test renew\n";
    });

    CONSOLE::Command::matchSingle( "watch", [](){
        FLOW::Action::watchLogs();
        std::cout << "test watch\n";
    });

    CONSOLE::Command::matchSingle( "log:success", [](){
        FLOW::Action::logSucces();
        std::cout << "test log:s\n";
    });

    CONSOLE::Command::matchSingle( "log:error", [](){
        FLOW::Action::logError();
        std::cout << "test log:e\n";
    });

    CONSOLE::Command::matchSingle( "start", [](){
        HAPROXY::Service::start();
        std::cout << "test start\n";
    });

    CONSOLE::Command::matchSingle( "stop", [](){
        HAPROXY::Service::stop();
        std::cout << "test stop\n";
    });

    CONSOLE::Command::matchSingle( "restart", [](){
        HAPROXY::Service::restart();
        std::cout << "test restart\n";
    });

    return 0;
}