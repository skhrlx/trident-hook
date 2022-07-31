#include "triggerbot.hpp"

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

void triggerbot::Shoot()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    Sleep(1);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void triggerbot::Run()
{
	Player* localPlayer = Player::GetLocalPlayer();

    int crosshairID = localPlayer->GetCrosshairID();
    if (crosshairID != 0) {

        Entity* target = Entity::GetByIndex(crosshairID - 1);
        if (target->GetClientClass()->m_ClassID == ClassID::CCSPlayer && localPlayer->GetTeam() != target->Cast<Player*>()->GetTeam())
        {
            triggerbot::Shoot();
        }
    }
}