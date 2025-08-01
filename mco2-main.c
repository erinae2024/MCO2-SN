#include"Display.c"

int main(){
	
	int on = 1;
	int choice;
	int page = 0;
	
	graph* mainGraph;
	
	ImportNodes(&mainGraph);
	ImportEdges(&mainGraph);
	
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