#include "fovchanger.hpp"

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

void fovchanger::Run()
{
	Player* localPlayer = Player::GetLocalPlayer();
	localPlayer->SetFOV(fov);
}