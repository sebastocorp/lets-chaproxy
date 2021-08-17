#pragma once

namespace CERTBOT
{
    class Command
    {
        // METHODs
        public:
        // TODO: put the methods of certificate class

        // CONSTs AND VARs
        private:
        inline static const char *HAPROXY_CERTS_PATH { "/etc/letsencrypt/haproxy" };
        inline static const char *CERTBOT_CERTS_PATH { "/etc/letsencrypt/live" };
        static char *email;
        static char *enviroment;
        static char **domains;
    };
}

#ifdef CERTBOT_IMPLEMENTATION

#endif // CERTBOT_IMPLEMENTATION