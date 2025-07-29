#include"Display.c"

int main(){
	
	int on = 1;
	int choice;
	int page = 0;
	
	graph* mainGraph = createGraph("DLSU Students", "Student Name", "ID Number");
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
	
	
	
	while(on){
		
		system("cls");
		
		displayGraphAsAdjacencyList(mainGraph);
		
			switch(page){
			
			case 0: displayMenu(&page); break;
			case 1: displayDetermine(&page, mainGraph);
			case 2: printf("FUNCTION IN PROGRESS"); break;
			case 3: displayNodeFunc(&page, mainGraph);
			case 4: displayEdgeFunc(&page, mainGraph);
			case 5: on = confirmExit(&page); break;
			default: displayMenu(&page); break;
			}	
	}
}

