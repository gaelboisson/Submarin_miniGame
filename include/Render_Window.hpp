#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "Entity.hpp"


class RenderWindow
{
public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();
    void clear();
    void render(Entity& p_entity);
    void display();


private:
    SDL_Window* window{nullptr}; 
    SDL_Renderer* renderer{nullptr}; 
};
