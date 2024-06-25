#include "../../header/Handler/handlerList.h"

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