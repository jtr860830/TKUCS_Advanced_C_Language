#include <stdio.h>
#include <stdlib.h>

typedef struct num_storage {
	int num;
	struct num_storage* next;
} tNumStorage;

typedef struct num_stor_head {
	int cnt;
	struct num_storage* head;
	struct num_storage* tail;
} tNumStorHead;

void in(tNumStorHead*, int);
void sort(tNumStorHead*);
void printList(tNumStorHead*);
tNumStorHead* merge(tNumStorHead*, tNumStorHead*);

int main(int argc, char* argv[]) {
	int temp;
	char space;
	tNumStorHead* list1 = (tNumStorHead*)malloc(sizeof(tNumStorHead));
	list1->head = NULL;
	list1->tail = NULL;
	tNumStorHead* list2	= (tNumStorHead*)malloc(sizeof(tNumStorHead));
	list2->head = NULL;
	list2->tail = NULL;
	
	while (scanf("%d%c", &temp, &space) == 2) {
		in(list1, temp);
		if (space == '\n') break;
	}
	
	while (scanf("%d%c", &temp, &space) == 2) {
		in(list2, temp);
		if (space == '\n') break;
	}
	
	puts("");
	printList(list1);
	printList(list2);
	
	merge(list1, list2);
	
	printList(merge(list1, list2));
	
	return 0;
}

void in(tNumStorHead* list, int input) {
	tNumStorage* node = (tNumStorage*)malloc(sizeof(tNumStorage));
	node->num = input;
	node->next = NULL;
	
	if (list->head == NULL) 
		list->head = node;
	else 
		list->tail->next = node;
	
	list->tail = node;
		
	list->cnt++;
	sort(list);
}

void sort(tNumStorHead* list) {
	tNumStorage *tmpPtr;
	tNumStorage *tmpNxt;
	tmpPtr = list->head;
	tmpNxt = list->head->next;

	int a, tmp;
	while(tmpNxt != NULL){
		while(tmpNxt != tmpPtr){
			if(tmpNxt->num < tmpPtr->num){
				tmp = tmpPtr->num;
				tmpPtr->num = tmpNxt->num;
				tmpNxt->num = tmp;
			}
			tmpPtr = tmpPtr->next;
		}
		tmpPtr = list->head;
		tmpNxt = tmpNxt->next;
	 }
	 list->head = tmpPtr;
}

void printList(tNumStorHead* list) {
	tNumStorage* temp = list->head;
	for(int i=0; i<list->cnt; i++) {
		printf("%d ", temp->num);
		temp = temp->next;
	}
	puts("\n------------------------\n");
}

tNumStorHead* merge(tNumStorHead* list1, tNumStorHead* list2) {
	tNumStorHead* temp = (tNumStorHead*)malloc(sizeof(tNumStorHead));
	temp->cnt = list1->cnt + list2->cnt;
	temp->head = list1->head;
	list1->tail->next = list2->head;
	sort(temp);
	return temp;
}