#include "../../header/Handler/initializer.h"
#include <ctype.h>

#define MAX_LINE_LENGTH 100

void trim(char *str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}


void initializer(App *app) {
    FILE *file = fopen("default.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file default.txt.\n");
        exit(EXIT_FAILURE);
    }

    initializeSingers(&(app->singers));
    initializePlaylists(&(app->playlists));
    initializeQueue(&(app->queue));
    initializeQueue(&(app->history));
    createEmptySong(&(app->currSong));

    char line[MAX_LINE_LENGTH];
    char *token;

    int numSingers;
    fscanf(file, "%d", &numSingers);
    fgets(line, MAX_LINE_LENGTH, file); // read the rest of the line



    fclose(file);
}

