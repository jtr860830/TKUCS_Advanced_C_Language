#include "list.h"

void addNodeToList(tListHead* listHead, tNode* pNode, tNode* pLoc,int choose, int loc) {
	if (choose==1 && loc==1 && listHead->count==1) {
		pNode->next = pLoc;
		pLoc->prev = pNode;
		pLoc->next = NULL;
		listHead->count++;
		listHead->head = pNode;
	} else if (choose==1 && loc==1) {
		pNode->next = pLoc;
		pLoc->prev = pNode;
		listHead->count++;
		listHead->head = pNode;
	} else if(choose==1) {
		pNode->next = pLoc;
		pNode->prev = pLoc->prev;
		pLoc->prev->next = pNode;
		pLoc->prev = pNode;
		listHead->count++;
	} else if (choose==2 && loc==listHead->count) {
		pLoc->next = pNode;
		pNode->prev = pLoc;
		listHead->count++;
		listHead->tail = pNode;
	} else {
		pNode->next = pLoc->next;
		pLoc->next->prev = pNode;
		pLoc->next = pNode;
		pNode->prev = pLoc;
		listHead->count++;
	}
}

void deleteNodeFromList(tListHead* listHead, tNode* pTar, int loc) {
	if (loc==1 && listHead->count==1) {
		listHead->head=NULL;
		listHead->tail=NULL;
		listHead->count--;
	} else if (loc==1) {
		listHead->head = listHead->head->next;
		listHead->head->prev = NULL;
		listHead->count--;
	} else if (loc==listHead->count) {
		listHead->tail = listHead->tail->prev;
		listHead->tail->next = NULL;
		listHead->count--;
	} else {
		pTar->prev->next = pTar->next;
		pTar->next->prev = pTar->prev;
		listHead->count--;
	}
}

void printList(tListHead *listHead) {
	tNode *pNode;

	printf("\n");
	printf("count: %d \n", listHead->count);
	pNode=listHead->head;
	printf (" From head --> ");
	while (pNode != NULL) {
		printf("%d ", pNode->num);
		pNode = pNode->next;
	}   
	pNode=listHead->tail;
	printf ("\n From tail --> ");
	while (pNode != NULL) {
		printf("%d ", pNode->num);
		pNode = pNode->prev;
	}   
	printf("\n");
}