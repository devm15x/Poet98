#ifndef OBJ_H
#define OBJ_H

#include "mtl.h"

typedef struct {
    float x;
    float y;
    float z;
} Vertex;

typedef struct {
    int v1;
    int v2;
    int v3;
    int material;
} Face;

typedef struct {
    Vertex *vertices;
    Face *faces;
    Material *mtl;
    int vertexCount;
    int faceCount;
    int modelCount;
} Model;

Model loadObj(char *filename);
void drawModel(Model *model);

#endif
