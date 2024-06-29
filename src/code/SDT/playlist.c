#include "../../header/SDT/Playlist/playlist.h"

// this is playlists 
void initializePlaylists(Playlists *playlists) {
    playlists->playlist = (Playlist *)malloc(sizeof(Playlist));
    playlists->numPlaylists = 0;
    playlists->capacity = 0;
}

void addPlaylist(Playlists *playlists, const char *playlistName) {
    if (playlists->numPlaylists >= playlists->capacity) {
        int newCapacity = (playlists->capacity == 0) ? 1 : playlists->capacity * 2;
    Playlist *newPlaylists = realloc(playlists->playlist, newCapacity * sizeof(Playlist));
        if (newPlaylists == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        playlists->playlist = newPlaylists;
        playlists->capacity = newCapacity;
    }

    playlists->playlist[playlists->numPlaylists].playlistName = (char *)malloc(strlen(playlistName));
    if (playlists->playlist[playlists->numPlaylists].playlistName == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy((char *)playlists->playlist[playlists->numPlaylists].playlistName, playlistName);

    printf("%s successfully added\n", playlists->playlist[playlists->numPlaylists].playlistName);
    playlists->numPlaylists++;
}

void removePlaylist(Playlists *playlists, const char *playlistName) {
    int foundIndex = -1;
    for (int i = 0; i < playlists->numPlaylists; i++) {
        if (strcmp(playlists->playlist[i].playlistName, playlistName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Playlist '%s' not found.\n", playlistName);
        return;
    }

    free((char *)playlists->playlist[foundIndex].playlistName);
    for (int i = foundIndex; i < playlists->numPlaylists - 1; i++) {
        playlists->playlist[i] = playlists->playlist[i + 1];
    }

    playlists->numPlaylists--;
}

void listPlaylists(Playlists *playlists) {
    if(playlists->capacity == 0){
        printf("KAMU TIDAK MEMILIKI PLAYLIST\n");
        return;

    }
    printf("List of Playlists:\n");
    for (int i = 0; i < playlists->numPlaylists; i++) {
        printf("    %d. %s\n", i + 1, playlists->playlist[i].playlistName);
    }
}

void deallocatePlaylists(Playlists *playlists) {
    if (playlists->playlist != NULL) {
        for (int i = 0; i < playlists->numPlaylists; i++) {
            free((char *)playlists->playlist[i].playlistName);
        }
        free(playlists->playlist);
        playlists->playlist = NULL;
    }
    playlists->numPlaylists = 0;
    playlists->capacity = 0;
}


//this is each playlist 
Playlist *createPlaylist(const char *playlistName) {
    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    if (playlist == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    playlist->playlistName = (char*)malloc(strlen(playlistName));
    if (playlist->playlistName == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(playlist);
        exit(EXIT_FAILURE);
    }
    strcpy((char *)(playlist->playlistName), playlistName);

    playlist->songs = NULL;
    playlist->numSongs = 0;
    playlist->capacity = 0;

    return playlist;
}

void addSongToPlaylist(Playlist *playlist, const char *songName, const char *artistName, const char *albumName, int songID) {
    for (int i = 0; i < playlist->numSongs; i++) {
        if (strcmp(playlist->songs[i].songName, songName) == 0 &&
            strcmp(playlist->songs[i].artistName, artistName) == 0 &&
            strcmp(playlist->songs[i].albumName, albumName) == 0 &&
            playlist->songs[i].songID == songID) {
            printf("Lagu \"%s\" oleh \"%s\" dari album \"%s\" dengan ID %d sudah ada di dalam playlist \"%s\".\n",
                   songName, artistName, albumName, songID, playlist->playlistName);
            return;
        }
    }

    if (playlist->numSongs >= playlist->capacity) {
        int newCapacity = (playlist->capacity == 0) ? 1 : playlist->capacity * 2;
        Song *newSongs = realloc(playlist->songs, newCapacity * sizeof(Song));
        if (newSongs == NULL) {
            fprintf(stderr, "Gagal mengalokasi memori.\n");
            exit(EXIT_FAILURE);
        }
        playlist->songs = newSongs;
        playlist->capacity = newCapacity;
    }
    
    playlist->songs[playlist->numSongs].songName = strdup(songName);
    playlist->songs[playlist->numSongs].artistName = strdup(artistName);
    playlist->songs[playlist->numSongs].albumName = strdup(albumName);
    playlist->songs[playlist->numSongs].songID = songID;

    printf("Lagu \"%s\" oleh \"%s\" dari album \"%s\" dengan ID %d berhasil ditambahkan ke dalam playlist \"%s\".\n",
           songName, artistName, albumName, songID, playlist->playlistName);

    playlist->numSongs++;
}

void removeSongFromPlaylist(Playlist *playlist, int songIndex) {
    if (songIndex < 0 || songIndex >= playlist->numSongs) {
        printf("Indeks lagu tidak valid.\n");
        return;
    }

    free((char *)playlist->songs[songIndex].songName);
    free((char *)playlist->songs[songIndex].artistName);
    free((char *)playlist->songs[songIndex].albumName);

    for (int i = songIndex; i < playlist->numSongs - 1; i++) {
        playlist->songs[i] = playlist->songs[i + 1];
    }

    playlist->numSongs--;
}

void swapSongsInPlaylist(Playlist *playlist, int x, int y) {
    if (x < 0 || y < 0 || x >= playlist->numSongs || y >= playlist->numSongs) {
        printf("Indeks lagu tidak valid untuk ditukar.\n");
        return;
    }

    // Swap songs at indexes x and y
    Song temp = playlist->songs[x];
    playlist->songs[x] = playlist->songs[y];
    playlist->songs[y] = temp;
}

void deleteAllSongsFromPlaylist(Playlist *playlist) {
    for (int i = 0; i < playlist->numSongs; i++) {
        free((char *)playlist->songs[i].songName);
        free((char *)playlist->songs[i].artistName);
        free((char *)playlist->songs[i].albumName);
    }
    free(playlist->songs);
    playlist->songs = NULL;
    playlist->numSongs = 0;
    playlist->capacity = 0;
}

void deletePlaylist(Playlist *playlist) {
    free((char *)playlist->playlistName);
    deleteAllSongsFromPlaylist(playlist);
    free(playlist->songs);
    free(playlist);
}

void playlistSwap(Playlists *playlists, int playlistID, int x, int y) {
    if (playlistID < 1 || playlistID > playlists->numPlaylists) {
        printf("Tidak ada playlist dengan playlist ID %d\n", playlistID);
        return;
    }

    Playlist *playlist = &playlists->playlist[playlistID - 1];

    if (x < 1 || x > playlist->numSongs || y < 1 || y > playlist->numSongs) {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"\n", (x < 1 || x > playlist->numSongs) ? x : y, playlist->playlistName);
        return;
    }

    swapSongsInPlaylist(playlist, x - 1, y - 1);
    printf("Berhasil menukar lagu \"%s\" dengan \"%s\" di playlist \"%s\"\n",
           playlist->songs[x - 1].songName,
           playlist->songs[y - 1].songName,
           playlist->playlistName);
}

