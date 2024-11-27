//
// Created by Ryan on 11/27/2024.
//k

#include <SDL.h>
#ifndef TRY_BALL_H
#define TRY_BALL_H


class ball {
public:
    SDL_Rect fin;
    int width = 10;
    int length = 10;
    double x_velo = 0;
    double y_velo = 1;

    void init(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &fin);
    }

    ball(int x, int y, int w, int h) {
        fin = {x, y, w, h};
    }

    ball(){
        width = 10;
        length = 10;
        x_velo = 0;
        y_velo = 0;
    };

};


#endif