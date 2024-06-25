
#include "../../header/Handler/handler.h"



void startup(){
    App app;
    printf("Selamat datang di Sepotipai\n"); 
    printf("jalankan \"START\" untuk memuat konfigurasi\n"); 

    char test[100]; 
    printf(">> ");
    scanf("%s", test);

    if(memcmp(test, "START", strlen(test)) == 0){
        printf("HASILNYA SAMA\n");
        initializer(&app);
        menu(&app); 
    }else{
        printf("KONFIGURASI TIDAK ADA, SILAHKAN MASUKKAN ULANG");
        return;
    }
}


void menu(App* app){
    while(true){
        char input[100]; 
        printf(">> ");
        scanf("%s", input); 
        if(memcmp(input, "LOAD", strlen(input)) == 0){
            printf("LOAD DISINI\n");
        }
        else if(memcmp(input, "LIST", strlen(input)) == 0){
            char subcommand[100]; 
            scanf("%s", subcommand); 
            list(subcommand, app);
        }
        else if(memcmp(input, "PLAY", strlen(input)) == 0){
            char subcommand[100]; 
            scanf("%s", subcommand); 
            play(subcommand, app);
        }else if(memcmp(input, "QUEUE", strlen(input)) == 0){
            char subcommand[100]; 
            scanf("%s", subcommand); 
            queue(subcommand, app);
        }
        else if(memcmp(input, "EXIT", strlen("EXIT")) == 0){
            printf("KELUAR DARI PROGRAM\n");
            break;
        }
        else{
            printf("PERINTAH TIDAK ADA\n"); 
        }
    }
}

void queue(const char* command, App *app) {
    if (strcmp(command, "SONG") == 0) {
        queueSong(app);
    } else if (strcmp(command, "PLAYLIST") == 0) {
        queuePlaylist(app);
    } else if(strcmp(command, "SWAP") == 0){
        int x, y;
        scanf("%d %d", &x, &y); 
        queueSwap(&(app->queue), x, y);
    } else if(strcmp(command, "REMOVE") == 0){
        int id; 
        scanf("%d", &id); 
        queueRemove(&(app->queue), id); 
    } else if(strcmp(command, "CLEAR") == 0){
        queueClear(&(app->queue));
    }
    else if(strcmp(command, "SHOW") == 0){
        printQueue(&(app->queue));
    } 
    else {
        printf("Subcommand QUEUE tidak dikenali\n");
    }
}

void queueSong(App *app) {
    printf("Daftar Penyanyi:\n");
    for (int i = 0; i < app->singers.numSingers; i++) {
        printf("%d. %s\n", i + 1, app->singers.singers[i].singerName);
    }

    char singerName[100];
    printf("Masukkan Nama Penyanyi: ");
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

    printf("\nDaftar Album oleh %s:\n", singerName);
    for (int i = 0; i < app->singers.singers[singerIndex].numAlbums; i++) {
        printf("%d. %s\n", i + 1, app->singers.singers[singerIndex].albums[i].name);
    }

    char albumName[100];
    printf("Masukkan Nama Album yang dipilih: ");
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

    printf("\nDaftar Lagu Album %s oleh %s:\n", albumName, singerName);
    for (int i = 0; i < app->singers.singers[singerIndex].albums[albumIndex].size; i++) {
        printf("%d. %s\n", i + 1, app->singers.singers[singerIndex].albums[albumIndex].songs[i]);
    }

    int songID;
    printf("Masukkan ID Lagu yang dipilih: ");
    scanf("%d", &songID);

    if (songID < 1 || songID > app->singers.singers[singerIndex].albums[albumIndex].size) {
        printf("ID Lagu tidak valid.\n");
        return;
    }

    const char *songName = app->singers.singers[singerIndex].albums[albumIndex].songs[songID - 1];
    enqueueSong(&app->queue, songName, singerName, albumName, songID);
    printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", songName, singerName);
}

void queuePlaylist(App *app) {
    if (app->playlists.numPlaylists == 0) {
        printf("KAMU TIDAK MEMILIKI PLAYLIST\n");
        return;
    }

    printf("List of Playlists:\n");
    for (int i = 0; i < app->playlists.numPlaylists; i++) {
        printf("%d. %s\n", i + 1, app->playlists.playlists[i].playlistName);
    }

    printf("Masukkan ID Playlist: ");
    int playlistID;
    scanf("%d", &playlistID);

    if (playlistID > 0 && playlistID <= app->playlists.numPlaylists) {
        Playlist *playlist = &app->playlists.playlists[playlistID - 1];
        enqueuePlaylist(&app->queue, playlist);
        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", playlist->playlistName);
    } else {
        printf("ID Playlist tidak valid.\n");
    }
}

