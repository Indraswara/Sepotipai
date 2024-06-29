
#ifndef HANDLER_SONG_H
#define HANDLER_SONG_H
#include "../app.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>


void playNextSong(App *app);
void playPreviousSong(App *app);
void songHandler(const char* command, App* app);
void statusHandler(App* app);


#endif