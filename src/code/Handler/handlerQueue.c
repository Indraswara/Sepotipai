#include "../../header/Handler/handlerQueue.h"

void queue(const char* command, App *app) {
    if (strcmp(command, "SONG") == 0) {
        queueSong(app);
    } else if (strcmp(command, "PLAYLIST") == 0) {
        queuePlaylist(app);
    } else if (strcmp(command, "SWAP") == 0) {
        int x, y;
        printf("Enter positions (x y): ");
        scanf("%d %d", &x, &y);
        queueSwap(&(app->queue), x, y);
    } else if (strcmp(command, "REMOVE") == 0) {
        int id;
        printf("Enter position to remove: ");
        scanf("%d", &id);
        queueRemove(&(app->queue), id);
    } else if (strcmp(command, "CLEAR") == 0) {
        queueClear(&(app->queue));
    } else if (strcmp(command, "SHOW") == 0) {
        printQueue(&(app->queue));
    } else {
        printf("Subcommand QUEUE not recognized.\n");
    }
}

void queueSong(App *app) {
    printf("List of Singers:\n");
    for (int i = 0; i < app->singers.numSingers; i++) {
        printf("%d. %s\n", i + 1, app->singers.singers[i].singerName);
    }

    char singerName[100];
    printf("Enter Singer's Name: ");
    scanf(" %[^\n]", singerName);

    int singerIndex = -1;
    for (int i = 0; i < app->singers.numSingers; i++) {
        if (strcmp(app->singers.singers[i].singerName, singerName) == 0) {
            singerIndex = i;
            break;
        }
    }

    if (singerIndex == -1) {
        printf("Singer '%s' not found.\n", singerName);
        return;
    }

    printf("\nAlbums by %s:\n", singerName);
    for (int i = 0; i < app->singers.singers[singerIndex].numAlbums; i++) {
        printf("%d. %s\n", i + 1, app->singers.singers[singerIndex].albums[i].name);
    }

    char albumName[100];
    printf("Enter Album Name: ");
    scanf(" %[^\n]", albumName);

    int albumIndex = -1;
    for (int i = 0; i < app->singers.singers[singerIndex].numAlbums; i++) {
        if (strcmp(app->singers.singers[singerIndex].albums[i].name, albumName) == 0) {
            albumIndex = i;
            break;
        }
    }
    if (albumIndex == -1) {
        printf("Album '%s' not found for singer '%s'.\n", albumName, singerName);
        return;
    }
    printf("\nSongs in Album %s by %s:\n", albumName, singerName);
    for (int i = 0; i < app->singers.singers[singerIndex].albums[albumIndex].size; i++) {
        printf("%d. %s\n", i + 1, app->singers.singers[singerIndex].albums[albumIndex].songs[i]->songName);
    }

    int songID;
    printf("Enter Song ID: ");
    scanf("%d", &songID);

    if (songID < 1 || songID > app->singers.singers[singerIndex].albums[albumIndex].size) {
        printf("Invalid Song ID.\n");
        return;
    }

    const char *songName = app->singers.singers[singerIndex].albums[albumIndex].songs[songID - 1]->songName;
    enqueueSong(&app->queue, songName, singerName, albumName, songID);
    printf("Successfully added song \"%s\" by \"%s\" to queue.\n", songName, singerName);
}

void queuePlaylist(App *app) {
    if (app->playlists.numPlaylists == 0) {
        printf("You do not have any playlists.\n");
        return;
    }

    printf("List of Playlists:\n");
    for (int i = 0; i < app->playlists.numPlaylists; i++) {
        printf("%d. %s\n", i + 1, app->playlists.playlist[i].playlistName);
    }

    int playlistID;
    printf("Enter Playlist ID: ");
    scanf("%d", &playlistID);

    if (playlistID > 0 && playlistID <= app->playlists.numPlaylists) {
        Playlist *playlist = &app->playlists.playlist[playlistID - 1];
        // enqueuePlaylist(&app->queue, playlist);
        for (int i = 0; i < playlist->numSongs; i++) {
            Song *song = &playlist->songs[i];
            enqueueSong(&app->queue, song->songName, song->artistName, song->albumName, song->songID);
        }
        printf("Successfully added playlist \"%s\" to queue.\n", playlist->playlistName);
    } else {
        printf("Invalid Playlist ID.\n");
    }
}