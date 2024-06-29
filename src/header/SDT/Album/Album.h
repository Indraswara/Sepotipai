#ifndef ALBUM_H 
#define ALBUM_H

#include "../Song/song.h" // Include the song header file

typedef struct {
    const char* name;
    Song** songs; // Array of Song pointers
    int capacity;
    int size;
} Album;

void createAlbum(Album *album, const char *name, int capacity);
void deallocateAlbum(Album *album);
void insertSong(Album *album, Song *song); // Update to accept Song pointer
void printAlbumSongs(const Album *album);

#endif
