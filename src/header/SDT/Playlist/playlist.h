#ifndef PLAYLIST_H 
#define PLAYLIST_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Song/song.h"



typedef struct {
    const char *playlistName;  
    Song *songs; 
    int numSongs; 
    int capacity;
} Playlist;

typedef struct {
    Playlist *playlist;
    int numPlaylists;
    int capacity;
} Playlists;

//this is playlists
void initializePlaylists(Playlists *playlists);
void addPlaylist(Playlists *playlists, const char *playlistName);
void removePlaylist(Playlists *playlists, const char *playlistName);
void listPlaylists(Playlists *playlists);
void deallocatePlaylists(Playlists *playlists);
void playlistSwap(Playlists *playlists, int playlistID, int x, int y);

//this each playlist
Playlist *createPlaylist(const char *playlistName);
void addSongToPlaylist(Playlist *playlist, const char *songName, const char *artistName, const char *albumName, int songID);
void removeSongFromPlaylist(Playlist *playlist, int songIndex);
void swapSongsInPlaylist(Playlist *playlist, int x, int y);
void deleteAllSongsFromPlaylist(Playlist *playlist);
void deletePlaylist(Playlist *playlist);



#endif 