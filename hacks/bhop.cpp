#include "bhop.hpp"

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

void bhop::ForceJump()
{
	auto* forceJump = reinterpret_cast<int*>(modules::client + dwForceJump);
	*forceJump = 6;
}

void bhop::Run()
{
	Player* localPlayer = Player::GetLocalPlayer();
	uintptr_t flags = localPlayer->GetFlags();
	if (flags & (1 << 0))
	{
		bhop::ForceJump();
	}
}
