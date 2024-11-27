#include <iostream>
#include <SDL.h>

int main(int argc, char *args[]) {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int BOX_WIDTH = 50;
    const int BOX_HEIGHT = 50;
    const int MOVE_SPEED = 10;
    int r;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Move the Box", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
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

    // Initial box position
    int boxX = (SCREEN_WIDTH - BOX_WIDTH) / 2;
    int boxY = (SCREEN_HEIGHT - BOX_HEIGHT) / 2;

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        boxX -= MOVE_SPEED;
                        if (boxX < 0) boxX = 0;
                        break;
                    case SDLK_RIGHT:
                        boxX += MOVE_SPEED;
                        r++;
                        if (boxX > SCREEN_WIDTH - BOX_WIDTH) boxX = SCREEN_WIDTH - BOX_WIDTH;
                        break;
                }
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);


        SDL_Rect box = {boxX, boxY, BOX_WIDTH, BOX_HEIGHT};
        SDL_SetRenderDrawColor(renderer, r, 255, 255, 255); // White box
        SDL_RenderDrawRect(renderer, &box);

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
