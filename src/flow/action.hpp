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

#endif // ACTION_IMPLEMENTATION