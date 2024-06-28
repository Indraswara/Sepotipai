

#include "../../header/Handler/handlerPlaylist.h"


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
            printf("%d. %s\n", i + 1, app->singers.singers[singerIndex].albums[albumIndex].songs[i]->songName);
        }

        int songID;
        printf("Masukkan ID Lagu yang dipilih: ");
        scanf("%d", &songID);

        if (songID < 1 || songID > app->singers.singers[singerIndex].albums[albumIndex].size) {
            printf("ID Lagu tidak valid.\n");
            return;
        }

        const char *songName = app->singers.singers[singerIndex].albums[albumIndex].songs[songID - 1]->songName;

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
            const char *songName = app->singers.singers[singerIndex].albums[albumIndex].songs[i]->songName;
            addSongToPlaylist(&(app->playlists.playlist[playlistIndex]), songName, singerName, albumName, i + 1);
        }
        printf("Berhasil menambahkan semua lagu dari album \"%s\" ke playlist \"%s\".\n", albumName, playlistName);
    }
    else {
        printf("Subcommand '%s' untuk menambahkan ke playlist tidak dikenali.\n", command);
    }
}

void showPlaylistData(int id, App *app) {
    if (id < 1 || id > app->playlists.numPlaylists) {
        printf("Tidak ada playlist dengan ID %d\n", id);
        return;
    }

    Playlist *playlist = &app->playlists.playlist[id - 1];
    printf("Playlist: %s\n", playlist->playlistName);
    printf("Songs:\n");

    for (int i = 0; i < playlist->numSongs; i++) {
        Song *song = &playlist->songs[i];
        printf("  %d. %s by %s from album %s\n", i + 1, song->songName, song->artistName, song->albumName);
    }
}

void playlistRemove(int playlistID, int songIndex, App *app) {

    if (playlistID < 1 || playlistID > app->playlists.numPlaylists) {
        printf("Tidak ada playlist dengan ID %d.\n", playlistID);
        return;
    }

    Playlist *playlist = &app->playlists.playlist[playlistID - 1];

    if (songIndex < 1 || songIndex > playlist->numSongs) {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\".\n", songIndex, playlist->playlistName);
        return;
    }

    Song song = playlist->songs[songIndex - 1];

    printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari playlist \"%s\"!\n", song.songName, song.artistName, playlist->playlistName);
    removeSongFromPlaylist(playlist, songIndex - 1);
}


void playlistDelete(App *app) {
    if (app->playlists.numPlaylists == 0) {
        printf("KAMU TIDAK MEMILIKI PLAYLIST\n");
        return;
    }

    listPlaylists(&app->playlists);

    int playlistID;
    printf("Masukkan ID Playlist yang dipilih: ");
    scanf("%d", &playlistID);

    if (playlistID < 1 || playlistID > app->playlists.numPlaylists) {
        printf("Tidak ada playlist dengan ID %d.\n", playlistID);
        return;
    }
    removePlaylist(&app->playlists, app->playlists.playlist[playlistID - 1].playlistName);
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
    else if(strcmp(command, "REMOVE") == 0){
        int idPlaylist, idSong; 
        scanf("%d %d", &idPlaylist, &idSong); 
        playlistRemove(idPlaylist, idSong, app);
    }
    else if(strcmp(command, "DELETE") == 0){
        playlistDelete(app);
    }
    else if(strcmp(command, "DATA") == 0){
        int id; 
        scanf("%d", &id);
        showPlaylistData(id, app);
    }else{
        printf("Perintah tidak dikenali\n");
        printf("List perintah PLAYLIST: ");
        printf("    - CREATE\n");
        printf("    - ADD\n");
        printf("    - SHOW\n");
        printf("    - SWAP z x y"); 
        printf("      z: id playlist");
        printf("      x: id lagu pertama");
        printf("      y: id lagu kedua");
        printf("    - REMOVE x y\n");
        printf("      x: id playlist");
        printf("      y: id lagu yang ingin dihapus");
        printf("    - DELETE\n");
        printf("    - DATA\n");
    }
}