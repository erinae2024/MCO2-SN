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
	int edgeNum;                 //amount of adjacent nodes
	node* edges[MAX_EDGES];      //array of adjacent nodes
	int edgeWeights[MAX_EDGES];  //array of edge weights
	
};


node* createNode(string name, string data);
void deleteNode(int index);
void printNodeName(node* n);
void printNodeData(node* n);

//Graph stuff;
struct graphTag{
	
	string name;
	node* rootNode;
	int nodeNum; 				//amount of nodes
	node* nodes[MAX_NODES];     //array of nodes
	
}; typedef struct graphTag graph;

graph* createGraph(string graphName, string initName, string initData);
void addNode(graph* g, string name, string data);
void addEdge(node* node1, node* node2, int weight);
void editEdge(node* node1, node* node2, int weight);
void deleteEdge(node* node1, node* node2);
int getEdgeIndex(node* node1, node* node2);
void displayGraphAsAdjacencyList(graph* g);
void editNodeData(node* n, string newData);