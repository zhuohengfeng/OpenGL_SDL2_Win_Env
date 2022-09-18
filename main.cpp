#include <iostream>

extern "C" {
#include <SDL2/SDL.h>
}

using namespace std;

#undef main
int main(int argc, char *argv[])
{
    std::cout << "Hello, SDL! 2" << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("3D Game",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          800, 600, SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == nullptr) {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* image = SDL_LoadBMP("../resource/123.bmp");
    if (image == nullptr) {
        cerr << "SDL load bmp failed"<<endl;
        return -1;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);


    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                cout << "Window quited." << endl;
                break;
            }
        }
        SDL_Rect rect = {0, 0, 800, 600};
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}