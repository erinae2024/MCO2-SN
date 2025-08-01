#include "QueueForGraph.c"

int returnNoRisk(node* n);
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
		    
		    //Initialize array to be filled with 0
		for(i = 0; i < g->nodeNum; i++) {
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
						
					for(i = 0; i < currentNode->edgeNum; i++) {
			        	
		        		adjNode = currentNode->edges[i];
		    	        adjIdx = returnNodeIdxData(g, adjNode->data);  
		            
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


/*void exportGraph(graph* g){
	
		int rootNodeIdx = 0;
		int i;
		int done = 0;
		
  		queue* q = CreateQueue(g->nodeNum);
    	node* result[g->nodeNum];
		int resultIdx = 0;
		int visited[g->nodeNum];
		node* adjNode;
		int adjIdx;
		
		    
		    //Initialize array to be filled with 0
		    for(i = 0; i < g->nodeNum; i++) {
		    	visited[i] = 0;
    		}
			
			while(!done){
				node* rootNode = g->nodes[rootNodeIdx];
			    Enqueue(q, rootNode);
		    	visited[rootNodeIdx] = 1;
		   			
		   			while(QueueEmpty(q) != 1) {
		    		
		    	    	node* currentNode = Dequeue(q);
		    	    
				    	printNodeData(currentNode); //change this to print to file
				    	printf("\n"); //change this to print to file
				            	
						for(i = 0; i < currentNode->edgeNum; i++) {
				        	
			        		adjNode = currentNode->edges[i];
			    	        adjIdx = returnNodeIdxData(g, adjNode->data); 
			            
			        	    if(adjIdx != -1 && !visited[adjIdx]) {
			    	            visited[adjIdx] = 1;
			    	            Enqueue(q, adjNode);
			    	            
			    	            printNodeData(adjNode); //change this to print to file
			    	            printf("\n"); //change this to print to file
			    	            printf("%d\n", currentNode->edgeWeights[i]); //change this to print to file
			    	       	}
			    	    }	
					}	
				
					int unvisitedExist = 0;  
					for(i = 0; i < g->nodeNum; i++) {
					    if(visited[i] == 0) {
					        rootNodeIdx = i;
					        unvisitedExist = 1;
					        i == g->nodeNum;
					    }
					}
						if (!unvisitedExist) {
						    done = 1;
					}
			}
}*/

void ExportGraphNodes(graph* g) {
    FILE* file = fopen("GraphNodes.txt", "w");
    if (!file) {
        printf("Error creating GraphNodes.txt!\n");
        return;
    }

    // Export nodes in specified format
    fprintf(file, "%s\n", g->name);          // Graph name
    fprintf(file, "%d\n", g->nodeNum);      // Node count
    
    for (int i = 0; i < g->nodeNum; i++) {
        fprintf(file, "%s\n", g->nodes[i]->name);  // Student name
        fprintf(file, "%s\n", g->nodes[i]->data);  // Student ID
    }

    fclose(file);
    printf("Node data exported to GraphNodes.txt\n");
}



// Helper function to count total unique edges
int CountGraphEdges(graph* g) {
    int edgeCount = 0;
    int i;
    for (i = 0; i < g->nodeNum; i++) {
        for (int j = 0; j < g->nodes[i]->edgeNum; j++) {
            // Only count edge if we haven't seen it before (student1 ID < student2 ID)
            if (returnNodeIdxData(g, g->nodes[i]->edges[j]->data) > i) {
                edgeCount++;
            }
        }
    }
    return edgeCount;
}

void ExportGraphEdges(graph* g) {
    FILE* file = fopen("GraphEdges.txt", "w");
    if (!file) {
        printf("Error creating GraphEdges.txt!\n");
        return;
    }

    int rootNodeIdx = 0;
    int i;
    int done = 0;
    
    queue* q = CreateQueue(g->nodeNum);
    int visited[g->nodeNum];
    node* adjNode;
    int adjIdx;
    
    // Initialize visited array
    for(i = 0; i < g->nodeNum; i++) {
        visited[i] = 0;
    }

    // Write total edge count 
    fprintf(file, "%d\n", CountGraphEdges(g));
    
    // BFS traversal to export edges
    while(!done) {
        node* rootNode = g->nodes[rootNodeIdx];
        Enqueue(q, rootNode);
        visited[rootNodeIdx] = 1;
        
        while(QueueEmpty(q) != 1) {
            node* currentNode = Dequeue(q);
            
            for(i = 0; i < currentNode->edgeNum; i++) {
                adjNode = currentNode->edges[i];
                adjIdx = returnNodeIdxData(g, adjNode->data); 
                
                // Only export edge if we haven't seen it before (student1 ID < student2 ID)
                if(adjIdx != -1 && adjIdx > rootNodeIdx) {
                    fprintf(file, "%s\n", currentNode->data);  // Student 1 ID
                    fprintf(file, "%s\n", adjNode->data);     // Student 2 ID
                    fprintf(file, "%d\n", currentNode->edgeWeights[i]); // Weight
                }
                
                if(adjIdx != -1 && !visited[adjIdx]) {
                    visited[adjIdx] = 1;
                    Enqueue(q, adjNode);
                }
            }
        }
        
        // Check for unvisited nodes (disconnected graphs)
        int unvisitedExist = 0;  
        for(i = 0; i < g->nodeNum; i++) {
            if(visited[i] == 0) {
                rootNodeIdx = i;
                unvisitedExist = 1;
                i = g->nodeNum; // Exit loop
            }
        }
        if (!unvisitedExist) {
            done = 1;
        }
    }
    
    fclose(file);
    printf("Edge data exported to GraphEdges.txt\n");
}