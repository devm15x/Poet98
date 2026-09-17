#include <windows.h>
#include <math.h>
#include <SDL.h>
#include <stdint.h>
#include "keyboard.h"

void setMovement(float *x, float *y, float *z, float *yaw){
     float radians = -(*yaw) * 3.14159265f / 180.0f;
     Uint8 *keys = SDL_GetKeyState(NULL);
     if(keys[SDLK_w]) {
                              *x += sin(radians) * 0.05f;
                              *z += cos(radians) * 0.05f;
     }
     if(keys[SDLK_s]) {
                              *x -= sin(radians) * 0.05f;
                              *z -= cos(radians) * 0.05f;
     }
     if(keys[SDLK_a]) {
                              *x += cos(radians) * 0.05f;
                              *z -= sin(radians) * 0.05f;
                              }

     if (keys[SDLK_d]) {
                              *x -= cos(radians) * 0.05f;
                              *z += sin(radians) * 0.05f;
     }
}
     
