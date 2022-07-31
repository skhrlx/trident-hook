#pragma once
#include "entity.hpp"

class Player : public Entity
{
public:
    static Player* GetLocalPlayer();

    int GetCrosshairID();

    uintptr_t GetFlags();

    uintptr_t GetHitsOnServer();

    int GetTeam();

    void SetFOV(int fov);

    void SetFlashOpacity(float opacity);

};