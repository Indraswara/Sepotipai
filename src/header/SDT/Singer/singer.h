#ifndef SINGER_H 
#define SINGER_H 

#include "../../../header/SDT/Album/Album.h" // Include album.h where Album structure is defined
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    const char* singerName;
    Album* albums;  // Pointer to array of albums
    int numAlbums;  // Number of albums
    int capacity;   // Capacity of the albums array
} Singer;

typedef struct{
    Singer *singers; 
    int numSingers; 
    int capacity; 
} Singers;


//this is for singer 
void createSinger(Singer *singer, const char* name,int capacity);
void deallocateSinger(Singer *singer);
void addAlbum(Singer *singer, const char *albumName, int albumCapacity);
void addSongToAlbum(Singer *singer, const char *albumName, const char *songTitle);
void printSingerDiscography(const Singer *singer);

//this is for singers 
void initializeSingers(Singers *singers);
void addSinger(Singers *singers, const char *singerName, int capacity);
void deallocateSingers(Singers *singers); 

#endif
