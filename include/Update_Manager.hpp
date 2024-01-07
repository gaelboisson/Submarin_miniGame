#pragma once


#include "event_manager.hpp"
#include "Level.hpp"


class UpdateManager
{
public:
    UpdateManager(EventManager &eventManager, Level &level);
    void update();


private:
    EventManager &eventManager;
    Level &level;
};
