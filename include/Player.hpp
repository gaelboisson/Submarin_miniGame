#pragma once


#include "Entity.hpp"
#include "Event_Manager.hpp"


class Player : public Entity
{
public:
    Player(Vector2f player_pos, SDL_Texture *player_texture, int width, int height, EventManager &EventManager);
    void update();
    void applyGravity(float gravity);


private:
    // EventManager &eventManager;
    // float speed {player_speed};  // Vitesse de déplacement du joueur
};
