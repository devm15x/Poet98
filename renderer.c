#include <stdio.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <windows.h>
#include "renderer.h"
float theta;
void project(){
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     gluPerspective(
                   60.0,          /* field of view */
                   800.0 / 600.0, /* aspect ratio */
                   0.1,           /* near clipping plane */
                   100.0           /* far clipping plane */    
     );

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
}
void init() {
     project();
     glEnable(GL_DEPTH_TEST);
     }
     
void draw(HDC buffer) {      
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            glTranslatef(0.0f, 0.0f, -3.0f);     
            glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glPushMatrix ();
            glRotatef(theta, 1.0f, 0.0f, 0.0f);
            glRotatef(theta, 0.0f, 1.0f, 0.0f);
            glBegin (GL_TRIANGLES);
            
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, 1.0f);

            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, -1.0f);

            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, 1.0f);

            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, -1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, -1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, -1.0f);

            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (-1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (1.0f, 1.0f, -1.0f);

            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (-1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (-1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (-1.0f, -1.0f, -1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glEnd ();
            glPopMatrix ();

            SwapBuffers (buffer);
            
            theta += 1.0f;
            Sleep (1);
}
