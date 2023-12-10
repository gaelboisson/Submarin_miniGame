#include "../include/Entity.hpp"
#include "../include/Player.hpp"
#include "../include/Event_Manager.hpp"
#include "../include/Math.hpp"


Player::Player(Vector2f player_pos, SDL_Texture *player_texture, int width, int height, EventManager &EventManager)
    : Entity(player_pos, player_texture, width, height) {}


void Player::update()
{
    applyGravity(1.0);
}


void Player::applyGravity(float gravity)
{
    // move(0, gravity);
}


// création des fichier * sauf main.cpp