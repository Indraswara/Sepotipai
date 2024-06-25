#ifndef SONG_H
#define SONG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *songName;
    const char *artistName;
    const char *albumName;
    int songID;
} Song;

// Initialize a song
Song *createSong(const char *songName, const char *artistName, const char *albumName, int songID);

// Destroy a song
void destroySong(Song *song);

#endif
