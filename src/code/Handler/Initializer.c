#include "../../header/Handler/initializer.h"


void initializer(App* app){
    // Initialize Singers and Playlists
    initializeSingers(&(app->singers));
    initializePlaylists(&(app->playlists));

    // Create an empty current song
    createEmptySong(&(app->currSong));

    // Add Singer One
    addSinger(&(app->singers), "Singer One", 10);
    addAlbum(&(app->singers.singers[0]), "First Album", 5);
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song A");
    addSongToAlbum(&(app->singers.singers[0]), "First Album", "Song B");

    // Add Singer Two
    addSinger(&(app->singers), "Singer Two", 3);
    addAlbum(&(app->singers.singers[1]), "Second Album", 3);
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song X");
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", "Song Y");

    // Add Playlists
    addPlaylist(&(app->playlists), "Workout Playlist");
    addPlaylist(&(app->playlists), "Chill Playlist");

    // Add songs to playlists
    addSongToPlaylist(&(app->playlists.playlist[0]), "Song A", "Singer One", "First Album", 1);
    addSongToPlaylist(&(app->playlists.playlist[0]), "Song X", "Singer Two", "Second Album", 1);
}

