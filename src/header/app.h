#ifndef APP_H 
#define APP_H 

#include "./SDT/Song/song.h"
#include "./SDT/Album/Album.h"

typedef struct app{
    ListDin song;  
    ListDin album;
} App; 

#endif