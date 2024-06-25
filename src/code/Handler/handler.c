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
        playlistCreate(&app);    
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
        
    }
    else if(strcmp(command, "ALBUM") == 0){

    }

}

