#include "../include/Entity.hpp"
#include "../include/Math.hpp"

Entity::Entity(Vector2f player_pos, SDL_Texture* player_texture, int width, int height)
    : player_pos(player_pos), texture(player_texture)
{
    currentFrame.x = 640;
    currentFrame.y = 0;
    currentFrame.w = 48;
    currentFrame.h = 32;
}

SDL_Texture* Entity::getTexture()
{
    return texture;
}
SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}