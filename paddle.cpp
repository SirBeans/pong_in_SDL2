//
// Created by Ryan on 11/26/2024.
//

#include "paddle.h"

SDL_Rect paddle::init (SDL_Renderer * renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &box);
    SDL_RenderPresent(renderer);

    return box;
}

void paddle::move(SDL_Event e, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    switch (e.type) {
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                    Velo = (Velo > 0) ? -1 : Velo - 3;
                    if (Velo < -20) Velo = -20;
                    break;
                case SDLK_RIGHT:
                    Velo = (Velo < 0) ? 1 : Velo + 3;
                    if (Velo > 20) Velo = 20;
                    break;
                default:
                    break;
            }
            break;

        case SDL_KEYUP:
            switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    Velo = 0;
                    break;
                default:
                    break;
            }
            break;

        default:
            break;
    }

    box.x += Velo;
    if (box.x < 0) {
        box.x = 0;
    } else if (box.x + box.w > 640) {
        box.x = 640 - box.w;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White paddle
    SDL_RenderFillRect(renderer, &box);                   // Draw updated paddle
    SDL_RenderPresent(renderer);

}