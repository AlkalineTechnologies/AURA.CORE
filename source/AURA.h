#pragma  once

#ifdef _WIN32
    #define AURA_API __declspec(dllexport)
#else
    #define AURA_API __attribute__((visibility("default")))
#endif

namespace AURACORE {    
    #define AURA_VERSION "1.0"
        
    AURA_API void About();
}