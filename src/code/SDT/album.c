#include "../../header/SDT/Album/Album.h"

// Function to create an album with given name and initial capacity
void createAlbum(Album *album, const char *name, int capacity) {
    album->name = strdup(name); // Allocate memory for album name
    album->songs = malloc(capacity * sizeof(const char*)); // Allocate memory for songs array
    album->capacity = capacity;
    album->size = 0; // Initially no songs in the album
}

// Function to deallocate memory used by an album
void deallocateAlbum(Album *album) {
    free((char*)album->name); // Free memory for album name
    free(album->songs);       // Free memory for songs array
    album->capacity = 0;      // Reset capacity
    album->size = 0;          // Reset size
}

// Function to insert a song into the album
void insertSong(Album *album, const char *songTitle) {
    if (album->size < album->capacity) {
        album->songs[album->size++] = strdup(songTitle); // Add song to the end of songs array
    } else {
        printf("Album is full, cannot add more songs.\n");
    }
}

// Function to print all songs in the album
void printAlbumSongs(const Album *album) {
    printf("Album: %s\n", album->name);
    printf("Songs:\n");
    for (int i = 0; i < album->size; ++i) {
        printf("- %s\n", album->songs[i]);
    }
}
