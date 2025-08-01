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
int addNode(graph* g, string name, string data);
void deleteNode(graph* g, int index);
void addEdge(node* node1, node* node2, int weight);
void editEdge(node* node1, node* node2, int weight);

int edgeExistData(node* node1, node* node2); //Checks if an edge exists given two nodes

void deleteEdge(node* node1, node* node2);
int getEdgeIndex(node* node1, node* node2);
void displayGraphAsAdjacencyList(graph* g, int init);
void editNodeName(node* n, string newName);
void editNodeData(node* n, string newData);

//Return index functions
int returnNodeIdxName(graph*g, string key);
int returnNodeIdxData(graph*g, string key);

//Util
int IDUnique(graph* g, string idNum); //Checks if a given ID number is unique (not existing in the graph)