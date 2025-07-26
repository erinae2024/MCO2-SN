//#include "GraphApplication.h"

//Node Stuff;
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

void editEdge(node* node1, node* node2, int weight){
	
	int full = 0;
	
	if(node1->edgeNum == MAX_EDGES || node2->edgeNum == MAX_EDGES){
		full = 1;
	}
	
	if(!full){
		
		node1->edgeWeights[node1->edgeNum-1] = weight;
		node2->edgeWeights[node2->edgeNum-1] = weight;
		
	}
	
}

void editNodeData(node* n, string newData){
	
	strcpy(n->data, newData);
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
			printf("|");
			printf("%d", currentNode->edgeWeights[j]);
			printf(":[");
			printNodeData(currentNode->edges[j]);
			printf("] -> ");
			                                     
		}
		
		if(!alone){
			printf("[X]\n");
		}
		
	}
	
	printf("\n");
}

/*int main(){
	
	graph* mainGraph = createGraph("DLSU Students", "124", "Cruz, Zach B.");
	displayGraphAsAdjacencyList(mainGraph);
	
	addNode(mainGraph, "121", "Santos, Erin D.");
	displayGraphAsAdjacencyList(mainGraph);
	
	addEdge(mainGraph->nodes[0], mainGraph->nodes[1], 45);
	displayGraphAsAdjacencyList(mainGraph);
	
	editEdge(mainGraph->nodes[0], mainGraph->nodes[1], 120);
	displayGraphAsAdjacencyList(mainGraph);
	
	addNode(mainGraph, "123", "De Leon, Alaine A.");
	addEdge(mainGraph->nodes[0], mainGraph->nodes[2], 50);
	displayGraphAsAdjacencyList(mainGraph);
	
	addEdge(mainGraph->nodes[1], mainGraph->nodes[2], 88);
	displayGraphAsAdjacencyList(mainGraph);
	
	addNode(mainGraph, "001", "Sans");
	addNode(mainGraph, "002", "Papyrus");
	addEdge(mainGraph->nodes[2], mainGraph->nodes[3], 9999);
	addEdge(mainGraph->nodes[2], mainGraph->nodes[4], 0);
	displayGraphAsAdjacencyList(mainGraph);
	
	editNodeData(mainGraph->nodes[3], "Ness");
	displayGraphAsAdjacencyList(mainGraph);
	
	
	
	//addNode(mainGraph, "3", "zech");
	//displayGraphAsAdjacencyList(mainGraph);
	//addEdge(mainGraph->nodes[1], mainGraph->nodes[2], 1);
	//displayGraphAsAdjacencyList(mainGraph);
	
	
}*/