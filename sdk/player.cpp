#include "player.hpp"
#include "modules.hpp"
#include "offsets.hpp"
#include "data.hpp"

using namespace hazedumper::netvars;
using namespace hazedumper::signatures;

Player* Player::GetLocalPlayer()
{
    return *reinterpret_cast<Player**>(modules::client + dwLocalPlayer);
}

void Player::SetFOV(int fov)
{
    return WriteValue<int>(m_iFOV, fov);
}

void Player::SetFlashOpacity(float opacity)
{
    return WriteValue<float>(m_flFlashMaxAlpha, opacity);
}

uintptr_t Player::GetFlags()
{
    uintptr_t flags = ReadValue<uintptr_t>(m_fFlags);
    return flags;
}

