#ifndef APP_H 
#define APP_H 

#include "./SDT/Singer/singer.h"
#include "./SDT/Playlist/playlist.h"

typedef struct app{
    Singers singers; 
    Playlists playlists; 
} App; 

#endif
