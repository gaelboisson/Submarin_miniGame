#include "Event_Manager.hpp"


void EventManager::processEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gameRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_z:
                moveUp = true;
                break;
            case SDLK_q:
                moveLeft = true;
                break;
            case SDLK_s:
                moveDown = true;
                break;
            case SDLK_d:
                moveRight = true;
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_z:
                moveUp = false;
                break;
            case SDLK_q:
                moveLeft = false;
                break;
            case SDLK_s:
                moveDown = false;
                break;
            case SDLK_d:
                moveRight = false;
                break;
            }
            break;
        }
    }
}
