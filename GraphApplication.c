//Node Stuff;


node* createNode(string name, string data){
	
	node* newNode = malloc(sizeof(node));
	strcpy(newNode->name, name);
	strcpy(newNode->data, data);
	newNode->edgeNum = 0;

	return newNode;

}

int addNode(graph* g, string name, string data){
	
	int success = 1;
	
	if(IDUnique(g, data) == 1){
		g->nodes[g->nodeNum] = createNode(name, data);
		g->nodeNum += 1;
	}
	else{
		success = 0;
	}
	
	return success;
	
}

void deleteNode(graph* g, int index){
	
	int i;
	
	node* dNode = g->nodes[index];
	
	for(i = dNode->edgeNum - 1; i >= 0; i--){
		
		deleteEdge(dNode, dNode->edges[i]);
		
	}
	
	if(index == g->nodeNum - 1){
		g->nodeNum -= 1;
		free(dNode);
	}else{
		
		for(i = index; i < g->nodeNum - 1; i++){
			
			g->nodes[i] = g->nodes[i+1];
			
		}
		
		g->nodeNum -= 1;
		free(dNode);
		
	}
	
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

//Util
int IDUnique(graph* g, string idNum){
	
	int i;
	int isUnique = 1;
	string currentIDNum;
	
	for(i=0; i<g->nodeNum; i++){
		
		strcpy(currentIDNum, g->nodes[i]->data);
		if(strcmp(currentIDNum, idNum) == 0)
			isUnique = 0;
	}
	
	return isUnique;
}


//GraphStuff;
graph* createGraph(string graphName, string initName, string initData){
	
	graph* newGraph = malloc(sizeof(graph));
	strcpy(newGraph->name, graphName);
	newGraph->nodes[0] = createNode(initName, initData);
	newGraph->rootNode = newGraph->nodes[0];
	newGraph->nodeNum = 1;
	
	return newGraph;
	
}




void addEdge(node* node1, node* node2, int weight){ //fix
	
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

void editEdge(node* node1, node* node2, int weight){ //fix
	
		node1->edgeWeights[node1->edgeNum-1] = weight;
		node2->edgeWeights[node2->edgeNum-1] = weight;
		int node1Edge = getEdgeIndex(node1, node2);
		int node2Edge = getEdgeIndex(node2, node1);
		
		node1->edgeWeights[node1Edge] = weight;
		node2->edgeWeights[node2Edge] = weight;

}

int edgeExistData(node* node1, node* node2){
	
	int i;
	int exist = 0;
	string edgeData;
	
	for(i=0; i<node1->edgeNum; i++)
	{
		strcpy(edgeData, node1->edges[i]->data);
		
		if(strcmp(edgeData, node2->data) == 0)
			exist = 1;
	}
	
	return exist;
	
}

void deleteEdge(node* node1, node* node2){
	
	int empty = 0;
	int i;
	
	if(node1->edgeNum == 0 || node2->edgeNum == 0){
		empty = 1;
	}
	
	if(!empty){
		
		int node1Edge = getEdgeIndex(node1, node2);
		int node2Edge = getEdgeIndex(node2, node1);
		
		if(node1Edge == node1->edgeNum - 1){
			node1->edgeNum -= 1;
		}else{
			
			for(i = node1Edge; i < node1->edgeNum - 1; i++){
				
				node1->edges[i] = node1->edges[i+1];
				
			}
			
			node1->edgeNum -= 1;
			
		}
		
		if(node2Edge == node2->edgeNum - 1){
			node2->edgeNum -= 1;
		}else{
			
			for(i = node2Edge; i < node2->edgeNum - 1; i++){
				
				node2->edges[i] = node2->edges[i+1];
				
			}
			
			node2->edgeNum -= 1;
			
		}
		
	}
	
}

void editNodeName(node* n, string newName){
	
	strcpy(n->name, newName);
}

void editNodeData(node* n, string newData){
	
	strcpy(n->data, newData);
	
}

int getEdgeIndex(node* node1, node* node2){ 
	
	int index;
	int done = 0;
	int i;
	
	if(node1->edgeNum == 0 || node2->edgeNum == 0){
		return -1;
	}
	
	for(i = 0; i < node1->edgeNum && !done; i++){
		
		if(node1->edges[i] == node2){
			index = i;
			done = 1;
		}
		
	}
	
	return index;
	
}

void displayGraphAsAdjacencyList(graph* g, int init){
	
	if(!init){
		return;
	}
	
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

//Return index functions
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