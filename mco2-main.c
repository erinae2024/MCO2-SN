#include"Display.c"

int main(){
	
	int on = 1;
	int choice;
	int page = 0;
	
	graph* mainGraph = createGraph("DLSU Students", "Student Name", "ID Number");
	addNode(mainGraph, "Santos, Erin D.", "121");
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
	addNode(mainGraph, "Ness", "010"); //LIMITATION: IF THERE ARE TWO NODES WITH SAME NAME, BFSALGO WILL DO THE FIRST INSTANCE OF THE NAME
	addEdge(mainGraph->nodes[3], mainGraph->nodes[5], 60);
	
	/*string name;
	
	printf("Enter student's name: ");
	scanf(" %[^\n]", name);
	
	printf("You entered: %s\n", name);
	printf("%d", returnNodeIdxName(mainGraph, name)); */
	
	while(on){
		
		system("cls");
		
		displayGraphAsAdjacencyList(mainGraph);
		
			switch(page){
			
			case 0: displayMenu(&page); break;
			case 1: displayDetermine(&page, mainGraph); break;
			case 2: printf("FUNCTION IN PROGRESS"); break;
			case 3: displayNodeFunc(&page, mainGraph); break;
			case 4: displayEdgeFunc(&page, mainGraph); break;
			case 5: on = confirmExit(&page); break;
			default: displayMenu(&page); break;
			}	
	}
}

