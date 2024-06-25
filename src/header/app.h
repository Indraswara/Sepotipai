#ifndef APP_H 
#define APP_H 

#include "./SDT/Singer/singer.h"
#include "./SDT/Playlist/playlist.h"
#include "./SDT/Queue/queue.h"
#include "./SDT/Song/song.h"

typedef struct app{
    Singers singers; 
    Playlists playlists; 
    Queue queue;
    Song currSong;
} App; 

#endif
