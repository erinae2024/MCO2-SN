#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphApplication.h"

struct queueTag{
	int headIndex;
	int tailIndex;
	int queueSize;
	node* nodes[];
};

typedef struct queueTag queue;



queue* CreateQueue(int size);
int Enqueue(queue* q, node* n);
node* Dequeue(queue* q);
node* QueueHead(queue* q);
node* QueueTail(queue* q);
int QueueEmpty(queue* q);
int QueueFull(queue* q);
void DisplayQueue(queue *q);

