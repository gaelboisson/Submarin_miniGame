#include <iostream>
#include <memory>


#include "Level.hpp"


Level::Level(Player &player, RenderWindow &window, Mix_Music *music)
    : player(player),
      window(window)
{

}


Level::~Level()
{
    
}


// Mise à jour du level selon la logique de jeu
void Level::update()
{
    player.update();
}


// Rendu du level
void Level::render()
{
    window.render(player);
}
