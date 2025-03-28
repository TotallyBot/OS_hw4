#ifndef queue_h
#define queue_h
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
void initQueue(void);
void destroyQueue(void);
void enqueue(void*);
void* dequeue(void);
bool tryDequeue(void**);
size_t size(void);
size_t waiting(void);
size_t visited(void);
#endif