#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mtl.h"
#include "log.h"

MaterialLibrary loadMtl(char *filename)
{
    MaterialLibrary mtlmodel;
    FILE *file;
    char lineMtl[256];
    int mtlIndex;

    mtlmodel.mtl = NULL;
    mtlmodel.mtlCount = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        log("Failed to open MTL: %s\n", filename);
        return mtlmodel;
    }

    while (fgets(lineMtl, sizeof(lineMtl), file) != NULL) {
        if (strncmp(lineMtl, "newmtl ", 7) == 0) {
            mtlmodel.mtlCount++;
        }
    }

    log("Materials: %d\n", mtlmodel.mtlCount);

    if (mtlmodel.mtlCount > 0) {
        mtlmodel.mtl = (Material *)malloc(
            sizeof(Material) * mtlmodel.mtlCount
        );

        if (mtlmodel.mtl == NULL) {
            log("Failed to allocate memory for materials\n");
            fclose(file);
            mtlmodel.mtlCount = 0;
            return mtlmodel;
        }
    }

    rewind(file);

    mtlIndex = 0;

    while (fgets(lineMtl, sizeof(lineMtl), file) != NULL) {
        if (strncmp(lineMtl, "newmtl ", 7) == 0) {
            sscanf(
                lineMtl,
                "newmtl %63s",
                mtlmodel.mtl[mtlIndex].name
            );

            mtlmodel.mtl[mtlIndex].r = 1.0f;
            mtlmodel.mtl[mtlIndex].g = 1.0f;
            mtlmodel.mtl[mtlIndex].b = 1.0f;

            mtlIndex++;
        }

        if (
            lineMtl[0] == 'K' &&
            lineMtl[1] == 'd' &&
            lineMtl[2] == ' '
        ) {
            sscanf(
                lineMtl,
                "Kd %f %f %f",
                &mtlmodel.mtl[mtlIndex - 1].r,
                &mtlmodel.mtl[mtlIndex - 1].g,
                &mtlmodel.mtl[mtlIndex - 1].b
            );
        }
    }

    fclose(file);

    return mtlmodel;
}
