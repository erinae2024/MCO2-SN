#include"Display.c"

int main(){
	
	int on = 1;
	int choice;
	int page = 0;
	
	graph* mainGraph = createGraph("DLSU Students", "Student Name", "ID Number");
	addNode(mainGraph, "ERIN", "121");
	addEdge(mainGraph->nodes[0], mainGraph->nodes[1], 120);
	
	addNode(mainGraph, "De Leon, Alaine A.", "123");
	addEdge(mainGraph->nodes[0], mainGraph->nodes[2], 50);
	addEdge(mainGraph->nodes[1], mainGraph->nodes[2], 88);
	
	addNode(mainGraph, "Sans", "001");
	addNode(mainGraph, "Papyrus", "002");
	addEdge(mainGraph->nodes[2], mainGraph->nodes[3], 999);
	addEdge(mainGraph->nodes[2], mainGraph->nodes[4], 20);
	//displayGraphAsAdjacencyList(mainGraph);
	
	editNodeName(mainGraph->nodes[3], "Ness");
	addNode(mainGraph, "Bang Chan", "197");
	
	addNode(mainGraph, "Lee Felix", "921");
	addNode(mainGraph, "Han Jisung", "008");
	addNode(mainGraph, "Seo Changbin", "009");
	addNode(mainGraph, "Lee Know", "010");
	addNode(mainGraph, "Kim Seungmin", "011");
	addNode(mainGraph, "Yang Jeongin", "012");
//	addNode(mainGraph, "Ness", "010"); //LIMITATION: IF THERE ARE TWO NODES WITH SAME NAME, BFSALGO WILL DO THE FIRST INSTANCE OF THE NAME
	addEdge(mainGraph->nodes[3], mainGraph->nodes[5], 60);

	addEdge(mainGraph->nodes[7], mainGraph->nodes[6], 60);
	addEdge(mainGraph->nodes[6], mainGraph->nodes[8], 60);
	addEdge(mainGraph->nodes[6], mainGraph->nodes[9], 60);
	addEdge(mainGraph->nodes[10], mainGraph->nodes[6], 60);
	addEdge(mainGraph->nodes[11], mainGraph->nodes[6], 60);
	
//	exportGraph(mainGraph);
	
	
	while(on){
		
		system("cls");
		
		displayGraphAsAdjacencyList(mainGraph);
		
			switch(page){
			
			case 0: displayMenu(&page); break;
			case 1: displayDetermine(&page, mainGraph); break;
			case 2: displayImportExport(&page, mainGraph); break;
			case 3: displayNodeFunc(&page, mainGraph); break;
			case 4: displayEdgeFunc(&page, mainGraph); break;
			case 5: on = confirmExit(&page); break;
			default: displayMenu(&page); break;
			}	
	}
}

/*todo: 
- bfs to get all edges
*/