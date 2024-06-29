#include "../../header/SDT/Album/Album.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createAlbum(Album *album, const char *name, int capacity) {
    album->name = (char*)malloc(strlen(name));
    memcpy((void *)album->name, name, strlen(name)); 
    // album->name = name;
    album->capacity = capacity;
    album->size = 0;
    album->songs = (Song**)malloc(capacity * sizeof(Song*));
}

void deallocateAlbum(Album *album) {
    for (int i = 0; i < album->size; ++i) {
        destroySong(album->songs[i]);
        free(album->songs[i]);
    }
    free(album->songs);
}

void insertSong(Album *album, Song *song) {
    if (album->size < album->capacity) {
        album->songs[album->size] = song;
        album->size++;
    } else {
        printf("Album is full, cannot insert more songs.\n");
    }
}

void printAlbumSongs(const Album *album) {
    printf("Album: %s\n", album->name);
    printf("Songs:\n");
    for (int i = 0; i < album->size; ++i) {
        printf("%d. %s by %s\n", album->songs[i]->songID, album->songs[i]->songName, album->songs[i]->artistName);
    }
}
