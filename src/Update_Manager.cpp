#include "../include/Update_Manager.hpp"
#include "event_manager.hpp"
#include "entity.hpp"


UpdateManager::UpdateManager(EventManager &eventManager, Level &level) : eventManager(eventManager), level(level) {}


void UpdateManager::update()
{
    level.update();
}
