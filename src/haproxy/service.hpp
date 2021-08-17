# pragma once

namespace Haproxy
{

    struct Service
    {
        static void start();
        static void stop();
        static void restart();
        static bool setCertbotConfig();
        static bool setRegularConfig();
        static bool changeMode(const char* mode = nullptr);
    };
}

#ifdef SERVICE_IMPLEMENTATION

#endif // SERVICE_IMPLEMENTATION