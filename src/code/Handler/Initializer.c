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
    FILE *file;
    char line[100]; // Buffer to hold lines from the file
    int totalSinger;
    int totalAlbum;
    char bandName[50]; // Adjust size as needed

    // Open the file in read mode
    file = fopen("data/default.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the first line to get totalSinger
    if (fgets(line, sizeof(line), file) != NULL) {
        // Parse the totalSinger value
        if (sscanf(line, "%d", &totalSinger) != 1) {
            printf("Error parsing totalSinger.\n");
            fclose(file);
            return 1;
        }
    } else {
        printf("Error reading from file.\n");
        fclose(file);
        return 1;
    }

    // Read the second line to get totalAlbum and bandName
    printf("Total Singers: %d\n", totalSinger);
    while(totalSinger--){
        if (fgets(line, sizeof(line), file) != NULL) {
            // Parse the totalAlbum and bandName values
            if (sscanf(line, "%d %49s", &totalAlbum, bandName) != 2) {
                printf("Error parsing totalAlbum and bandName.\n");
                fclose(file);
                return 1;
            }
        } else {
            printf("Error reading from file.\n");
            fclose(file);
            return 1;
        }
        // Print the results
        printf("Total Albums: %d\n", totalAlbum);
        printf("Band Name: %s\n", bandName);
    }


    fclose(file);
    return 0;
}

