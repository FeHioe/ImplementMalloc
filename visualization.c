/**
    CSC209 A2 Spring 2015
    visualization.c
    Purpose: Visualizes the structs used in A2 of CSC209 

    @author Samir Patel
    @version 1.0 24/02/15
*/

extern struct block *allocated_list;
extern struct block *freelist;
void print_list_display(struct block *list, char* name){
	if (list == NULL){
		printf("        ---------------------------\n        -                         -\n        -                         -\n        -                         -\n        -                         -\n        -          NULL           -\n        -                         -\n        -                         -\n        ---------------------------\n");
	}
	int i = 0;
	while(list != NULL){
		if (i > 0 && list->next != NULL){
		printf("        ---------------------------\n       -                           -\n        ---------------------------\n        - Address: %p -\n        ---------------------------\n        -  Size: %d               -\n        ---------------------------\n        -                         -\n        ---------------------------\n", list->addr, list->size);
		}
		else if(i>0 && list ->next == NULL){
			printf("        ---------------------------\n        -                         -\n        ---------------------------\n        - Address: %p -\n        ---------------------------\n        -  Size: %d               -\n        ---------------------------\n        -         NULL            -\n        ---------------------------\n", list->addr, list->size);
		}
		else if (list->next != NULL){
printf("        ---------------------------\n        -        %s         -\n        ---------------------------\n        - Address: %p -\n        ---------------------------\n        -  Size: %d               -\n        ---------------------------\n        -                         -\n        ---------------------------\n",name, list->addr, list->size);
		}
		else{
			printf("        ---------------------------\n        -        %s         -\n        ---------------------------\n        - Address: %p -\n        ---------------------------\n        -  Size: %d               -\n        ---------------------------\n        -         NULL            -\n        ---------------------------\n",name, list->addr, list->size);
		}
	list = list->next;
	i++;
	if (list != NULL){
		printf("                     |\n                     |\n                     |\n                     V\n");
	}
}
printf("\n");
}

void print_free_display(){
	print_list_display(freelist, "FreeList");
}

void print_allocated_display(){
	print_list_display(allocated_list, "Alocated");
}

