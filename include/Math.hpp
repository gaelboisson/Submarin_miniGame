#pragma once


#include <iostream>


struct Vector2f // Structure pour les vecteurs 2D
{
    Vector2f() : x(0.0), y(0.0) {} // Constructeur par défaut


    Vector2f(float p_x, float p_y) : x(p_x), y(p_y) {}


    void print() // On peut définir des méthodes dans le fichier d'en-tête pour les méthodes courtes
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }


    float x;
    float y;
};
