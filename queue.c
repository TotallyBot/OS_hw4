#include "queue.h"
#include <stdlib.h>
#include <threads.h>
typedef struct Node{
    void *data;
    struct Node *next;
}Node;

typedef struct Queue {
    Node *front;
    Node *back;
    size_t size;
}queue;

static queue q;

void initQueue(void) {
    q.front = q.back = NULL;
    q.size = 0;
}
void destroyQueue(void) {
    while(q.front != NULL) {
        Node *tmp = q.front;
        q.front = q.front->next;
        free(tmp);
    }
    q.size = 0;
    q.back = NULL;
}

void enqueue(void* Data) {
    Node *newElem = (Node *)malloc(sizeof(Node));
    newElem->data = Data;
    newElem->next = NULL;
    if(q.front == NULL) {
        q.front = q.back = newElem;
    }
    else {
        q.back->next = newElem;
        q.back = newElem;
    }
    q.size++;
}
void* dequeue(void) {

    return NULL;
}

bool tryDequeue(void** data) {
    if(q.front != NULL) {
        Node *temp = q.front;
        *data = q.front->data;
        q.front = q.front->next;
        if(q.front == NULL) {
            q.back = NULL;
        }
        free(temp);
        q.size--;
        return true;
    }
    return false;
}
size_t size(void) {
    return q.size;
}
size_t waiting(void) {
    return 0;
}
size_t visited(void) {

    return 0;
}