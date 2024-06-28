#include "../../header/Handler/handlerSong.h"

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
        printf("Cara menggunakan: \n"); 
        printf("SONG NEXT\n");
        printf("SONG PREV\n");
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

        printf("History Queue: \n"); 
        QueueNode *currentHistory = app->history.head;
        int posHistory = 1;
        while (currentHistory) {
            if (currentHistory->song) {
                printf("%d. %s - %s - %s\n", posHistory, currentHistory->song->artistName, currentHistory->song->songName, currentHistory->song->albumName);
            }
            currentHistory = currentHistory->next;
            posHistory++;
        }
    }

}