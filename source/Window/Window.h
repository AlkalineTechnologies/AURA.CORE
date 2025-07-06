#include <AURA.h>
#include <SDL.h>

namespace AURACORE {
    
    class Window {
        private:
            SDL_Window* window = nullptr;
            SDL_GLContext glContext = nullptr;
            int width = 0;
            int height = 0;

        public:
            AURA_API Window(const char* title, int width, int height);
            AURA_API ~Window();

            AURA_API void PollEvents();
            AURA_API bool ShouldClose() const;
            AURA_API void SwapBuffers();

            AURA_API int GetWidth() const;
            AURA_API int GetHeight() const;
            AURA_API void SetTitle(const char* title);
    };
}