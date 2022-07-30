#include "modules.hpp"
#include "entity.hpp"
#include "offsets.hpp"

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

Entity* Entity::GetByIndex(int index)
{
    return *reinterpret_cast<Entity**>(modules::client + dwEntityList + sizeof(EntInfo) * index);
}

std::vector<Entity*> Entity::GetAll()
{
    std::vector<Entity*> allEntities;
    for (EntInfo* entInfo = reinterpret_cast<EntInfo*>(modules::client + dwEntityList); entInfo; entInfo = entInfo->m_pNext)
    {
        if (entInfo->m_pEntity == nullptr)
        {
            continue;
        }

        allEntities.push_back(entInfo->m_pEntity);

        if (entInfo->m_pNext == nullptr || entInfo->m_pNext == entInfo->m_pPrev)
        {
            break;
        }
    }
    return allEntities;
}

bool Entity::IsDormant()
{
    return ReadValue<bool>(m_bDormant);
}