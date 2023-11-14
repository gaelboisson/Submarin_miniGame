#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Erreur lors de l'initialisation de SDL : %s", SDL_GetError());
        return -1;
    }

    // Récupération de la taille de l'écran
    SDL_DisplayMode Screen;
    if (SDL_GetCurrentDisplayMode(0, &Screen) != 0) {
        SDL_Log("Erreur lors de la récupération du mode d'affichage : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Création de la fenêtre SDL
    SDL_Window* fenetre = SDL_CreateWindow("Ma fenêtre SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Screen.w, Screen.h, SDL_WINDOW_SHOWN);
    if (!fenetre) {
        SDL_Log("Erreur lors de la création de la fenêtre : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Boucle principale
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Dessiner ici...
    }

    // Libération des ressources et fermeture de SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}
