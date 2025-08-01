#include"Display.c"

int main(){
	
	int on = 1;
	int choice;
	int page = 0;
	
	int graphInit = 0;
	graph* mainGraph;
	
	while(on){
		
		system("cls");

			displayGraphAsAdjacencyList(mainGraph, graphInit);
			
			switch(page){
			
			case 0: displayMenu(&page); break;
			case 1: displayDetermine(&page, mainGraph); break; //Determine Possibly Infected Students
			case 2: mainGraph = displayImportExport(&page, mainGraph, &graphInit); break;
			case 3: displayNodeFunc(&page, mainGraph); break;
			case 4: displayEdgeFunc(&page, mainGraph); break;
			case 5: on = confirmExit(&page); break;
			default: displayMenu(&page); break;
			}	
	}
}
