#include "../../header/Handler/initializer.h"


void initializer(App* app) {
    // Initialize Singers and Playlists
    initializeSingers(&(app->singers));
    initializePlaylists(&(app->playlists));

    // Create an empty current song
    createEmptySong(&(app->currSong));
    //create empty Queue
    initializeQueue(&(app->queue));
    initializeQueue(&(app->history));

    // Add Singer One
    addSinger(&(app->singers), "Singer One", 10);
    addAlbum(&(app->singers.singers[0]), "First Album", 5);
    Song* songA = createSong("Song A", "Singer One", "First Album", 1);
    Song* songB = createSong("Song B", "Singer One", "First Album", 2);
    addSongToAlbum(&(app->singers.singers[0]), "First Album", songA);
    addSongToAlbum(&(app->singers.singers[0]), "First Album", songB);

    // Add Singer Two
    addSinger(&(app->singers), "Singer Two", 3);
    addAlbum(&(app->singers.singers[1]), "Second Album", 3);
    Song* songX = createSong("Song X", "Singer Two", "Second Album", 3);
    Song* songY = createSong("Song Y", "Singer Two", "Second Album", 4);
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", songX);
    addSongToAlbum(&(app->singers.singers[1]), "Second Album", songY);

    // Add Playlists
    addPlaylist(&(app->playlists), "Workout Playlist");
    addPlaylist(&(app->playlists), "Chill Playlist");

    // Add songs to playlists
    addSongToPlaylist(&(app->playlists.playlist[0]), "Song A", "Singer One", "First Album", 1);
    addSongToPlaylist(&(app->playlists.playlist[0]), "Song X", "Singer Two", "Second Album", 3);
}

