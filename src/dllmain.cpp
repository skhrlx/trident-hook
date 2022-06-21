#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <cstdint>
#include <thread>

#include "offsets.hpp"
#include "data.hpp"

using namespace hazedumper::netvars;
using namespace hazedumper::signatures;

// hack fn
void BunnyHop(const HMODULE instance) noexcept
{
	const auto client = reinterpret_cast<uintptr_t>(GetModuleHandle("client.dll"));

	// hack loop
	while (!GetAsyncKeyState(VK_INSERT))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		if (!GetAsyncKeyState(VK_SPACE))
			continue;

		const auto localPlayer = *reinterpret_cast<uintptr_t*>(client + dwLocalPlayer);

		const auto flags = *reinterpret_cast<int32_t*>(localPlayer + m_fFlags);

		(flags & (1 << 0)) ?
			*reinterpret_cast<uintptr_t*>(client + dwForceJump) = 6 :
			*reinterpret_cast<uintptr_t*>(client + dwForceJump) = 4;

		if (NoFlash)
		{
		const auto localPlayer = *reinterpret_cast<uintptr_t*>(client + dwLocalPlayer);
		*reinterpret_cast<float*>(localPlayer + m_flFlashMaxAlpha) = 0.0f;
		}
	}

	while (!GetAsyncKeyState(VK_DELETE))
	{
	FreeLibraryAndExitThread(instance, 0);
	}

}

int __stdcall DllMain(
	const HMODULE instance,
	const std::uintptr_t reason,
	const void* reserved
)
{
	if (reason == 1)
	{
		DisableThreadLibraryCalls(instance);

		const auto thread = CreateThread(
			nullptr,
			0,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(BunnyHop),
			instance,
			0,
			nullptr
		);

		if (thread)
			CloseHandle(thread);
	}

	return 1;
}