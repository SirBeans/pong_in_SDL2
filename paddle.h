//
// Created by Ryan on 11/26/2024.
//

#include <SDL.h>

#ifndef TRY_PADDLE_H
#define TRY_PADDLE_H


class paddle {

    enum dir {
        RIGHT,
        LEFT
    };



    int length;
    int width;

public:
    int pos;

    void move(SDL_Event * e, dir f);
    SDL_Rect init(SDL_Renderer *renderer);

public:
    paddle(int x, int y) {
        length = x;
        width = y;
    }

    paddle() {
        length = 100;
        width = 10;
    }


};


#endif //TRY_PADDLE_H
