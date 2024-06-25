#include "../../header/Handler/initializer.h"


void initializer(App* app){
    initializeSingers(&(app->singers));
    initializePlaylists(&(app->playlists));

    addSinger(&(app->singers), "Singer One", 10);
    addAlbum(&(app->singers.singers[0]), "First Album", 5);
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song A");
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song B");

    addSinger(&(app->singers), "Singer Two", 3);
    addAlbum(&(app->singers.singers[1]), "Second Album", 3);
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song X");
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song Y");

    addPlaylist(&(app->playlists), "Workout Playlist");
    addPlaylist(&(app->playlists), "Chill Playlist");

    // Example of adding songs to playlists after initialization
    addSongToPlaylist(&(app->playlists.playlist[0]), "Song A", "Singer One", "First Album", 1);
    addSongToPlaylist(&(app->playlists.playlist[0]), "Song X", "Singer Two", "Second Album", 1);

}
