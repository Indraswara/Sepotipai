#ifndef APP_H 
#define APP_H 

#include "./SDT/Singer/singer.h"
#include "./SDT/Playlist/playlist.h"
#include "./SDT/Queue/queue.h"

typedef struct app{
    Singers singers; 
    Playlists playlists; 
    Queue queue;
} App; 

#endif
