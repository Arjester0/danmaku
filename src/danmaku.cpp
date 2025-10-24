#include <raylib.h> 
#include <stdio.h>
#include <math.h>
// #include <kissfft.h> 

/* TODO: 
 * [X] convert to raylib 
 * [ ] Take the data from the audio stream and put it into fft
 * [ ] Make danmaku patterns with functions based off data from fft
 * [ ] Render danmaku patterns on screen based off function results 
 */ 

void danmaku_patterns(); 
void fft(); 

void draw_danmaku() {
// sprite/circle,
// Archimedean Spiral: r = a + b(theta) 
// \(x(t)=t\cos (t)\) \(y(t)=t\sin (t)\) for parameters 
} 

void callback(void *buffer, unsigned int frames) {
    
} 


int main(int argc, char* args[]) {
    const int screenWidth = 400;
    const int screenHeight = 400; 

    Music test = LoadMusicStream("assets/connertheme.mp3"); 
    PlayMusicStream(test); 

    InitWindow(screenWidth, screenHeight, "danmaku"); 

    SetTargetFPS(60); 

    while(!WindowShouldClose()) {
	UpdateMusicStream(test); 

	if (IsKeyPressed(KEY_SPACE)) {
	    if (IsMusicStreamPlaying(test)) {
		PauseMusicStream(test);
	    } else {
		ResumeMusicStream(test); 
	    } 
	}

	BeginDrawing();
	    ClearBackground(RAYWHITE); 
	    DrawText("Danmaku", 10, 10, 20, DARKGRAY); 

	    // draw danmaku function
	    draw_danmaku(); 

	EndDrawing(); 
    } 
    
    UnloadMusicStream(test); 
    CloseAudioDevice(); 

    CloseWindow(); 

    return 0;
}

