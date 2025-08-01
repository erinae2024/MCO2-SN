#include "QueueForGraph.c"

int returnNoRisk(node* n); //used if root node has no edge weights above 30
void printAdjacentNodes(node* n); //to be used to show students who have been in contact with specified infected student
void printRiskStudent(graph* g, string key, int type);


int returnNoRisk(node* n){
	
	int i;
	for(i=0; i<n->edgeNum; i++){
		
		if(n->edgeWeights[i] > 30)
			return 0;
	}
	return 1;
}

void printAdjacentNodes(node* n){  
	
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

void printRiskStudent(graph* g, string key, int type) {
	
	int studentFound = 1;
    int rootNodeIdx;
    int i;
    
    if(type == 1)
    	rootNodeIdx = returnNodeIdxName(g, key);
    else if(type == 2)
    	rootNodeIdx = returnNodeIdxData(g, key);
    
    
    if(rootNodeIdx == -1){
    	studentFound = 0;
    	if(type == 1)
    		printf("Error! No student with this name found in graph!\n\n");
    	else if(type == 2)
    		printf("Error! No student with this ID number found in graph!\n\n");
	}
    
    if(studentFound){
    	
    	printAdjacentNodes(g->nodes[rootNodeIdx]);
    
    	printf("----------------");
    	printf("\nList of Possibly Infected Students:\n\n");
    
   		queue* q = CreateQueue(g->nodeNum);
    	node* result[g->nodeNum];
		int resultIdx = 0;
		int visited[g->nodeNum];
		node* adjNode;
		int adjIdx;
		    
		//Initialize visited array to be filled with 0
		for(i = 0; i < g->nodeNum; i++) {
	    	visited[i] = 0;
    	}
		
	    node* rootNode = g->nodes[rootNodeIdx];
		Enqueue(q, rootNode); //Enqueue root node
	    visited[rootNodeIdx] = 1; //Mark as visited
			
	   		
	   	if(returnNoRisk(rootNode) == 1)
	   		printf("Infected student has not been in contact with another student for over 30 minutes.\n\n");
	   	else{
	   			
	   		while(QueueEmpty(q) != 1) {
	    	
			//Dequeue current node	
	    	node* currentNode = Dequeue(q);
	    	    
	    	//Only put non-root nodes into the result
		    if(currentNode != rootNode) {
			    result[resultIdx] = currentNode;
			    resultIdx++;
			            
			}
						
					for(i = 0; i < currentNode->edgeNum; i++) {
			        	
		        		adjNode = currentNode->edges[i];
		    	        adjIdx = returnNodeIdxData(g, adjNode->data);  
		            	
		            	//For each unvisited neighbor of the dequeued node
		        	    if(adjIdx != -1 && !visited[adjIdx] && currentNode->edgeWeights[i] > 30) {
		    	            visited[adjIdx] = 1;
		    	            Enqueue(q, adjNode);
		    	       	}
		    	    }	
				}	
			
			
	        	for(i = 0; i < resultIdx; i++) {
		    	    node* displayNode = result[i];
		    	    printf("%d. ", i+1);
		    	    printNodeName(displayNode);
		    	    printf(":[");
		    	    printNodeData(displayNode);
		    	    printf("]");
		    	    printf("\n");
	   			}
	    	}
	    
			printf("\n");
    
  	
	}
    
}