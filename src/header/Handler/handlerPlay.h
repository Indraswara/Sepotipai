#ifndef HANDLERLIST_H
#define HANDLERLIST_H 

#include "../app.h"
#include <string.h> 
#include <stdio.h>

void play(const char* command, App *app); 

void playSong(App *app); 

void playPlaylist(App *app);


#endif