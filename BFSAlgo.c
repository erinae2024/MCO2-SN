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

int returnNoRisk(node* n){
	
	int i;
	for(i=0; i<n->edgeNum; i++){
		
		if(n->edgeWeights[i] > 30)
			return 0;
	}
	return 1;
}

void printAdjacentNodes(node* n){ //to be used to show students who have been in contact with specified infected student
	
	int i;
	int alone = 0;
	
	printf("\nInfected Student -> Students Who Have Been In Contact with Infected Student:\n\n");
	
	if(n->edgeNum <= 0){
		alone = 1;
		printNodeName(n);
		printf(":[");
		printNodeData(n);
		printf("] -> [X]\n");
	}else{
		printNodeName(n);
		printf(":[");
		printNodeData(n);
		printf("] -> ");
	}
		
	for(i = 0; i < n->edgeNum && !alone; i++){
			
		printNodeName(n->edges[i]);
		printf("|");
		printf("%d", n->edgeWeights[i]);
		printf(":[");
		printNodeData(n->edges[i]);
		printf("] -> ");
		                                     
	}
		
	if(!alone){
		printf("[X]\n");
	}
		
}

void printRiskStudent(graph* g, string key) {
	
    int rootNodeIdx = returnNodeIdxData(g, key);
    
    printAdjacentNodes(g->nodes[rootNodeIdx]);
    
    printf("----------------");
    printf("\nList of Possibly Infected Students:\n\n");
    
   	queue* q = CreateQueue(g->nodeNum);
    node* result[g->nodeNum];
	int resultIdx = 0;
	int visited[g->nodeNum];
	node* adjNode;
	int adjIdx;
    
    if(rootNodeIdx != 1) {
	    
	    //Initialize array to be filled with 0
	    for(int i = 0; i < g->nodeNum; i++) {
	    	visited[i] = 0;
    	}

	    node* rootNode = g->nodes[rootNodeIdx];
	    Enqueue(q, rootNode);
	    visited[rootNodeIdx] = 1;

	   	
	   	if(returnNoRisk(rootNode) == 1)
	   		printf("Infected student has not been in contact with another student for over 30 minutes.\n\n");
	   	else{
	   		
	   		while(QueueEmpty(q) != 1) {
	    	
	        node* currentNode = Dequeue(q);
	        
	        //only put non-root nodes into the result
		        if(currentNode != rootNode) {
		            result[resultIdx] = currentNode;
		            resultIdx++;
		            
		        }
					
				for(int i = 0; i < currentNode->edgeNum; i++) {
		        	
		        	adjNode = currentNode->edges[i];
		            adjIdx = returnNodeIdxData(g, adjNode->data); // You'll need this function
		            
		            if(adjIdx != -1 && !visited[adjIdx] && currentNode->edgeWeights[i] > 30) {
		                visited[adjIdx] = 1;
		                Enqueue(q, adjNode);
		           	}
		        }	
			}	


	        for(int i = 0; i < resultIdx; i++) {
		        node* displayNode = result[i];
		        printf("%d. ", i+1);
		        printNodeName(displayNode);
		        printf(":[");
		        printNodeData(displayNode);
		        printf("]");
		        printf("\n");
	   		}
	    }
    }
    else
    	printf("Error 404: Student Not Found");
}






int main(){
	
	graph* mainGraph = createGraph("DLSU Students", "124", "Cruz, Zach B.");
	addNode(mainGraph, "121", "Santos, Erin D.");
	addEdge(mainGraph->nodes[0], mainGraph->nodes[1], 120);
	
	addNode(mainGraph, "123", "De Leon, Alaine A.");
	addEdge(mainGraph->nodes[0], mainGraph->nodes[2], 50);
	addEdge(mainGraph->nodes[1], mainGraph->nodes[2], 88);
	
	addNode(mainGraph, "001", "Sans");
	addNode(mainGraph, "002", "Papyrus");
	addEdge(mainGraph->nodes[2], mainGraph->nodes[3], 999);
	addEdge(mainGraph->nodes[2], mainGraph->nodes[4], 20);
	//displayGraphAsAdjacencyList(mainGraph);
	
	editNodeData(mainGraph->nodes[3], "Ness");
	addNode(mainGraph, "197", "Bang Chan");
	addEdge(mainGraph->nodes[3], mainGraph->nodes[5], 60);
	
	//displayGraphAsAdjacencyList(mainGraph);

	
	/*queue* mainq;
	mainq = CreateQueue(mainGraph->nodeNum);
	Enqueue(mainq, mainGraph->nodes[3]);
	Enqueue(mainq, mainGraph->nodes[4]);
	Enqueue(mainq, mainGraph->nodes[0]);
	Enqueue(mainq, mainGraph->nodes[2]);
	DisplayQueue(mainq);
	Dequeue(mainq);
	DisplayQueue(mainq);*/
	
	
/*	printRiskStudent(mainGraph, "Cruz, Zach B.");
	printRiskStudent(mainGraph, "Santos, Erin D.");
	printRiskStudent(mainGraph, "De Leon, Alaine A.");*/
	printRiskStudent(mainGraph, "Ness");
//	printRiskStudent(mainGraph, "Papyrus");
//	printRiskStudent(mainGraph, "Bang Chan");

	
}
