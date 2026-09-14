#include <windows.h>
#include <math.h>
#include "keyboard.h"

void setMovement(float *x, float *y, float *z, float *yaw){
     float radians = -(*yaw) * 3.14159265f / 180.0f;
     
     if(GetAsyncKeyState('W') & 0x8000) {
                              *x += sin(radians) * 0.05f;
                              *z += cos(radians) * 0.05f;
     }
     if(GetAsyncKeyState('S') & 0x8000) {
                              *x -= sin(radians) * 0.05f;
                              *z -= cos(radians) * 0.05f;
     }
     if(GetAsyncKeyState('A') & 0x8000) {
                              *x += cos(radians) * 0.05f;
                              *z -= sin(radians) * 0.05f;
                              }

     if(GetAsyncKeyState('D') & 0x8000) {
                              *x -= cos(radians) * 0.05f;
                              *z += sin(radians) * 0.05f;
     }
}
     
