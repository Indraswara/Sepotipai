#include "../../header/Handler/handler.h"
#include "../../shared/boolean.h"
void startup(){
    printf("Selamat datang di Sepotipai\n"); 
    printf("jalankan \"START\" untuk memuat konfigurasi\n"); 

    char test[100]; 
    printf(">> ");
    scanf("%s", test);

    if(memcmp(test, "START", strlen(test)) == 0){
        printf("HASILNYA SAMA\n");
        prepare();
        menu(); 
    }else{
        printf("KONFIGURASI TIDAK ADA, SILAHKAN MASUKKAN ULANG");
        return;
    }
}

void prepare(){
    // CreateListDin(&((app->song)), 100);
    printf("HALO");
}

void menu(){
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
            list(subcommand);
        }
        else if(memcmp(input, "EXIT", strlen("EXIT")) == 0){
            printf("KELUAR DARI PROGRAM\n");
            break;
        }else{
            printf("PERINTAH TIDAK ADA\n"); 
        }
    }
}

void list(const char *command) {
    if (strcmp(command, "ADD") == 0) {
        printf("Melakukan operasi ADD di list()\n");
        // Add your 'ADD' functionality here
    } else if (strcmp(command, "REMOVE") == 0) {
        printf("Melakukan operasi REMOVE di list()\n");
        // Add your 'REMOVE' functionality here
    } else {
        printf("Perintah '%s' tidak dikenali dalam list()\n", command);
    }
}