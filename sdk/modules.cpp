#include "modules.hpp"
#include <Windows.h>

namespace modules
{
    uintptr_t client;
    uintptr_t engine;

    void Initialize()
    {
        client = reinterpret_cast<uintptr_t>(GetModuleHandle("client.dll"));
        engine = reinterpret_cast<uintptr_t>(GetModuleHandle("engine.dll"));
    }
}