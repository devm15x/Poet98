#ifndef RENDERER_H
#define RENDERER_H
#include <windows.h>
#include<stdio.h>
#include<gl\gl.h>
void draw(HDC buffer, float x, float y , float z, float pitch, float yaw);
void init();
#endif
