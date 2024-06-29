#ifndef HANDLER_QUEUE_H 
#define HANDLER_QUEUE_H
#include "../app.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>

void queue(const char* command, App *app);

void queueSong(App *app);

void queuePlaylist(App *app);


#endif
