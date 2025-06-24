#include <AURA.h>
#include <SDL.h>
#include <SDL_version.h>
#include <ImGui/imgui.h>
#include <GLEW/GL/glew.h>

#include <cstdio>

void AURACORE::About() {
    // Display information about the AURA Engine
    SDL_version Version;
    SDL_GetVersion(&Version);

    printf("AURA %s\n", AURA_VERSION);
    printf("Dependencies:\n");
    printf("\tImGui %s\n", IMGUI_VERSION);
    printf("\tSDL: %d.%d.%d\n", Version.major, Version.minor, Version.patch);
    printf("\tGLEW: %s\n", glewGetString(GLEW_VERSION));
}
