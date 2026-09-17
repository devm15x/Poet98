#ifndef MTL_H
#define MTL_H

typedef struct {
    char name[64];
    float r;
    float g;
    float b;
} Material;

typedef struct {
    Material *mtl;
    int mtlCount;
} MaterialLibrary;

MaterialLibrary loadMtl(char *filename);

#endif
