#pragma once

namespace FLOW
{
    struct Action{
        // METHODs
        static void createCerts();
        static void renewCerts();
        static void watchLogs();

        // Maybe not needed
        static void logSucces();
        static void logError();
    };
}

#ifdef ACTION_IMPLEMENTATION

namespace FLOW
{
    void Action::createCerts(){}
    void Action::renewCerts(){}
    void Action::watchLogs(){}

    // Maybe not needed
    void Action::logSucces(){}
    void Action::logError(){}
}

#endif // ACTION_IMPLEMENTATION