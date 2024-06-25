#include "../../header/Handler/handlerPlay.h"

void play(const char* command, App *app) {
    if (strcmp(command, "SONG") == 0) {
        playSong(app);
    } else if (strcmp(command, "PLAYLIST") == 0) {
        playPlaylist(app);
    } else {
        printf("Perintah '%s' tidak dikenali dalam play.\n", command);
    }
}


void playSong(App *app) {
    printf("Daftar Penyanyi:\n");
    for (int i = 0; i < app->singers.numSingers; i++) {
        printf("    %d. %s\n", i + 1, app->singers.singers[i].singerName);
    }

    char singerName[100];
    char albumName[100];
    int songIndex;

    printf("Masukkan nama penyanyi: ");
    scanf(" %[^\n]", singerName);

    int singerIndex = -1;
    for (int i = 0; i < app->singers.numSingers; i++) {
        if (strcmp(app->singers.singers[i].singerName, singerName) == 0) {
            singerIndex = i;
            break;
        }
    }

    if (singerIndex == -1) {
        printf("Penyanyi dengan nama '%s' tidak ditemukan.\n", singerName);
        return;
    }

    printf("\nAlbum untuk penyanyi '%s':\n", singerName);
    for (int i = 0; i < app->singers.singers[singerIndex].numAlbums; i++) {
        printf("    %d. %s\n", i + 1, app->singers.singers[singerIndex].albums[i].name);
    }

    printf("Masukkan nama album: ");
    scanf(" %[^\n]", albumName);

    int albumIndex = -1;
    for (int i = 0; i < app->singers.singers[singerIndex].numAlbums; i++) {
        if (strcmp(app->singers.singers[singerIndex].albums[i].name, albumName) == 0) {
            albumIndex = i;
            break;
        }
    }

    if (albumIndex == -1) {
        printf("Album '%s' tidak ditemukan untuk penyanyi '%s'.\n", albumName, singerName);
        return;
    }

    printf("\nLagu untuk album '%s':\n", albumName);
    for (int i = 0; i < app->singers.singers[singerIndex].albums[albumIndex].size; i++) {
        printf("    %d. %s\n", i + 1, app->singers.singers[singerIndex].albums[albumIndex].songs[i]->songName);
    }

    printf("Masukkan nomor lagu (1-%d): ", app->singers.singers[singerIndex].albums[albumIndex].size);
    scanf("%d", &songIndex);

    if (songIndex < 1 || songIndex > app->singers.singers[singerIndex].albums[albumIndex].size) {
        printf("Nomor lagu tidak valid untuk album '%s'.\n", albumName);
        return;
    }

    songIndex--;
    const char *songName = app->singers.singers[singerIndex].albums[albumIndex].songs[songIndex]->songName;
    printf("\nMemulai lagu: %s dari penyanyi: %s, album: %s\n", songName, singerName, albumName);
}

void playPlaylist(App *app) {
    // List available playlists
    printf("Daftar Playlist:\n");
    listPlaylists(&(app->playlists));

    int playlistIndex;
    printf("Masukkan nomor playlist (1-%d): ", app->playlists.numPlaylists);
    scanf("%d", &playlistIndex);

    if (playlistIndex < 1 || playlistIndex > app->playlists.numPlaylists) {
        printf("Nomor playlist tidak valid.\n");
        return;
    }

    playlistIndex--;
    const char *playlistName = app->playlists.playlist[playlistIndex].playlistName;
    printf("\nMemutar playlist '%s'.\n", playlistName);
}
