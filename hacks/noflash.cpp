#include "noflash.hpp"

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

void noflash::Run()
{
	Player* localPlayer = Player::GetLocalPlayer();
	localPlayer->SetFlashOpacity(opacity);
}