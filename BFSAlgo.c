#include "QueueForGraph.c"

int main(){
	
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
	
	queue* mainq;
	mainq = CreateQueue(mainGraph->nodeNum);
	Enqueue(mainq, mainGraph->nodes[3]);
	Enqueue(mainq, mainGraph->nodes[4]);
	Enqueue(mainq, mainGraph->nodes[0]);
	Enqueue(mainq, mainGraph->nodes[2]);
	DisplayQueue(mainq);
	Dequeue(mainq);
	DisplayQueue(mainq);
	
	
	
	
	
}