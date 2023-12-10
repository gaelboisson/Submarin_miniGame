#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"


class Entity
{
public:
    Entity(Vector2f player_pos, SDL_Texture* player_texture, int width, int height);
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
    Vector2f getPos(){
        return player_pos;
    };

private:
    SDL_Rect currentFrame;
    SDL_Texture* texture;
    Vector2f player_pos;
    int width;
    int height;
};
