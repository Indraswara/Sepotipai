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


void queueSwap(Queue *queue, int x, int y) {
    if (x <= 0 || y <= 0 || x > queue->size || y > queue->size) {
        printf("Indeks tidak valid.\n");
        return;
    }

    if (x == y) {
        printf("Tidak ada yang perlu ditukar karena kedua indeks sama.\n");
        return;
    }

    // Adjust for 1-based indexing
    x--;
    y--;

    QueueNode *currentX = queue->head;
    QueueNode *prevX = NULL;
    for (int i = 0; i < x && currentX != NULL; i++) {
        prevX = currentX;
        currentX = currentX->next;
    }

    QueueNode *currentY = queue->head;
    QueueNode *prevY = NULL;
    for (int i = 0; i < y && currentY != NULL; i++) {
        prevY = currentY;
        currentY = currentY->next;
    }

    if (currentX == NULL || currentY == NULL) {
        printf("Indeks tidak valid.\n");
        return;
    }

    // Swap the nodes
    QueueNode *temp;

    if (prevX != NULL) {
        prevX->next = currentY;
    } else {
        queue->head = currentY;
    }

    if (prevY != NULL) {
        prevY->next = currentX;
    } else {
        queue->head = currentX;
    }

    temp = currentX->next;
    currentX->next = currentY->next;
    currentY->next = temp;

    // Print appropriate messages based on what is being swapped
    if (currentX->song != NULL && currentY->song != NULL) {
        printf("Lagu \"%s\" berhasil ditukar dengan \"%s\".\n", currentX->song->songName, currentY->song->songName);
    } else if (currentX->playlist != NULL && currentY->playlist != NULL) {
        printf("Playlist \"%s\" berhasil ditukar dengan \"%s\".\n", currentX->playlist->playlistName, currentY->playlist->playlistName);
    } else {
        printf("Lagu dan playlist berhasil ditukar.\n");
    }
}

// Function to deallocate Queue
void deallocateQueue(Queue *queue) {
    while (queue->size > 0) {
        dequeue(queue);
    }
}

