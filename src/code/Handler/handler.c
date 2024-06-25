#include "../../header/Handler/handler.h"
#include "../../shared/boolean.h"

void startup(){
    App app;
    printf("Selamat datang di Sepotipai\n"); 
    printf("jalankan \"START\" untuk memuat konfigurasi\n"); 

    char test[100]; 
    printf(">> ");
    scanf("%s", test);

    if(memcmp(test, "START", strlen(test)) == 0){
        printf("HASILNYA SAMA\n");
        prepare(&app);
        menu(&app); 
    }else{
        printf("KONFIGURASI TIDAK ADA, SILAHKAN MASUKKAN ULANG");
        return;
    }
}

//STILL HARDCODED
void prepare(App *app) {
    initializeSingers(&(app->singers));   // Initialize singers
    initializePlaylists(&(app->playlists)); // Initialize playlists

    // Example: Adding singers dynamically
    addSinger(&(app->singers), "Singer One", 10);  // Example capacity 10 for first singer
    addAlbum(&(app->singers.singers[0]), "First Album", 5);
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song A");
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song B");

    addSinger(&(app->singers), "Singer Two", 3);  // Example capacity 3 for second singer
    addAlbum(&(app->singers.singers[1]), "Second Album", 3);
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song X");
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song Y");

    // Example: Adding playlists dynamically
    addPlaylist(&(app->playlists), "Workout Playlist");
    addPlaylist(&(app->playlists), "Chill Playlist");
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
        else if(memcmp(input, "EXIT", strlen("EXIT")) == 0){
            printf("KELUAR DARI PROGRAM\n");
            break;
        }else{
            printf("PERINTAH TIDAK ADA\n"); 
        }
    }
}

void list(const char *command, App *app) {
    if (strcmp(command, "DEFAULT") == 0) {
        listDefault(app);
    } else if (strcmp(command, "PLAYLIST") == 0) {
        listPlaylistHandler(app);
    } else if (strcmp(command, "REMOVE") == 0) {
        printf("Melakukan operasi REMOVE di list()\n");
        // Implement remove operation logic here
    } else {
        printf("Perintah '%s' tidak dikenali dalam list.\n", command);
    }
}

void listDefault(App *app) {
    printf("List penyanyi:\n");
    for (int i = 0; i < app->singers.numSingers; i++) {
        printf("    %d. %s\n", i + 1, app->singers.singers[i].singerName);
    }

    // Prompt user for album view
    char choice;
    printf("Ingin melihat album yang ada? (Y/N): ");
    scanf(" %c", &choice);  // Read user choice

    if (choice == 'Y' || choice == 'y') {
        char singerName[100];  // Assuming maximum singer name length of 100 characters
        printf("Masukkan nama penyanyi untuk melihat album mereka: ");
        scanf(" %[^\n]", singerName);  // Read singer name including spaces

        // Find the singer by name
        int found = 0;
        for (int i = 0; i < app->singers.numSingers; i++) {
            if (strcmp(app->singers.singers[i].singerName, singerName) == 0) {
                printf("Album milik %s:\n", singerName);
                printSingerDiscography(&(app->singers.singers[i]));  

                char viewSongsChoice;
                printf("Mau melihat lagu dalam album? (Y/N): ");
                scanf(" %c", &viewSongsChoice);
                if (viewSongsChoice == 'Y' || viewSongsChoice == 'y') {
                    char albumName[100];  
                    printf("Masukkan nama album untuk melihat lagu-lagunya: ");
                    scanf(" %[^\n]", albumName);  

                    int albumFound = 0;
                    for (int j = 0; j < app->singers.singers[i].numAlbums; j++) {
                        if (strcmp(app->singers.singers[i].albums[j].name, albumName) == 0) {
                            printf("Lagu-lagu dalam album '%s':\n", albumName);
                            printAlbumSongs(&(app->singers.singers[i].albums[j]));
                            albumFound = 1;
                            break;
                        }
                    }

                    if (!albumFound) {
                        printf("Album '%s' tidak ditemukan.\n", albumName);
                    }
                }
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Penyanyi dengan nama '%s' tidak ditemukan.\n", singerName);
        }
    } else {
        printf("Tidak melihat album penyanyi.\n");
    }
}

void listPlaylistHandler(App *app) {
    listPlaylists(&(app->playlists));
}