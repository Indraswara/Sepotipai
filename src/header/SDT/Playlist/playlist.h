#ifndef PLAYLIST_H 
#define PLAYLIST_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *playlistName;  
} Playlist;

typedef struct {
    Playlist *playlists;
    int numPlaylists;
    int capacity;
} Playlists;

void initializePlaylists(Playlists *playlists);
void addPlaylist(Playlists *playlists, const char *playlistName);
void removePlaylist(Playlists *playlists, const char *playlistName);
void listPlaylists(Playlists *playlists);
void deallocatePlaylists(Playlists *playlists);

#endif 