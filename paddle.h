//
// Created by Ryan on 11/26/2024.
//

#include <SDL.h>

#ifndef TRY_PADDLE_H
#define TRY_PADDLE_H


class paddle {
public:

    int length;
    int width;
    int pos;
    int Velo = 0;
    enum dir {
        RIGHT,
        LEFT
    };

    void move(SDL_Event e, SDL_Renderer *renderer);
    SDL_Rect init(SDL_Renderer *renderer);


    paddle(int startX, int startY) : pos(startX), width(100), length(10) {
        box = {startX, startY, width, length};
    }


    SDL_Rect box = {};


};


#endif //TRY_PADDLE_H
