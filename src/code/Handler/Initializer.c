#include "../../header/Handler/initializer.h"


void initializer(App* app){
    initializeSingers(&(app->singers));   // Initialize singers
    initializePlaylists(&(app->playlists)); // Initialize playlists

    // Example: Adding singers dynamically
    printf("SINGER, ALBUM, SONG\n");
    addSinger(&(app->singers), "Singer One", 10);  // Example capacity 10 for first singer
    addAlbum(&(app->singers.singers[0]), "First Album", 5);
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song A");
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song B");

    addSinger(&(app->singers), "Singer Two", 3);  // Example capacity 3 for second singer
    addAlbum(&(app->singers.singers[1]), "Second Album", 3);
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song X");
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song Y");

    // Example: Adding playlists dynamically

    printf("PLAYLIST\n");
    addPlaylist(&(app->playlists), "Workout Playlist");
    addPlaylist(&(app->playlists), "Chill Playlist");
}