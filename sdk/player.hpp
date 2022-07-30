#pragma once
#include "entity.hpp"

class Player : public Entity
{
public:
    static Player* GetLocalPlayer();

    int GetHealth();

    int GetTeam();

    int GetShotsFired();

    int GetCrosshairID();

    uintptr_t GetFlags();

    uintptr_t GetHitsOnServer();

    void SetFOV(int fov);

    void SetFlashOpacity(float opacity);

    bool isScoped();
};