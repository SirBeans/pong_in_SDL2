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
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                Velo = -20;
                break;
            case SDLK_RIGHT:
                Velo = 20;
                break;
        }
    } else if (e.type == SDL_KEYUP) {
        if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_RIGHT) {
            Velo = 0; // Stop moving
        }
    }

    box.x += Velo;


    if (box.x < 0) {
        box.x = 0;
    } else if (box.x + box.w > 640) {
        box.x = 640 - box.w;
    }

}
void paddle::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &box);
}