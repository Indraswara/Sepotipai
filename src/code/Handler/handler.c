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
        }else if(strcmp(input, "SONG") == 0){
            char subcommand[100]; 
            scanf("%s", subcommand); 
            songHandler(subcommand, app);

        }else if(strcmp(input, "STATUS") == 0){
            statusHandler(app);
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


void playNextSong(App *app) {
    if (app->queue.size > 0 || app->currSong.songName != NULL) {
        if (app->currSong.songName != NULL) {
            enqueueSong(&app->history, app->currSong.songName, app->currSong.artistName, app->currSong.albumName, app->currSong.songID);
        }

        if (app->queue.size > 0) {
            changeValue(&app->currSong, app->queue.head->song->songName, app->queue.head->song->artistName, app->queue.head->song->albumName, app->queue.head->song->songID);
            dequeue(&app->queue);
            printf("Memutar lagu \"%s\" oleh \"%s\"\n", app->currSong.songName, app->currSong.artistName);
        } else {
            printf("Queue kosong, memutar kembali lagu \"%s\" oleh \"%s\"\n", app->currSong.songName, app->currSong.artistName);
        }
    } else {
        printf("Tidak ada lagu yang diputar\n");
    }
}


void playPreviousSong(App *app) {
    if (app->history.size > 0) {
        if (app->currSong.songName != NULL) {
            enqueueSong(&app->queue, app->currSong.songName, app->currSong.artistName, app->currSong.albumName, app->currSong.songID);
        }

        if (app->history.head != NULL) {
            changeValue(&app->currSong, app->history.head->song->songName, app->history.head->song->artistName, app->history.head->song->albumName, app->history.head->song->songID);
            dequeue(&app->history);
            printf("Memutar lagu sebelumnya \"%s\" oleh \"%s\"\n", app->currSong.songName, app->currSong.artistName);
        } else {
            if (app->currSong.songName != NULL) {
                printf("Riwayat lagu kosong, memutar kembali lagu \"%s\" oleh \"%s\"\n", app->currSong.songName, app->currSong.artistName);
            } else {
                printf("Riwayat lagu kosong, tidak ada lagu yang diputar\n");
            }
        }
    } else {
        if (app->currSong.songName != NULL) {
            printf("Riwayat lagu kosong, memutar kembali lagu \"%s\" oleh \"%s\"\n", app->currSong.songName, app->currSong.artistName);
        } else {
            printf("Riwayat lagu kosong, tidak ada lagu yang diputar\n");
        }
    }
}



void songHandler(const char* command, App* app){
    if(strcmp(command, "NEXT") == 0){
        playNextSong(app);
    }else if(strcmp(command, "PREV") == 0){
        playPreviousSong(app);
    }
    else{
        printf("Perintah '%s' tidak dikenali dalam song.\n", command);
    }
}

void statusHandler(App* app) {
    if (app->currSong.songName == NULL) {
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n");
    } else {
        printf("Now Playing:\n%s - %s - %s\n", app->currSong.artistName, app->currSong.songName, app->currSong.albumName);
    }

    if (app->queue.size == 0) {
        printf("Queue:\nYour queue is empty.\n");
    } else {
        printf("Queue:\n");
        QueueNode *current = app->queue.head;
        int pos = 1;
        while (current) {
            if (current->song) {
                printf("%d. %s - %s - %s\n", pos, current->song->artistName, current->song->songName, current->song->albumName);
            }
            current = current->next;
            pos++;
        }
    }

}