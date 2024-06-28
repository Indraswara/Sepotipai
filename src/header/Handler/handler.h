#ifndef HANDLER_H 
#define HANDLER_H

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "../app.h"
#include "../../header/Handler/handlerList.h"
#include "../../header/Handler/handlerPlay.h"
#include "../../header/Handler/initializer.h"
#include "../../header/Handler/handlerPlaylist.h"
#include "../../header/Handler/handlerSong.h"
#include "../../header/Handler/handlerQueue.h"
#include "../../shared/boolean.h"

void startup();

void menu(App *app); 

void saveCommand(); 

void loadCommand(); 

void help(); 


#endif
