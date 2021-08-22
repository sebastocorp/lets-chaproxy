# pragma once

namespace HAPROXY
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

namespace HAPROXY
{
    void Service::start() {}
    void Service::stop() {}
    void Service::restart() {}
    bool Service::setCertbotConfig() { return true; }
    bool Service::setRegularConfig() { return true; }
    bool Service::changeMode( const char* mode ) { return true; }
}

#endif // SERVICE_IMPLEMENTATION