#include "../../header/SDT/Queue/queue.h"

// Function to initialize Queue
void initializeQueue(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

// Function to create a new song
Song *createSong(const char *songName, const char *artistName, const char *albumName, int songID) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    newSong->songName = strdup(songName);
    newSong->artistName = strdup(artistName);
    newSong->albumName = strdup(albumName);
    newSong->songID = songID;
    return newSong;
}

// Function to enqueue Song
void enqueueSong(Queue *queue, const char *songName, const char *artistName, const char *albumName, int songID) {
    Song *song = createSong(songName, artistName, albumName, songID);

    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->song = song;
    newNode->playlist = NULL;
    newNode->next = NULL;

    if (queue->size == 0) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        newNode->next = queue->head->next;
        queue->head->next = newNode;
        if (queue->tail == queue->head) {
            queue->tail = newNode;
        }
    }
    queue->size++;
}

// Function to enqueue Playlist
void enqueuePlaylist(Queue *queue, Playlist *playlist) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->playlist = playlist;
    newNode->song = NULL;
    newNode->next = NULL;

    if (queue->size == 0) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        newNode->next = queue->head->next;
        queue->head->next = newNode;
        if (queue->tail == queue->head) {
            queue->tail = newNode;
        }
    }
    queue->size++;
}

// Function to dequeue (remove head)
void dequeue(Queue *queue) {
    if (queue->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    QueueNode *temp = queue->head;
    queue->head = queue->head->next;
    if (temp->song) {
        free((void *)temp->song->songName);
        free((void *)temp->song->artistName);
        free((void *)temp->song->albumName);
        free(temp->song);
    }
    free(temp);

    queue->size--;
    if (queue->size == 0) {
        queue->tail = NULL;
    }
}

// Function to print Queue
void printQueue(Queue *queue) {
    QueueNode *current = queue->head;
    int pos = 1;
    while (current) {
        if (current->song) {
            printf("%d. Song: %s by %s from the album %s\n", pos, current->song->songName, current->song->artistName, current->song->albumName);
        } else if (current->playlist) {
            printf("%d. Playlist: %s\n", pos, current->playlist->playlistName);
        }
        current = current->next;
        pos++;
    }
}

// Function to deallocate Queue
void deallocateQueue(Queue *queue) {
    while (queue->size > 0) {
        dequeue(queue);
    }
}

