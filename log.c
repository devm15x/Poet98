#include <stdio.h>
#include "log.h"
#include <stdarg.h>

void log(const char *format, ...) {
     FILE *logfile = fopen("poet.log", "a");
     if (logfile == NULL) {
          return;
     }


     va_list args;
     va_start(args, format);


     vfprintf(logfile, format, args);
     va_end(args);

     fclose(logfile);
}
void initLog() {
     FILE * initFile;
     initFile = fopen("poet.log", "w");
     if (initFile == NULL) {
                  return;
     }
     fclose(initFile);
     log("Poet Engine for Windows v0.1 \n");
}
