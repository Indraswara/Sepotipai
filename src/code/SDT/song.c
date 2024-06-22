#include "../../header/SDT/Song/song.h"
#include <string.h>  // For string manipulation functions

void addSong(ListDin *songList, const char *songName) {
    // Insert the new song into the songList
    insertLast(songList, songName);
}

void deleteSong(ListDin *songList, const char *songName) {
    IdxType idx;
    boolean found = false;

    // Search for the songName in the songList
    for (idx = 0; idx < listLength(*songList); idx++) {
        if (strcmp(ELMT(*songList, idx), songName) == 0) {
            // Song found, delete it
            deleteLast(songList, &ELMT(*songList, idx));
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Song '%s' not found.\n", songName);
    }
}

// You can add more functions related to songs here if needed
