#include <Window/Window.h>
#include <cstdio>

AURACORE::Window::Window(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: Failed to initialize SDL: %s\n", SDL_GetError());
        return;
    }
    window = SDL_CreateWindow(
        title,
         SDL_WINDOWPOS_CENTERED,
         SDL_WINDOWPOS_CENTERED, 
         width, height, 
         SDL_WINDOW_OPENGL);
    
    if (!window) {
        printf("Error: Failed to create window: %s\n", SDL_GetError());
        return;
    }

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        printf("Error: Failed to create OpenGL context: %s\n", SDL_GetError());
        return;
    }

    if (SDL_GL_SetSwapInterval(1) < 0) {
        printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
    }

    this->width = width;
    this->height = height;
}


