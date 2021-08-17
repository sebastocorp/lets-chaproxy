#pragma once

#include <string_view>

namespace CONSOLE
{
    class Log
    {
        // METHODs
        public:
        static void error( const char *message, bool show = true );
        static void info( const char *message, bool show = true );
        static void success( const char *message, bool show = true );
        static bool store( const char *message );
        static char *getStrDate();
        static const char *getLast();

        // CONSTs AND VARs
        public:
        static const size_t LOG_MAX_SIZE { 512 };
        inline static const char *LOG_PATH { "/tmp/lets-haproxy.log" };
    };
}

#ifdef LOG_IMPLEMENTATION

#include <cstring>
#include <ctime>
#include <chrono>

namespace CONSOLE
{
    void Log::error( const char *message, bool show ){
        // Create error message
        char msg[ LOG_MAX_SIZE ] = "[ERROR] ";
        strcat( msg, message );

        // Store message
        Log::store( msg );
        
        // Show message
        if ( show ) Show::error( msg );
    }

    void Log::info( const char *message, bool show ){
        // Create info message
        char msg[ LOG_MAX_SIZE ] = "[INFO] ";
        strcat( msg, message );

        // Store message
        Log::store( msg );
        
        // Show message
        if ( show ) Show::info( msg );
    }

    void Log::success( const char *message, bool show ){
        // Create success message
        char msg[ LOG_MAX_SIZE ] = "[SUCCESS] ";
        strcat( msg, message );

        // Store message
        Log::store( msg );
        
        // Show message
        if ( show ) Show::success( msg );
    }

    char *Log::getStrDate(){/*
        time_t now = time(0);
        tm *date = localtime(&now);*/
        // test date
        std::time_t ct = std::time(0);
        char* cc = ctime(&ct);

        std::cout << cc << std::endl;
        // end test 
        /*char str_date[10] = "";
        return str_date;*/
        char *hehe = (char*) "hehe";
        return hehe;
    }

    bool Log::store( const char * message ){
        char * hehe = Log::getStrDate();
        (void) hehe;
        return true;
    }
}

#endif // LOG_IMPLEMENTATION