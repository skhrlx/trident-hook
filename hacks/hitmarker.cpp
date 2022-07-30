#include "hitmarker.hpp"

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

void hitmarker::Sound()
{
	Beep(850, 50);
}

void hitmarker::Run()
{
	Player* localPlayer = Player::GetLocalPlayer();
	uintptr_t hits = localPlayer->GetHitsOnServer();
	if (hits > 1)
	{
		hitmarker::Sound();
	}
}
