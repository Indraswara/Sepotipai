#ifndef ALBUM_H 
#define ALBUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char* name;
    const char** songs;
    int capacity;
    int size;
} Album;

void createAlbum(Album *album, const char *name, int capacity);
void deallocateAlbum(Album *album);
void insertSong(Album *album, const char *songTitle);
void printAlbumSongs(const Album *album); // Updated to pass Album by const reference

#endif
