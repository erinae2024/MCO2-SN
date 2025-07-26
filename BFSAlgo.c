#include "QueueForGraph.c"

//
/*node* findNodeName(graph*g, string key){
	int i;
	string nodeName;
	for(i=0; i < g->nodeNum; i++){
		
		strcpy(nodeName, g->nodes[i]->name);
		
		if(strcmp(nodeName, key)==0)
			return g->nodes[i];
	}
	
	node* emptynode;
	emptynode = createNode(" ", " ");
	return emptynode;
}*/

/*node* findNodeData(graph*g, string key){
	int i;
	string nodeData;
	for(i=0; i < g->nodeNum; i++){
		
		strcpy(nodeData, g->nodes[i]->data);
		
		if(strcmp(nodeData, key)==0)
			return g->nodes[i];
	}
	
	node* emptynode;
	emptynode = createNode(" ", " ");
	return emptynode;
}*/

int returnNodeIdxName(graph*g, string key){
	int i;
	string nodeName;
	for(i=0; i < g->nodeNum; i++){
		
		strcpy(nodeName, g->nodes[i]->name);
		
		if(strcmp(nodeName, key)==0)
			return i;
	}
	
	return -1;
	
}

int returnNodeIdxData(graph*g, string key){
	int i;
	string nodeData;
	for(i=0; i < g->nodeNum; i++){
		
		strcpy(nodeData, g->nodes[i]->data);
		
		if(strcmp(nodeData, key)==0)
			return i;
	}
	
	return -1;
	
}

void printRiskStudent(graph* g, string key){
	
	int rootNodeIdx;
	int i;
	queue* q = CreateQueue(g->nodeNum);
	rootNodeIdx = returnNodeIdxData(g, key);
	
	if(rootNodeIdx!=-1){
		
		int count = 1;
		for(i=0; i<g->nodes[rootNodeIdx]->edgeNum;){

			node* currentNode = g->nodes[rootNodeIdx];
			
			if(currentNode->edgeWeights[i] > 30){
				
				printf("%d. ", count);
				printNodeName(currentNode->edges[i]);
				printf("|");
				printf("%d", currentNode->edgeWeights[i]);
				printf(":[");
				printNodeData(currentNode->edges[i]);
				printf("]");
				
				count = count+1;
				printf("\n");
			}
			
			i++;
		}
		
	}
	else
		printf("Error 404: Student Not Found");
}

int main(){
	
	graph* mainGraph = createGraph("DLSU Students", "124", "Cruz, Zach B.");
	
	addNode(mainGraph, "121", "Santos, Erin D.");
	
	
	addEdge(mainGraph->nodes[0], mainGraph->nodes[1], 45);
	
	editEdge(mainGraph->nodes[0], mainGraph->nodes[1], 120);
	
	addNode(mainGraph, "123", "De Leon, Alaine A.");
	addEdge(mainGraph->nodes[0], mainGraph->nodes[2], 50);
	
	addEdge(mainGraph->nodes[1], mainGraph->nodes[2], 88);
	
	addNode(mainGraph, "001", "Sans");
	addNode(mainGraph, "002", "Papyrus");
	addEdge(mainGraph->nodes[2], mainGraph->nodes[3], 9999);
	addEdge(mainGraph->nodes[2], mainGraph->nodes[4], 0);
	displayGraphAsAdjacencyList(mainGraph);
	
	editNodeData(mainGraph->nodes[3], "Ness");
	addNode(mainGraph, "197", "Bang Chan");
	addEdge(mainGraph->nodes[3], mainGraph->nodes[5], 60);
	
	displayGraphAsAdjacencyList(mainGraph);
	
	/*queue* mainq;
	mainq = CreateQueue(mainGraph->nodeNum);
	Enqueue(mainq, mainGraph->nodes[3]);
	Enqueue(mainq, mainGraph->nodes[4]);
	Enqueue(mainq, mainGraph->nodes[0]);
	Enqueue(mainq, mainGraph->nodes[2]);
	DisplayQueue(mainq);
	Dequeue(mainq);
	DisplayQueue(mainq);*/
	
	printRiskStudent(mainGraph, "Santos, Erin D.");
	printRiskStudent(mainGraph, "De Leon, Alaine A.");

	
	
	
}

/*		node* visited[MAX_NODES]; //visited array
		node* result[MAX_NODES]; //output
 
		queue* q = CreateQueue(g->nodeNum);
		Enqueue(q, g->nodes[rootNodeIdx]);*/