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

void prepare(App *app) {
    initializeSingers(&(app->singers));  // Initialize singers (formerly singerManager)

    // Example: Adding singers dynamically
    addSinger(&(app->singers), 10);  // Example capacity 10 for first singer
    addAlbum(&(app->singers.singers[0]), "First Album", 5);
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song A");
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song B");
    
    addSinger(&(app->singers), 3);  // Example capacity 3 for second singer
    addAlbum(&(app->singers.singers[1]), "Second Album", 3);
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song X");
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song Y");
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
    if (strcmp(command, "ADD") == 0) {
        printf("Melakukan operasi ADD di list()\n");
        
        for(int i = 0; i < app->singers.numSingers; i++){
            printf("singer %d:\n", i+1); 
            printSingerDiscography(&(app->singers.singers[i]));
        }

    } else if (strcmp(command, "REMOVE") == 0) {
        printf("Melakukan operasi REMOVE di list()\n");
        // Add your 'REMOVE' functionality here
    } else {
        printf("Perintah '%s' tidak dikenali dalam list()\n", command);
    }
}