#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"QueueForGraph.h" //QueueForGraph.h has GraphApplication.h
#include"GraphApplication.c"

queue* CreateQueue(int size){
	
	queue *q = malloc((sizeof(int) * 3) + (sizeof(node) * size));
	
	q->headIndex = 0;
	q->tailIndex = 0;
	q->queueSize = size;
	
	return q;
	
}

int Enqueue(queue* q, node* n){

	if (!QueueFull(q))
	{
		q->nodes[q->tailIndex % q->queueSize] = n;
	
		q->tailIndex += 1;
		return 1;
	}
	else
		return -1;
}

node* Dequeue(queue* q){
	
	if(q->headIndex == q->tailIndex){
		node* emptynode;
		emptynode = createNode(" ", " ");
		return emptynode;
	}
	
	node* n;
	n = q->nodes[q->headIndex];
	
	q->headIndex += 1;
	
	if(q->headIndex == q->queueSize){
		q->headIndex -= q->queueSize;
		q->tailIndex -= q->queueSize;
	}	
	
	return n;
}

node* QueueHead(queue* q){
	
	if(q->headIndex == q->tailIndex){
		node* emptynode;
		emptynode = createNode(" ", " ");
		return emptynode;
	}
	
	node* n;
	n = q->nodes[q->headIndex];
	
	return n;
}

node* QueueTail(queue* q){
	
	if(q->headIndex == q->tailIndex){
		node* emptynode;
		emptynode = createNode(" ", " ");
		return emptynode;
	}
	
	node* n;
	n = q->nodes[q->tailIndex];
	
	return n;
}

int QueueEmpty(queue* q){
	
	if(q->headIndex == q->tailIndex){
		return 1;
	}
	
	return 0;
	
}

int QueueFull(queue* q){
	
	if((q->headIndex == q->tailIndex % q->queueSize) && (q->headIndex != q->tailIndex)){
		return 1;
	}
	
	return 0;
	
}

void DisplayQueue(queue *q)
{
	int i;
	
	printf("\nDisplaying Queue:\n");
	
	for(i = q->headIndex; i < q->tailIndex; i++)
	{
		printNodeName(q->nodes[i]);
		printf(":[");
		printNodeData(q->nodes[i]);
		
		if(i == q->tailIndex-1)
			printf("]");
		else
			printf("], ");
	}
	
	printf("\n");
}
