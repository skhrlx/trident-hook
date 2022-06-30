#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <cstdint>
#include <thread>
#include <iostream>

#include "../sdk/offsets.hpp"
#include "../sdk/data.hpp"
#include "../ext/minhook/MinHook.h"
#include "../sdk/entity.hpp"

using namespace hazedumper::netvars;
using namespace hazedumper::signatures;

void __forceinline PolyMorphic() {
	std::srand(GetTickCount64());
	int x = rand() % 17;
	for (int i = 0; i < x; i++) {

		switch (x) {
		case 0:
			_asm {
				add eax, x
				sub eax, x
			}
		case 1:
			_asm {
				add ecx, x
				sub ecx, x
			}
		case 2:
			_asm {
				inc ecx
				dec ecx
			}
		case 3:
			_asm {
				mov eax, eax
				sub eax, x
				add eax, x
			}

		case 4:
			_asm {
				mov ecx, ecx
				sub ecx, x
				add ecx, x
			}
		case 5:
			_asm {
				sub eax, 1
				inc eax
			}
		case 6:
			_asm {
				xor eax, eax
				mov eax, eax
			}
		case 7:
			_asm {
				pop ecx
				push ecx
			}
		case 8:
			_asm {
				dec eax
				add eax, 1
			}
		case 9:
			_asm {
				nop
				add eax, x
				nop
				sub eax, x
				nop
			}
		case 10:
			_asm {
				nop
				add ecx, x
				nop
				sub ecx, x
				nop
			}
		case 11:
			_asm {
				nop
				inc ecx
				nop
				dec ecx
				nop
			}
		case 12:
			_asm {
				nop
				mov eax, eax
				nop
				sub eax, x
				nop
				add eax, x
				nop
			}

		case 13:
			_asm {
				nop
				mov ecx, ecx
				nop
				sub ecx, x
				nop
				add ecx, x
				nop
			}
		case 14:
			_asm {
				nop
				sub eax, 1
				nop
				inc eax
				nop
			}
		case 15:
			_asm {
				nop
				xor eax, eax
				nop
				mov eax, eax
				nop
			}
		case 16:
			_asm {
				nop
				pop ecx
				nop
				push ecx
				nop
			}
		case 17:
			_asm {
				nop
				dec eax
				nop
				add eax, 1
				nop
			}
		}
	}
}

/*void MainLoop(const HMODULE instance) noexcept
{
	PolyMorphic();
	const auto client = reinterpret_cast<uintptr_t>(GetModuleHandle("client.dll"));
	//PolyMorphic();
	//const auto localPlayer = *reinterpret_cast<uintptr_t*>(client + dwLocalPlayer);
	//PolyMorphic();
	//Entity LocalPlayerEnt = Entity(localPlayer);
	PolyMorphic();
	while (!GetAsyncKeyState(VK_INSERT))
	{
		PolyMorphic();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		PolyMorphic();
		if (Bunnhyhop)
			PolyMorphic();
			if (!GetAsyncKeyState(VK_SPACE))
				continue;
			PolyMorphic();
			const auto localPlayer = *reinterpret_cast<uintptr_t*>(client + dwLocalPlayer);
			PolyMorphic();
			const auto flags = *reinterpret_cast<int32_t*>(localPlayer + m_fFlags);
			PolyMorphic();
			(flags & (1 << 0)) ?
				*reinterpret_cast<uintptr_t*>(client + dwForceJump) = 6 :
				*reinterpret_cast<uintptr_t*>(client + dwForceJump) = 4;
				PolyMorphic();
		if (NoFlash)
		{
			PolyMorphic();
			uint32_t localPlayer = *reinterpret_cast<uint32_t*>(client + dwLocalPlayer);
			Entity LocalPlayerEnt = Entity(localPlayer);
			LocalPlayerEnt.SetFlashAlpha(0.0f);
			PolyMorphic();
		}
		PolyMorphic();
	}
	PolyMorphic();
	while (!GetAsyncKeyState(VK_DELETE))
	{
		PolyMorphic();
		FreeLibraryAndExitThread(instance, 0);
		PolyMorphic();
	}
	PolyMorphic();
}*/

void MainLoop(const HMODULE instance) noexcept
{

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
			reinterpret_cast<LPTHREAD_START_ROUTINE>(MainLoop),
			instance,
			0,
			nullptr
		);

		if (thread)
			CloseHandle(thread);
	}

	return 1;
}