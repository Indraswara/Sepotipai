#ifndef HANDLER_H 
#define HANDLER_H

#include <stdio.h>
#include <string.h> 
#include "../app.h"
#include "../../header/Handler/handlerList.h"
#include "../../header/Handler/handlerPlay.h"
#include "../../header/Handler/initializer.h"
#include "../../header/Handler/handlerPlaylist.h"
#include "../../shared/boolean.h"

void startup();

void prepare(App *app); 

void menu(App *app); 

void start(); 

void play(const char* command, App *app); 

void queue(); 

void song(); 

void playlist(); 

void status(); 

void saveCommand(); 

void loadCommand(); 

void help(); 


#endif
