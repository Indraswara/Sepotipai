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

void createEmptySong(Song *song);
void changeValue(Song *song, const char *defaultSongName, const char *defaultArtistName, const char *defaultAlbumName, int defaultSongID);
Song *createSong(const char *songName, const char *artistName, const char *albumName, int songID);
void destroySong(Song *song);

#endif
