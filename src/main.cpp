#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>



int main(int argc, char* argv[]) {
    // Initialisation de SDL video
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Erreur lors de l'initialisation de SDL video : %s", SDL_GetError());
        return -1;
    }

    // Initialisation de SDL_image
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "Erreur lors de l'initialisation de SDL image : %s" << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Récupération de la taille de l'écran
    SDL_DisplayMode Screen;
    if (SDL_GetCurrentDisplayMode(0, &Screen) != 0) {
        SDL_Log("Erreur lors de la récupération du mode d'affichage : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Calcul de la taille de la fenêtre
    int windowWidth = Screen.w * 0.9;
    int windowHeight = Screen.h * 0.9;

    // Calcul de la position de la fenêtre pour centrer celle-ci sur l'écran
    int windowPosX = (Screen.w - windowWidth) / 2;
    int windowPosY = (Screen.h - windowHeight) / 2;


    // Création de la fenêtre SDL avec la taille et la position calculées
    SDL_Window* fenetre = SDL_CreateWindow("Submarine Mini Game", windowPosX, windowPosY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (!fenetre) {
        SDL_Log("Erreur lors de la création de la fenêtre : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

//------------------------------------------------------------------------------------------

 // Initialisation du chargement d'images avec SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        SDL_Log("Erreur lors de l'initialisation de SDL_image : %s", IMG_GetError());
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return -1;
    }

    // Création du renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Erreur lors de la création du renderer : %s", SDL_GetError());
        SDL_DestroyWindow(fenetre);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    // Chargement de l'image du sprite
    SDL_Texture* submarineTexture = IMG_LoadTexture(renderer, "res/gfx/submarine.png");
    if (!submarineTexture) {
        SDL_Log("Erreur lors du chargement du sprite : %s", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(fenetre);
        IMG_Quit();
        SDL_Quit(); 
        return -1;
    }

    // Définition des nouvelles largeur et hauteur
    int newWidth = 48;
    int newHeight = 32;


    // Redimensionner la texture du sous-marin à la nouvelle taille
    SDL_Rect destinationRect = { 640, 0, newWidth, newHeight };
    
//-----------------------------------------------------------------------------------

    // Boucle principale
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_UP:
                    destinationRect.y -= 10;
                    break;
                case SDLK_DOWN:
                    destinationRect.y += 10;
                    destinationRect.y += 5;
                    break;
                case SDLK_LEFT:
                    destinationRect.x -= 10;
                    destinationRect.y += 5;
                    break;
                case SDLK_RIGHT:
                    destinationRect.x += 10;
                    destinationRect.y += 5;
                    break;
                default:
                    break;
                }
            }
        }

        // Effacer l'écran
        SDL_RenderClear(renderer);

        // Dessiner le sprite dans le coin supérieur gauche (0, 0)
        SDL_RenderCopy(renderer, submarineTexture, NULL, &destinationRect);

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);
    }

    // Libération des ressources et fermeture de SDL

    SDL_DestroyTexture(submarineTexture); // Libérer la texture originale du sous-marin
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}