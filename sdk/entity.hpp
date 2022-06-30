#pragma once
#include <cstdint>
#include "data.hpp"

class Entity
{
private:
    uint32_t EntityAddress = 0;
public:

    uint32_t GetEntityAddress();
    uint32_t GetGlowIndex();
    uint16_t GetCurrentWeaponID();
    uint16_t GetWeaponIndex();
    uint16_t getCrosshairId();
    uint16_t getShotsFired();
    uint8_t getHealth();
    uint8_t getForceAttack();
    uint8_t getTeam();
    void setTotalHitsOnServer(int num);
    int getTotalHitsOnServer();
    void SetFlashAlpha(float num);
    void SetForceJump(uint8_t value);
    void setForceAttack(uint8_t value);
    void setForceAttack2(uint8_t value);
    void shoot();

    bool IsDormant();
    bool IsDefusing();
    bool isInAir();
    bool isValidPlayer();
    bool IsCrouching();
    Entity();
    Entity(uint32_t EntityAddress);
    ~Entity();
};
