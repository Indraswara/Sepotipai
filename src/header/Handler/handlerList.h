#ifndef HANDLERLIST_H
#define HANDLERLIST_H 

#include "../app.h"
#include <string.h> 
#include <stdio.h>

void list(const char* command, App *app); 

void listDefault(App *app);

void listPlaylistHandler(App *app);

#endif
