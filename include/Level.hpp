#pragma once

#include <vector>
#include <SDL2/SDL_mixer.h>
#include <memory>

#include "Render_Window.hpp"
#include "Player.hpp"


class Level
{
public:
    Level(Player &player, RenderWindow &window, Mix_Music* music); // Constructeur
    ~Level(); // Destructeur
    void update(); // Le level peut être mis à jour
    void render(); // Le level peut être rendu


private:
    Player &player;
    RenderWindow &window;
    Mix_Music* music;
};
