#include <SDL.h>

void setMouseLook(float *yaw, float *pitch)
{
    int mouseX;
    int mouseY;

    SDL_GetRelativeMouseState(&mouseX, &mouseY);

    *pitch += mouseX * 0.15f;
    *yaw   += mouseY * 0.15f;

    if (*yaw > 89.0f)
        *yaw = 89.0f;

    if (*yaw < -89.0f)
        *yaw = -89.0f;
}
