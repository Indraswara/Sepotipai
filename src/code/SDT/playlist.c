#include "../../header/SDT/Playlist/playlist.h"

void initializePlaylists(Playlists *playlists) {
    playlists->playlists = NULL;
    playlists->numPlaylists = 0;
    playlists->capacity = 0;
}

void addPlaylist(Playlists *playlists, const char *playlistName) {
    if (playlists->numPlaylists >= playlists->capacity) {
        int newCapacity = (playlists->capacity == 0) ? 1 : playlists->capacity * 2;
        Playlist *newPlaylists = realloc(playlists->playlists, newCapacity * sizeof(Playlist));
        if (newPlaylists == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        playlists->playlists = newPlaylists;
        playlists->capacity = newCapacity;
    }

    playlists->playlists[playlists->numPlaylists].playlistName = malloc(strlen(playlistName) + 1);
    if (playlists->playlists[playlists->numPlaylists].playlistName == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy((char *)playlists->playlists[playlists->numPlaylists].playlistName, playlistName);

    printf("%s successfully added\n", playlistName);
    playlists->numPlaylists++;
}

void removePlaylist(Playlists *playlists, const char *playlistName) {
    int foundIndex = -1;
    for (int i = 0; i < playlists->numPlaylists; i++) {
        if (strcmp(playlists->playlists[i].playlistName, playlistName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Playlist '%s' not found.\n", playlistName);
        return;
    }

    free((char *)playlists->playlists[foundIndex].playlistName);
    for (int i = foundIndex; i < playlists->numPlaylists - 1; i++) {
        playlists->playlists[i] = playlists->playlists[i + 1];
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
        printf("    %d. %s\n", i + 1, playlists->playlists[i].playlistName);
    }
}

void deallocatePlaylists(Playlists *playlists) {
    if (playlists->playlists != NULL) {
        for (int i = 0; i < playlists->numPlaylists; i++) {
            free((char *)playlists->playlists[i].playlistName);
        }
        free(playlists->playlists);
        playlists->playlists = NULL;
    }
    playlists->numPlaylists = 0;
    playlists->capacity = 0;
}
