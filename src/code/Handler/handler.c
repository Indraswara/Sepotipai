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
        }else if(strcmp(input, "PLAYLIST") == 0){
            char subcommand[100]; 
            scanf("%s", subcommand); 
            playlist(subcommand, app);
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

void playlist(const char *command, App *app){
    if(strcmp(command, "CREATE") == 0){
        playlistCreate(app);    
    }
    else if(strcmp(command, "ADD") == 0){
        char subcommand[100]; 
        scanf("%s", subcommand);
        playlistAdd(subcommand, app);
    }
    else if(strcmp(command, "SHOW") == 0){
        listPlaylists(&(app->playlists));
    }
}

void playlistCreate(App *app){
    printf("Masukkan nama playlist yang ingin dibuat: "); 
    char name[100]; 
    scanf("%s", name); 
    if(strlen(name) <= 3){
        printf("nama yang dimasukkan kurang panjang\n"); 
        return;
    }
    addPlaylist(&(app->playlists), name);
    printf("Playlist %s berhasil dibuat silahkan menambahkan lagu kesayangan anda\n", name);
}


void playlistAdd(const char *command, App *app){
    if(strcmp(command, "SONG") == 0){
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

        // Ask for playlist name to add the song
        printf("Daftar Playlist:\n");
        for (int i = 0; i < app->playlists.numPlaylists; i++) {
            printf("%d. %s\n", i + 1, app->playlists.playlist[i].playlistName);
        }

        char playlistName[100];
        printf("Masukkan Nama Playlist: ");
        scanf(" %[^\n]", playlistName);

        int playlistIndex = -1;
        for (int i = 0; i < app->playlists.numPlaylists; i++) {
            if (strcmp(app->playlists.playlist[i].playlistName, playlistName) == 0) {
                playlistIndex = i;
                break;
            }
        }

        if (playlistIndex == -1) {
            printf("Playlist dengan nama '%s' tidak ditemukan.\n", playlistName);
            return;
        }

        // Add song to the found playlist
        addSongToPlaylist(&(app->playlists.playlist[playlistIndex]), songName, singerName, albumName, songID);
        printf("Berhasil menambahkan lagu \"%s\" ke playlist \"%s\".\n", songName, playlistName);
    }
    else if(strcmp(command, "ALBUM") == 0){
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

        // Ask for playlist name to add the entire album
        printf("Daftar Playlist:\n");
        for (int i = 0; i < app->playlists.numPlaylists; i++) {
            printf("%d. %s\n", i + 1, app->playlists.playlist[i].playlistName);
        }

        char playlistName[100];
        printf("Masukkan Nama Playlist: ");
        scanf(" %[^\n]", playlistName);

        int playlistIndex = -1;
        for (int i = 0; i < app->playlists.numPlaylists; i++) {
            if (strcmp(app->playlists.playlist[i].playlistName, playlistName) == 0) {
                playlistIndex = i;
                break;
            }
        }

        if (playlistIndex == -1) {
            printf("Playlist dengan nama '%s' tidak ditemukan.\n", playlistName);
            return;
        }

        // Add entire album to the found playlist
        for (int i = 0; i < app->singers.singers[singerIndex].albums[albumIndex].size; i++) {
            const char *songName = app->singers.singers[singerIndex].albums[albumIndex].songs[i];
            addSongToPlaylist(&(app->playlists.playlist[playlistIndex]), songName, singerName, albumName, i + 1);
        }
        printf("Berhasil menambahkan semua lagu dari album \"%s\" ke playlist \"%s\".\n", albumName, playlistName);
    }
    else {
        printf("Subcommand '%s' untuk menambahkan ke playlist tidak dikenali.\n", command);
    }
}


