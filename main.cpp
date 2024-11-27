#include <iostream>
#include <SDL.h>
#include "paddle.h"
#include "ball.cpp"

void handleBallCollision(ball &ball, paddle &paddle, SDL_Renderer *renderer);

int main(int argc, char *args[]) {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }



    paddle player((SCREEN_WIDTH - 10) / 2, SCREEN_HEIGHT - 30); // Bottom-center, Pong-style paddle
    player.init(renderer);

    ball gameBall((SCREEN_WIDTH - 10) / 2, (SCREEN_HEIGHT - 10) / 2, 10, 10);
    gameBall.init(renderer);

    bool quit = false;
    SDL_Event e;



    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
               player.move(e, renderer);
            }
        }

        handleBallCollision(gameBall, player, renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &gameBall.fin);

        player.draw(renderer);

        SDL_RenderPresent(renderer);

    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void handleBallCollision(ball &ball, paddle &paddle, SDL_Renderer *renderer) {
    if (ball.fin.y <= 0) {
        ball.y_velo = -ball.y_velo;
    }

    if (ball.fin.y + ball.length >= paddle.box.y &&
        ball.fin.y <= paddle.box.y &&
        ball.fin.x + ball.width >= paddle.box.x &&
        ball.fin.x <= paddle.box.x + paddle.width) {
        ball.y_velo = -ball.y_velo;
        ball.x_velo = (paddle.Velo) / 20;
    }
        if (ball.fin.x <= 0 || ball.fin.x + ball.width >= 640) {
            ball.x_velo = -1 * ball.x_velo;
        }
    if (ball.fin.y + ball.length >= 480) {
        ball.fin.y = 480 - ball.length;
        ball.y_velo = 0;
        ball.x_velo = 0;
    }

        ball.fin.x += ball.x_velo;
        ball.fin.y += ball.y_velo;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }