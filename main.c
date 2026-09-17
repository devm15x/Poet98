/**************************
 * Includes
 *
 **************************/

#include <SDL.h>
#include <gl/gl.h>
#include "renderer.h"
#include "keyboard.h"
#include "mouse.h"
#include "log.h"
float x = 0.0f;
float y = 0.0f;
float z = -3.0f;
float yaw = 0.0f;
float pitch = 0.0f;

/**************************
 * WinMain
 *
 **************************/

int main(int argc, char *argv[])
{
    BOOL bQuit = FALSE;
    SDL_Event event;
    float theta = 0.0f;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

    SDL_SetVideoMode(800, 600, 24, SDL_OPENGL);

    SDL_WM_SetCaption("Poet Engine for Windows", NULL);
    SDL_ShowCursor(SDL_DISABLE);
    init();
/* program main loop */
while (!bQuit)
{
    /* handle SDL events */
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            bQuit = 1;
        }

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                bQuit = 1;
            }
        }
    }

    /* game logic */
    setMovement(&x, &y, &z, &pitch);
    setMouseLook(&yaw, &pitch);
    draw(x, y, z, yaw, pitch);
}

SDL_Quit();
return 0;
}


/********************
 * Window Procedure
 *
 ********************/



