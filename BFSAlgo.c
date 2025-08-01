#include "QueueForGraph.c"

int returnNoRisk(node* n);
void printAdjacentNodes(node* n); //to be used to show students who have been in contact with specified infected student
void printRiskStudentName(graph* g, string key);
void printRiskStudentData(graph* g, string key);

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

void printRiskStudentName(graph* g, string key) {
	
	int studentFound = 1;
    int rootNodeIdx;
    
    rootNodeIdx = returnNodeIdxName(g, key);
    
    if(rootNodeIdx == -1){
    	printf("Error! No student with this name found in graph!\n\n");
    	studentFound = 0;
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
		    	        adjIdx = returnNodeIdxData(g, adjNode->data);  
		            
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
	    
			printf("\n");
	    
    
  	
	}
    
}

void printRiskStudentData(graph* g, string key) {
	
	int studentFound = 1;
    int rootNodeIdx;
    
    rootNodeIdx = returnNodeIdxData(g, key);
    
    if(rootNodeIdx == -1){
    	printf("Error! No student with this ID number found in graph!\n\n");
    	studentFound = 0;
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
		    	        adjIdx = returnNodeIdxData(g, adjNode->data); 
		            
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
	    
			printf("\n");
	    
    	
  	
	}
    
}

void exportGraph(graph* g){
	
		int rootNodeIdx = 0;
		
  		queue* q = CreateQueue(g->nodeNum);
    	node* result[g->nodeNum];
		int resultIdx = 0;
		int visited[g->nodeNum];
		node* adjNode;
		int adjIdx;
		    
		    //Initialize array to be filled with 0
		    for(int i = 0; i < g->nodeNum; i++) {
		    	visited[i] = 0;
    		}
		
		    node* rootNode = g->nodes[rootNodeIdx];
		    Enqueue(q, rootNode);
	    	visited[rootNodeIdx] = 1;
	   			
	   			while(QueueEmpty(q) != 1) {
	    		
	    	    	node* currentNode = Dequeue(q);
	    	    
			    	result[resultIdx] = currentNode;
			   	 	resultIdx++;
			            	
					for(int i = 0; i < currentNode->edgeNum; i++) {
			        	
		        		adjNode = currentNode->edges[i];
		    	        adjIdx = returnNodeIdxData(g, adjNode->data); 
		            
		        	    if(adjIdx != -1 && !visited[adjIdx]) {
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
	    
			printf("\n");
}
