#pragma once
#include <vector>

namespace Haproxy
{
    
    class Config
    {
        // METHODs
        public:
        static bool parse( const char* configPath = nullptr );
        static bool store( const char* configPath = nullptr );
        static bool prepare();
        static std::vector<char*> getParsed();
        static std::vector<char*> getSection( const char* type = nullptr );
        static std::vector<char*> getSecureFrontends();
        static std::vector<char*> getSecureDomains();
        static char* dump();

        private:
        static std::vector<char*> parseConfig( const char* configPath = nullptr );
        static std::vector<char*> getSectionByName( const char* type, const char* label=nullptr);
        static bool prepareSecureFrontends();

        // CONSTs AND VARs
        public:
        std::vector<char*> parsedConfig {};
        inline static const char* TEMP_CONFIG_PATH { "/tmp/haproxy.cfg" };
        inline static const char* CONFIG_PATH { "/etc/haproxy/haproxy.cfg" };
        inline static const char* CERTBOT_TEMPLATE_PATH { "/usr/src/app/templates/haproxy.certbot.cfg" };// Adapt this paths
        inline static const char* USER_TEMPLATE_PATH { "/usr/src/app/templates/haproxy.user.cfg" };

        private:
        inline static const char* CONFIG_RESERVED_KEYWORDS[5] {
            "global",
            "defaults",
            "frontend",
            "backend",
            "listen"
        };
    };
}

#ifdef CONFIG_IMPLEMENTATION

#endif // CONFIG_IMPLEMENTATION