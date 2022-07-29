#include <Windows.h>

namespace modules
{
    const auto client = reinterpret_cast<uintptr_t>(GetModuleHandle("client.dll"));
    const auto engine = reinterpret_cast<uintptr_t>(GetModuleHandle("engine.dll"));
}