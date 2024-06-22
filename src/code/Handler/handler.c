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
        menu(); 
    }else{
        printf("KONFIGURASI TIDAK ADA, SILAHKAN MASUKKAN ULANG");
        return;
    }
}


void menu(){
    while(true){
        char input[100]; 
        printf(">> ");
        scanf("%s", input); 
        if(memcmp(input, "LOAD", strlen(input)) == 0){
            printf("LOAD DISINI\n");
        }
        else if(memcmp(input, "EXIT", strlen("EXIT")) == 0){
            printf("KELUAR DARI PROGRAM\n");
            break;
        }else{
            printf("PERINTAH TIDAK ADA\n"); 
        }
    }
}