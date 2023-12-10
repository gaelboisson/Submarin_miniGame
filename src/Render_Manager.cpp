#include "render_manager.hpp"
#include "render_window.hpp"


RenderManager::RenderManager(RenderWindow &window, Level &level) : window(window), level(level) {}


void RenderManager::render()
{
    window.clear();
    level.render();
    window.display();
}
