#include "main.h"

int main(void) {
	int choose;
	tListHead *listHead;
	
	listHead = (tListHead*)malloc(sizeof(tListHead));
	listHead->head = NULL;
	listHead->tail = NULL;
	listHead->count = 0;
	
	while (1) {
		printf ("1. Add a number or 2. Delete a number: ");
		scanf ("%d", &choose);
		if (choose == 1) {
			processAdd(listHead);
		}
		else if (choose == 2) {
			processDel(listHead);
		}
		else {
			printf ("  No such choose !\n");
			continue;
		}        	
		printf ("\n");
	}
}

void processAdd(tListHead *listHead) {
	int num, loc, choose;
	tNode *pNode, *pLoc = listHead->head;
	  
	printf (" Add a number: ");
	scanf ("%d", &num);
	pNode = (tNode*)malloc(sizeof(tNode));
	pNode->num = num;
	pNode->next = NULL;
	pNode->prev = NULL;
	
	if (listHead->count>0 && pLoc!=NULL) {
		do {
			printf ("  Specify a target location: ");
			scanf ("%d", &loc);
			if (loc > listHead->count || loc < 1) {
				printf ("    Exceed current list size %d or <= 0\n", listHead->count);
			}
			else {
				for (int i=0; i<loc-1; i++)
					pLoc = pLoc->next;
				break;
			}
		} while(1);
		do {
			printf ("  1. Before or 2. After the location %d: ", loc);
			scanf ("%d", &choose);
			if (choose > 2 || choose < 1) {
				printf ("    No such choose\n");
			} else {
				addNodeToList(listHead, pNode, pLoc, choose, loc);
				break;
			}
		} while(1);    
	} else {
		listHead->head = pNode;
		listHead->tail = pNode;
		listHead->count++;
	}

	printList(listHead);
}

void processDel(tListHead* listHead) {
	int loc;
	tNode* pTar = listHead->head;
	
	if (listHead->count == 0) {
		printf ("  Nothing to delete.\n");
		return;
	}
	
	do {
		printf ("  Specify a target location: ");
		scanf ("%d", &loc);
		if (loc > listHead->count || loc < 1) {
			printf ("    Exceed current list size %d or <= 0\n", listHead->count);
		}
		else {
			for (int i=0; i<loc-1; i++)
				pTar = pTar->next;
			break;
		}
	} while(1);
	
	deleteNodeFromList(listHead, pTar, loc);
	printList(listHead);
}