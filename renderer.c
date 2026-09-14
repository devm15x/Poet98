#include <stdio.h>
#include <gl\gl.h>
#include <windows.h>
#include "renderer.h"
float theta;

void draw(buffer) {            
            glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            glRotatef (theta, 0.0f, 1.0f, 0.0f);
            glBegin (GL_TRIANGLES);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (0.0f, 1.0f, -0.5f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (0.87f, -0.5f, 0.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (-0.87f, -0.5f, 0.0f);
            glEnd ();
            glPopMatrix ();

            SwapBuffers (buffer);
            
            theta += 1.0f;
            Sleep (1);
}
