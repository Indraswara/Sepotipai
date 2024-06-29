#ifndef HANDLER_PLAYLIST_H 
#define HANDLER_PLAYLIST_H 

#include "../app.h"
#include <string.h> 
#include <stdio.h>

void playlistCreate(App *app); 

void playlistAdd(const char *command, App *app); 

void showPlaylistData(int id, App *app); 

void playlistDelete(App *app); 

void playlist(const char *command, App *app); 



#endif 