#include "../../header/SDT/Song/song.h"
#include <string.h>  // s

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

void createEmptySong(Song *song) {
    song = (Song *)malloc(sizeof(Song));
    if (song == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    song->songName = NULL;
    song->artistName = NULL;
    song->albumName = NULL;
    song->songID = 0;
}

void changeValue(Song *song, const char *defaultSongName, const char *defaultArtistName, const char *defaultAlbumName, int defaultSongID) {
    if (song == NULL) {
        fprintf(stderr, "Error: Song pointer is NULL.\n");
        return;
    }

    if (song->songName == NULL || strlen(song->songName) > 0) {
        song->songName = strdup(defaultSongName);
        if (song->songName == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    if (song->artistName == NULL || strlen(song->artistName) > 0){
        song->artistName = strdup(defaultArtistName);
        if (song->artistName == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    if (song->albumName == NULL || strlen(song->albumName) > 0) {
        song->albumName = strdup(defaultAlbumName);
        if (song->albumName == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    if (song->songID == 0) {
        song->songID = defaultSongID;
    }
}


void destroySong(Song *song) {
    if (song != NULL) {
        free((char *)song->songName);
        free((char *)song->artistName);
        free((char *)song->albumName);
        free(song);
    }
}