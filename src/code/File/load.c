#include "../../header/File/load.h"

#define MAX_LINE_LENGTH 100
#define MAX_SONGS_PER_ALBUM 20

void trim(char *str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}

void loadFile(App *app, const char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH]; // Buffer to hold lines from the file
    int totalSinger;
    int totalAlbum;
    char bandName[MAX_LINE_LENGTH]; // Adjust size as needed

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the first line to get totalSinger
    if (fgets(line, sizeof(line), file) != NULL) {
        // Parse the totalSinger value
        if (sscanf(line, "%d", &totalSinger) != 1) {
            printf("Error parsing totalSinger.\n");
            fclose(file);
            return;
        }
    } else {
        printf("Error reading from file.\n");
        fclose(file);
        return;
    }

    initializeSingers(&(app->singers));
    initializePlaylists(&(app->playlists));

    int singerIndex;
    while (totalSinger--) {
        if (fgets(line, sizeof(line), file) != NULL) {
            trim(line);
            if (sscanf(line, "%d %[^\n]", &totalAlbum, bandName) != 2) {
                printf("Error parsing totalAlbum and bandName.\n");
                fclose(file);
                return;
            }

            addSinger(&(app->singers), bandName, totalAlbum);
            singerIndex = app->singers.numSingers - 1;

        } else {
            printf("Error reading from file.\n");
            fclose(file);
            return;
        }

        while (totalAlbum--) {
            int totalSong;
            char albumName[MAX_LINE_LENGTH];
            if (fgets(line, sizeof(line), file) != NULL) {
                trim(line);
                if (sscanf(line, "%d %[^\n]", &totalSong, albumName) != 2) {
                    printf("Error parsing totalSong and albumName.\n");
                    fclose(file);
                    return;
                }

                // Add the album to the singer
                addAlbum(&(app->singers.singers[singerIndex]), albumName, MAX_SONGS_PER_ALBUM);
                int albumIndex = app->singers.singers[singerIndex].numAlbums - 1;

                while (totalSong--) {
                    char songName[MAX_LINE_LENGTH];
                    if (fgets(line, sizeof(line), file) != NULL) {
                        trim(line);
                        strncpy(songName, line, sizeof(songName) - 1);
                        songName[sizeof(songName) - 1] = '\0';

                        // Create a new song and add it to the album
                        Song *song = createSong(songName, bandName, albumName, app->singers.singers[singerIndex].albums[albumIndex].size + 1);
                        addSongToAlbum(&(app->singers.singers[singerIndex]), albumName, song);
                    } else {
                        printf("Error reading from file.\n");
                        fclose(file);
                        return;
                    }
                }
            } else {
                printf("Error reading from file.\n");
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}
