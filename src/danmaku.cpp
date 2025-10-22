#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h> 
#include <stdio.h>
#include <math.h>
// #include <kissfft.h> 

/* TODO: 
 * [ ] Take the data from the audio stream and put it into fft
 * [ ] Make danmaku patterns with functions based off data from fft
 * [ ] Render danmaku patterns on screen based off function results 
 */ 

void danmaku_patterns(); 
void fft(); 

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
    SDL_Window* window = SDL_CreateWindow( "Danmaku", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *music = Mix_LoadMUS("connertheme.mp3");
    if (!music) {
        printf("Mixer error: %s\n", Mix_GetError());
        return 1;
    }
    
    while (true) {
        SDL_Event e;
	Mix_PlayMusic(music, 0);
        if (SDL_WaitEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }
    }

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

