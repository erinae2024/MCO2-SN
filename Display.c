#include "BFSAlgo.c"

void printOptions(int count, string optionsStr[], int space){
	
	for(int i = 0; i < count; i++){
		
		printf("[%d] %s\n", i + 1, optionsStr + i);
		
		if(i == count - 1 && space == 1){
			printf("\n");
		}
		
	}
	
}

int getInput(int min, int max){
	
	int choice;
	int done = 0;
	
	
	while(!done){
		
		printf("Please enter the number of your chosen option: ");
		scanf("%d", &choice);
	
		if(choice < min || choice > max){
			printf("Invalid Option!\n\n");
		}else{
			done = 1;
		}
		
	}
	
	return choice;
	
}

int getInputCustom(int min, int max, string str){
	
	int choice;
	int done = 0;
	
	
	while(!done){
		
		printf("%s", str);
		scanf("%d", &choice);
	
		if(choice < min || choice > max){
			printf("Invalid Option!\n\n");
		}else{
			done = 1;
		}
		
	}
	
	return choice;
	
}

void displayMenu(int *page){ //0
	
	printf("Contact Tracing Program\n\n");
	
	string options[5] = {"Determine Possibly Infected Students", "Import/Export Graph", "Add/Edit/Delete Node", "Add/Edit/Delete Edge", "Quit"};
	
	printOptions(5, options, 1);
	*page = getInput(1,5);
	
}

void displayDetermine(int *page, graph* g){ //1

	int choice = 0;
	string input;		
	
	system("cls");

	
	printf("Enter student's name: ");
	scanf("%s", input);
	
	printRiskStudent(g, input);
	
	printf("[1] Back to Main Menu\n");
	printf("Please enter the number of your chosen option: ");
	scanf("%d", &choice);
	if(choice == 1)
		*page = 0;
	
	
}

void displayNodeFunc(int* page, graph* g){ //3
	
	int on = 1;
	int subpage = 0;
	int choice;
	string name;
	string data;
	string newName;
	int nodeIdx;



		while(on){
		
		system("cls");
		
		switch(subpage){
			
			case 0: printf("Add/Edit/Delete Node Menu\n\n");
					string options0[4] = {"Add Node", "Edit Node Data", "Delete Node", "Back to Main Menu"};
					printOptions(4, options0, 1);
					scanf("%d", choice);
					choice = getInput(1, 4);
					if(choice == 4)
						*page = 0;
					else
						subpage = choice;
					break;
					
					
			case 1: printf("Add Node Menu\n\n");
					printf("Enter student's name: ");
					scanf("%s", name);
					printf("\nEnter the student's ID number: ");
					scanf("%s", data);
					addNode(g, name, data);
					subpage = 0;
					break;
			
			case 2: printf("Edit Node Menu\n\n");
					string options2[2] = {"Edit Node Name", "Edit Node Data"};
					printOptions(2, options2, 1);
					choice = getInput(1,2);
					
					if(choice == 1){
						printf("Enter the original name of student: ");
						scanf("%s", name);
						nodeIdx = returnNodeIdxName(g, name);
						printf("\nEnter new name of student: ");
						scanf("%s", newName);
						editNodeName(g->nodes[nodeIdx], newName);
						subpage = 0;
					}
					
					else if(choice == 2){
						printf("Enter the original ID number of student: ");
						scanf("%s", data);
						nodeIdx = returnNodeIdxData(g, data);
						printf("\nEnter ID number of student: ");
						scanf("%s", newName);
						editNodeData(g->nodes[nodeIdx], newName);
						subpage = 0;						
					}
					break;

					
					
			case 3: printf("Delete Node Menu\n\n");
					printf("Choose input type:\n");
					string options3[2] = {"Student Name", "Student ID Number"};
					printOptions(2, options3, 1);
					choice = getInput(1,2);
					
					if(choice == 1){
						printf("Enter name of student: ");
						scanf("%s", name);
						nodeIdx = returnNodeIdxName(g, name);
						deleteNode(g, nodeIdx);
						subpage = 0;
					}
					
					else if(choice == 2){
						printf("Enter the ID number of student: ");
						scanf("%s", data);
						nodeIdx = returnNodeIdxData(g, data);
						deleteNode(g, nodeIdx);
						subpage = 0;						
					}
					break;
		}
		
	}
	
}

void displayEdgeFunc(int* page, graph* g){
	
	int choice = 0;
	string node1;
	string node2;
	int nodeIdx1;
	int nodeIdx2;
	int weight;
	
	string options;
	
	int on = 1;
	int subpage = 0;
	
		while(on){
		
		system("cls");
		
		switch(subpage){
			
			case 0: printf("Add/Edit/Delete Edge Menu\n\n");
					string options0[4] = {"Add Edge", "Delete Edge", "Edit Edge Weight", "Back to Main Menu"};
					printOptions(4, options0, 1);
					scanf("%d", choice);
					choice = getInput(1, 4);
					if(choice == 3)
						*page = 0;
					else
						subpage = choice;
					break;
					
					
			case 1: printf("Add Edge Menu\n\n");
			        printf("Choose input type:\n");
					string options1[2] = {"Student Names", "Student ID Numbers"};
					printOptions(2, options1, 1);
					choice = getInput(1,2);
					
					if(choice == 1){
						printf("Enter name of first student: ");
						scanf("%s", node1);
						nodeIdx1 = returnNodeIdxName(g, node1);
						printf("\nEnter name of second student: ");
						scanf("%s", node2);
						nodeIdx2 = returnNodeIdxName(g, node2);
						printf("Enter time both students have been in contact (in minutes): ");
						scanf("%d", weight);
						addEdge(g->nodes[nodeIdx1], g->nodes[nodeIdx2], weight);
						subpage = 0;
					}
					
					else if(choice == 2){
						printf("Enter ID number of first student: ");
						scanf("%s", node1);
						nodeIdx1 = returnNodeIdxData(g, node1);
						printf("\nEnter ID number of second student: ");
						scanf("%s", node2);
						nodeIdx2 = returnNodeIdxData(g, node2);
						printf("Enter time both students have been in contact (in minutes): ");
						scanf("%d", weight);
						addEdge(g->nodes[nodeIdx1], g->nodes[nodeIdx2], weight);
						subpage = 0;
					}
					break;
			
			case 2: printf("Delete Edge Menu\n\n");
			        printf("Choose input type:\n");
					string options2[2] = {"Student Names", "Student ID Numbers"};
					printOptions(2, options2, 1);
					choice = getInput(1,2);
					
					if(choice == 1){
						printf("Enter name of first student: ");
						scanf("%s", node1);
						nodeIdx1 = returnNodeIdxName(g, node1);
						printf("\nEnter name of second student: ");
						scanf("%s", node2);
						nodeIdx2 = returnNodeIdxName(g, node2);
						deleteEdge(g->nodes[nodeIdx1], g->nodes[nodeIdx2]);
						subpage = 0;
					}
					
					else if(choice == 2){
						printf("Enter ID number of first student: ");
						scanf("%s", node1);
						nodeIdx1 = returnNodeIdxData(g, node1);
						printf("\nEnter ID number of second student: ");
						scanf("%s", node2);
						nodeIdx2 = returnNodeIdxData(g, node2);
						deleteEdge(g->nodes[nodeIdx1], g->nodes[nodeIdx2]);
						subpage = 0;
					}
					break;	
			
			case 3: printf("Edit Edge Weight Menu\n\n");
			        printf("Choose input type:\n");
					string options3[2] = {"Student Names", "Student ID Numbers"};
					printOptions(2, options3, 1);
					choice = getInput(1,2);
					
					if(choice == 1){
						printf("Enter name of first student: ");
						scanf("%s", node1);
						nodeIdx1 = returnNodeIdxName(g, node1);
						printf("\nEnter name of second student: ");
						scanf("%s", node2);
						nodeIdx2 = returnNodeIdxName(g, node2);
						printf("Enter new time both students have been in contact (in minutes): ");
						scanf("%d", weight);
						editEdge(g->nodes[nodeIdx1], g->nodes[nodeIdx2], weight);
						subpage = 0;
					}
					
					else if(choice == 2){
						printf("Enter ID number of first student: ");
						scanf("%s", node1);
						nodeIdx1 = returnNodeIdxData(g, node1);
						printf("\nEnter ID number of second student: ");
						scanf("%s", node2);
						nodeIdx2 = returnNodeIdxData(g, node2);
						printf("Enter new time both students have been in contact (in minutes): ");
						scanf("%d", weight);
						editEdge(g->nodes[nodeIdx1], g->nodes[nodeIdx2], weight);
						subpage = 0;
					}
					break;

		}
		
	}
	
}

int confirmExit(int *page){
	
	system("cls");
	printf("Are you sure you want to exit the program?\n[1] Yes\n[2] No\n\n");
	
	int choice = getInput(1,2);
	
	if(choice == 1){
		return 0;
	}else{
		*page = 0;
		return 1;
	}
}

