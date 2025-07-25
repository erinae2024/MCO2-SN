#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 255
#define MAX_EDGES 50
#define MAX_NODES 255

typedef char string[BUFFER];
typedef struct nodeTag node;

//Node stuff;
struct nodeTag{
	
	string name;
	string data;
	int edgeNum;
	node* edges[MAX_EDGES];
	int edgeWeights[MAX_EDGES];
	
};

node* createNode(string name, string data){
	
	node* newNode = malloc(sizeof(node));
	strcpy(newNode->name, name);
	strcpy(newNode->data, data);
	newNode->edgeNum = 0;

	return newNode;

}

void printNodeName(node* n){
	
	string name;
	strcpy(name, n->name);
	printf("%s", name);
	
}

void printNodeData(node* n){
	
	string data;
	strcpy(data, n->data);
	printf("%s", data);
	
}

//GraphStuff;
struct graphTag{
	
	string name;
	node* rootNode;
	int nodeNum;
	node* nodes[MAX_NODES];
	
}; typedef struct graphTag graph;

graph* createGraph(string graphName, string initName, string initData){
	
	graph* newGraph = malloc(sizeof(graph));
	strcpy(newGraph->name, graphName);
	newGraph->nodes[0] = createNode(initName, initData);
	newGraph->rootNode = newGraph->nodes[0];
	newGraph->nodeNum = 1;
	
}

void addNode(graph* g, string name, string data){
	
	g->nodes[g->nodeNum] = createNode(name, data);
	g->nodeNum += 1;
	
}

void addEdge(node* node1, node* node2, int weight){
	
	int full = 0;
	
	if(node1->edgeNum == MAX_EDGES || node2->edgeNum == MAX_EDGES){
		full = 1;
	}
	
	if(!full){
		
		node1->edges[node1->edgeNum] = node2;
		node1->edgeWeights[node1->edgeNum] = weight;
		node1->edgeNum += 1;
		
		node2->edges[node2->edgeNum] = node1;
		node2->edgeWeights[node2->edgeNum] = weight;
		node2->edgeNum += 1;
		
	}
	
}

void displayGraphAsAdjacencyList(graph* g){
	
	int done = 0;
	int i, j;
	
	if(g->nodeNum <= 0){
		done = 1;
	}else{
		printf("Adjacency List of Graph %s:\n\n", g->name);
	}
	
	for(i = 0; i < g->nodeNum && done == 0; i++){
		
		int alone = 0;
		
		node* currentNode = g->nodes[i];
		
		if(currentNode->edgeNum <= 0){
			alone = 1;
			printf("%d. ", i + 1);
			printNodeName(currentNode);
			printf(":[");
			printNodeData(currentNode);
			printf("] -> [X]\n");
		}else{
			printf("%d. ", i + 1);
			printNodeName(currentNode);
			printf(":[");
			printNodeData(currentNode);
			printf("] -> ");
		}
		
		for(j = 0; j < currentNode->edgeNum && !alone; j++){
			
			printNodeName(currentNode->edges[j]);
			printf(":[");
			printNodeData(currentNode->edges[j]);
			printf("] -> ");
			
		}
		
		if(!alone){
			printf("[X]\n");
		}
		
	}
	
}

int main(){
	
	graph* mainGraph = createGraph("Main", "1", "hello");
	addNode(mainGraph, "2", "hiya");
	addEdge(mainGraph->nodes[0], mainGraph->nodes[1], 1);
	addNode(mainGraph, "3", "zech");
	addEdge(mainGraph->nodes[1], mainGraph->nodes[2], 1);
	displayGraphAsAdjacencyList(mainGraph);
	
}