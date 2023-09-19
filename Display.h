//
// Created by Thalisson Melo on 17/09/23.
//

#ifndef CHIP8_DISPLAY_H
#define CHIP8_DISPLAY_H

#include <cstdint>
#include <SDL.h>


class Display {
    friend class Imgui;

public:
    Display(const char* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight);
    ~Display();

    void Update(void const *buffer, int pitch);
    static bool ProcessInput(uint8_t* keys);

private:
    SDL_Window* window{};
    SDL_Renderer* renderer{};
    SDL_Texture* texture{};

};


#endif //CHIP8_DISPLAY_H
