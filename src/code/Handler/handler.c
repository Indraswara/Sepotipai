#include "../../header/Handler/handler.h"

void startup(){
    App app;
    printf("Selamat datang di Sepotipai\n"); 
    printf("jalankan \"START\" untuk memuat konfigurasi\n"); 

    char test[100]; 

    while(true){
        printf(">> ");
        scanf("%s", test);
        if(memcmp(test, "START", strlen(test)) == 0){
            initializer(&app);
            menu(&app); 
            return;
        }else{
            printf("PERINTAH ANDA SAAT INI HANYA: \n"); 
            printf("START: untuk memulai permainan\n");
        }
    }
}



void menu(App* app){
    while(true){
        char input[100]; 
        printf(">> ");
        scanf("%s", input); 
        if(memcmp(input, "LIST", strlen(input)) == 0){
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
        }else if(strcmp(input, "SONG") == 0){
            char subcommand[100]; 
            scanf("%s", subcommand); 
            songHandler(subcommand, app);

        }else if(strcmp(input, "STATUS") == 0){
            statusHandler(app);
        }else if(strcmp(input, "SAVE") == 0){
            char path[100];
            printf("Masukkan nama file: ");
            scanf("%s", path);
            saveToFile(app, path);
        } else if(strcmp(input, "LOAD") == 0){
            char path[100];
            printf("Masukkan nama file: ");
            scanf("%s", path);
            clearApp(app);
            loadFile(app, path);
        }
        else if(strcmp(input, "HELP") == 0){
            help();
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


void help(){
    printf("List Command: \n");
    printf("    - LIST\n");
    printf("    - PLAY\n");
    printf("    - QUEUE\n");
    printf("    - PLAYLIST\n");
    printf("    - SONG\n");
    printf("    - SAVE\n");
    printf("    - LOAD\n");
    printf("    - STATUS\n");
    printf("    - HELP\n");
    printf("    - EXIT\n");
}


