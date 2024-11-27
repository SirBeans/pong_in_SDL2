//
// Created by Ryan on 11/26/2024.
//

#include "paddle.h"

SDL_Rect paddle::init (SDL_Renderer * renderer){

    SDL_Rect box = {100, 100, width, length};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White box
    SDL_RenderDrawRect(renderer, &box);

    return box;
}

void paddle::move(SDL_Event *e, dir f) {

    switch (f) {
        case RIGHT:
            pos++;
            break;
        case LEFT:
            pos--;
            break;
        default:
            break;
    }
    
}