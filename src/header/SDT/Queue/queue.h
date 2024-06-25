#ifndef QUEUE_H
#define QUEUE_H

#include "../Playlist/playlist.h"

typedef struct {
    const char *songName;
    const char *artistName;
    const char *albumName;
    int songID;
} Song;

typedef struct QueueNode {
    Song *song;
    Playlist *playlist;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *head;
    QueueNode *tail;
    int size;
} Queue;

void initializeQueue(Queue *queue);
void enqueueSong(Queue *queue, const char *songName, const char *artistName, const char *albumName, int songID);
void enqueuePlaylist(Queue *queue, Playlist *playlist);
void dequeue(Queue *queue);
void printQueue(Queue *queue);
void queueSwap(Queue *queue, int x, int y);
void queueRemove(Queue *queue, int id);
void queueClear(Queue *queue);
void deallocateQueue(Queue *queue);

#endif // QUEUE_H
