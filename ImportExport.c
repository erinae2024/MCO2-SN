#include "BFSAlgo.c"

void ImportNodes(graph** g) {
    FILE* file = fopen("GraphNodes.txt", "r");
    if (!file) {
        printf("Error opening GraphNodes.txt\n");
        return;
    }

    string graphName, name, data;
    int nodeCount;
    int i;

    // Read graph name 
    fscanf(file, " %[^\n]", graphName);
    
    // Read node count
    fscanf(file, "%d", &nodeCount);

    // Create first node (initializes graph)
    fscanf(file, " %[^\n]", name);
    fscanf(file, " %[^\n]", data);
    *g = createGraph(graphName, name, data);

    // Add remaining nodes
    for ( i = 1; i < nodeCount; i++) {
        fscanf(file, " %[^\n]", name);
    	fscanf(file, " %[^\n]", data);
        addNode(*g, name, data);
    }

    fclose(file);
    printf("Imported %d nodes from GraphNodes.txt\n", nodeCount);
}

void ImportEdges(graph** g) {
    if (!g || !*g) return;

    FILE* file = fopen("GraphEdges.txt", "r");
    if (!file) {
        printf("Error: GraphEdges.txt not found\n");
        return;
    }

    string id1, id2;
    int edgeCount, weight;
    int i;

    fscanf(file, "%d", &edgeCount);

    for ( i = 0; i < edgeCount; i++) {
        fscanf(file, "%s", id1); //ID Number of Student 1
        fscanf(file, "%s", id2); //ID Number of Student 2
        fscanf(file, "%d", &weight); //Edge weight / Time of contact between them (in minutes)
        int idx1 = returnNodeIdxData(*g, id1);
        int idx2 = returnNodeIdxData(*g, id2);
        
        if (idx1 != -1 && idx2 != -1) {
            addEdge((*g)->nodes[idx1], (*g)->nodes[idx2], weight);
        }
    }

    fclose(file);
    printf("Imported %d edges from GraphEdges.txt\n", edgeCount);
}

void ExportGraphNodes(graph* g) {
    FILE* file = fopen("GraphNodes.txt", "w");
    if (!file) {
        printf("Error creating GraphNodes.txt!\n");
        return;
    }


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