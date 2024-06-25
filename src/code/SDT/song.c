#include "../../header/SDT/Song/song.h"
#include <string.h>  // For string manipulation functions

Song *createSong(const char *songName, const char *artistName, const char *albumName, int songID) {
    Song *song = (Song *)malloc(sizeof(Song));
    if (song == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    song->songName = (const char *)malloc(strlen(songName) + 1);
    if (song->songName == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(song);
        exit(EXIT_FAILURE);
    }
    strcpy((char *)song->songName, songName);

    song->artistName = (const char *)malloc(strlen(artistName) + 1);
    if (song->artistName == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free((char *)song->songName);
        free(song);
        exit(EXIT_FAILURE);
    }
    strcpy((char *)song->artistName, artistName);

    song->albumName = (const char *)malloc(strlen(albumName) + 1);
    if (song->albumName == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free((char *)song->artistName);
        free((char *)song->songName);
        free(song);
        exit(EXIT_FAILURE);
    }
    strcpy((char *)song->albumName, albumName);

    song->songID = songID;

    return song;
}

void destroySong(Song *song) {
    if (song != NULL) {
        free((char *)song->songName);
        free((char *)song->artistName);
        free((char *)song->albumName);
        free(song);
    }
}