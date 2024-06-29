#include "../../header/File/save.h"

void saveToFile(App *app, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", app->singers.numSingers);

    for (int i = 0; i < app->singers.numSingers; ++i) {
        Singer *singer = &(app->singers.singers[i]);
        
        // Write total number of albums and singer's name
        fprintf(file, "%d %s\n", singer->numAlbums, singer->singerName);
        
        for (int j = 0; j < singer->numAlbums; ++j) {
            Album *album = &(singer->albums[j]);
            
            // Write total number of songs and album's name
            fprintf(file, "%d %s\n", album->size, album->name);
            
            for (int k = 0; k < album->size; ++k) {
                Song *song = album->songs[k];
                
                // Write song's name
                fprintf(file, "%s\n", song->songName);
            }
        }
    }
    fclose(file);
    printf("Data saved to %s\n", filename);
}