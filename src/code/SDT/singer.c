
#include "../../header/SDT/Singer/singer.h"

void createSinger(Singer *singer, int capacity) {
    singer->albums = malloc(capacity * sizeof(Album));
    if (singer->albums == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    singer->numAlbums = 0;
    singer->capacity = capacity;
}

void deallocateSinger(Singer *singer) {
    if (singer->albums != NULL) {
        for (int i = 0; i < singer->numAlbums; ++i) {
            deallocateAlbum(&(singer->albums[i]));
        }
        free(singer->albums);
        singer->albums = NULL;
        singer->numAlbums = 0;
        singer->capacity = 0;
    }
}

void addAlbum(Singer *singer, const char *albumName, int albumCapacity) {
    if (singer->numAlbums < singer->capacity) {
        createAlbum(&(singer->albums[singer->numAlbums]), albumName, albumCapacity);
        singer->numAlbums++;
    } else {
        fprintf(stderr, "Singer's album collection is full.\n");
    }
}

void addSongToAlbum(Singer *singer, const char *albumName, const char *songTitle) {
    // Find the album by name and add the song
    for (int i = 0; i < singer->numAlbums; ++i) {
        if (strcmp(singer->albums[i].name, albumName) == 0) {
            insertSong(&(singer->albums[i]), songTitle);
            return;
        }
    }
    fprintf(stderr, "Album '%s' not found.\n", albumName);
}

void printSingerDiscography(const Singer *singer) {
    printf("Singer's Discography:\n");
    for (int i = 0; i < singer->numAlbums; ++i) {
        printf("Album %d:\n", i + 1);
        printAlbumSongs(&(singer->albums[i]));
        printf("\n");
    }
}

//this is for singers 

void initializeSingers(Singers *singers){
    singers->singers = NULL;
    singers->numSingers = 0;
    singers->capacity = 0;
}

void addSinger(Singers *singers, int capacity) {
    // Allocate more memory if needed
    if (singers->numSingers >= singers->capacity) {
        int newCapacity = (singers->capacity == 0) ? 1 : singers->capacity * 2; // Double the capacity
        Singer *newSingers = realloc(singers->singers, newCapacity * sizeof(Singer));
        if (newSingers == NULL) {
            printf("Alokasi gagal\n");
        }
        singers->singers = newSingers;
        singers->capacity = newCapacity;
    }
    
    // Create the new singer
    createSinger(&singers->singers[singers->numSingers], capacity);
    singers->numSingers++;
    printf("Singer berhasil ditambahkan\n");
}


void deallocateSingersingers(Singers *singers) {
    if (singers->singers != NULL) {
        for (int i = 0; i < singers->numSingers; ++i) {
            deallocateSinger(&singers->singers[i]);
        }
        free(singers->singers);
        singers->singers = NULL;
    }
    singers->numSingers = 0;
    singers->capacity = 0;
}
