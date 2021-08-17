#pragma once

namespace CONSOLE
{
    class Show
    {
        // METHODs
        public:
        static void setColorOutput( int color );
        static void error( const char *message );
        static void info( const char *message );
        static void success( const char *message );

        // CONSTs AND VARs
        public:
        enum CLI_FONT_COLORS_OPS {
            COLOR_BLACK = 0,
            COLOR_RED,
            COLOR_GREEN,
            COLOR_YELLOW,
            COLOR_BLUE,
            COLOR_MAGENTA,
            COLOR_CYAN,
            COLOR_WHITE,
            COLOR_RESET,
            COLOR_COUNT,
        };
        private:
        inline static const char *CLI_FONT_COLORS[COLOR_COUNT]{
            "\033[0;30m",
            "\033[0;31m",
            "\033[0;32m",
            "\033[0;33m",
            "\033[0;34m",
            "\033[0;35m",
            "\033[0;36m",
            "\033[0;37m",
            "\033[0m",
        };
    };
}


#ifdef SHOW_IMPLEMENTATION

namespace CONSOLE
{
    void Show::setColorOutput( int color ){
        // Check the option color first
        if (color >= Show::COLOR_COUNT || color < 0) color = Show::COLOR_RESET;

        std::cout << Show::CLI_FONT_COLORS[color];
    }

    void Show::error( const char *message ){
        Show::setColorOutput( Show::COLOR_RED );
        std::cout << message << "\n";
        Show::setColorOutput( Show::COLOR_RESET );
    }

    void Show::info( const char *message ){
        Show::setColorOutput( Show::COLOR_YELLOW );
        std::cout << message << "\n";
        Show::setColorOutput( Show::COLOR_RESET );
    }

    void Show::success( const char *message ){
        Show::setColorOutput( Show::COLOR_GREEN );
        std::cout << message << "\n";
        Show::setColorOutput( Show::COLOR_RESET );
    }
}

#endif // SHOW_IMPLEMENTATION