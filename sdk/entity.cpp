#include "entity.hpp"
#include "../sdk/offsets.hpp"

using namespace hazedumper::netvars;
using namespace hazedumper::signatures;

void Entity::SetFlashAlpha(float num)
{
    const auto localPlayer = *reinterpret_cast<uintptr_t*>(client + dwLocalPlayer);
    *reinterpret_cast<float*>(localPlayer + m_flFlashMaxAlpha) = 0.0f;
}








Entity::Entity(uint32_t EntityAddress)
{
    this->EntityAddress = EntityAddress;
}

Entity::Entity()
{
}

Entity::~Entity()
{

}