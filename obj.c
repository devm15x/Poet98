#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <GL/gl.h>

#include "obj.h"
#include "mtl.h"
#include "log.h"

Model loadObj(char *filename)
{
    Model model;
    MaterialLibrary materials;

    FILE *file;
    char line[256];
    char materialName[64];
    char mtlFilename[256];

    int vertexIndex;
    int faceIndex;
    int currentMaterial;
    int i;

    model.vertices = NULL;
    model.faces = NULL;
    model.mtl = NULL;
    model.vertexCount = 0;
    model.faceCount = 0;
    model.modelCount = 0;

    strcpy(mtlFilename, filename);
    strcat(mtlFilename, ".mtl");

    materials = loadMtl(mtlFilename);

    model.mtl = materials.mtl;
    model.modelCount = materials.mtlCount;

    file = fopen(filename, "r");

    if (file == NULL) {
        log("Failed to open OBJ: %s\n", filename);
        return model;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == 'v' && line[1] == ' ') {
            model.vertexCount++;
        }

        if (line[0] == 'f' && line[1] == ' ') {
            model.faceCount++;
        }
    }

    log("Vertices: %d\n", model.vertexCount);
    log("Faces: %d\n", model.faceCount);

    model.vertices = (Vertex *)malloc(
        sizeof(Vertex) * model.vertexCount
    );

    model.faces = (Face *)malloc(
        sizeof(Face) * model.faceCount
    );

    if (model.vertices == NULL || model.faces == NULL) {
        log("Failed to allocate memory for OBJ\n");

        if (model.vertices != NULL) {
            free(model.vertices);
        }

        if (model.faces != NULL) {
            free(model.faces);
        }

        model.vertices = NULL;
        model.faces = NULL;
        model.vertexCount = 0;
        model.faceCount = 0;

        fclose(file);
        return model;
    }

    log(
        "Allocated %d bytes of memory to vertices\n",
        sizeof(Vertex) * model.vertexCount
    );

    log(
        "Allocated %d bytes of memory to faces\n",
        sizeof(Face) * model.faceCount
    );

    rewind(file);

    vertexIndex = 0;
    faceIndex = 0;
    currentMaterial = -1;

    while (fgets(line, sizeof(line), file) != NULL) {

        if (line[0] == 'v' && line[1] == ' ') {
            sscanf(
                line,
                "v %f %f %f",
                &model.vertices[vertexIndex].x,
                &model.vertices[vertexIndex].y,
                &model.vertices[vertexIndex].z
            );

            vertexIndex++;
        }

        if (strncmp(line, "usemtl ", 7) == 0) {
            sscanf(line, "usemtl %63s", materialName);

            for (i = 0; i < model.modelCount; i++) {
                if (strcmp(materialName, model.mtl[i].name) == 0) {
                    currentMaterial = i;
                    break;
                }
            }
        }

        if (line[0] == 'f' && line[1] == ' ') {
            sscanf(
                line,
                "f %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d",
                &model.faces[faceIndex].v1,
                &model.faces[faceIndex].v2,
                &model.faces[faceIndex].v3
            );

            model.faces[faceIndex].material = currentMaterial;

            faceIndex++;
        }
    }

    fclose(file);

    return model;
}

void drawModel(Model *model)
{
    int i;

    glBegin(GL_TRIANGLES);

    for (i = 0; i < model->faceCount; i++) {
        int material;

        material = model->faces[i].material;

        if (material >= 0 && material < model->modelCount) {
            glColor3f(
                model->mtl[material].r,
                model->mtl[material].g,
                model->mtl[material].b
            );
        } else {
            glColor3f(1.0f, 0.0f, 1.0f);
        }

        glVertex3f(
            model->vertices[model->faces[i].v1 - 1].x,
            model->vertices[model->faces[i].v1 - 1].y,
            model->vertices[model->faces[i].v1 - 1].z
        );

        glVertex3f(
            model->vertices[model->faces[i].v2 - 1].x,
            model->vertices[model->faces[i].v2 - 1].y,
            model->vertices[model->faces[i].v2 - 1].z
        );

        glVertex3f(
            model->vertices[model->faces[i].v3 - 1].x,
            model->vertices[model->faces[i].v3 - 1].y,
            model->vertices[model->faces[i].v3 - 1].z
        );
    }

    glEnd();
}
