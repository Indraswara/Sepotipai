#include "../../header/SDT/Album/Album.h"

void createAlbum(Album *album, const char *name, int capacity) {
    album->name = strdup(name); 
    album->songs = malloc(capacity * sizeof(const char*)); 
    album->capacity = capacity;
    album->size = 0; 
}

void deallocateAlbum(Album *album) {
    free((char*)album->name); 
    free(album->songs);       
    album->capacity = 0;      
    album->size = 0;          
}

void insertSong(Album *album, const char *songTitle) {
    if (album->size < album->capacity) {
        album->songs[album->size++] = strdup(songTitle); 
    } else {
        printf("Album is full, cannot add more songs.\n");
    }
}

void printAlbumSongs(const Album *album) {
    printf("Album: %s\n", album->name);
    printf("Songs:\n");
    for (int i = 0; i < album->size; ++i) {
        printf("- %s\n", album->songs[i]);
    }
}
