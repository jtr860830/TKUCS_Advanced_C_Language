#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LIST_H
#define LIST_H

typedef struct node {
	int num;
	struct node *next;
	struct node *prev;
} tNode;

typedef struct list_head {
	int count;
	tNode *head;
	tNode *tail;
} tListHead;

void addNodeToList(tListHead* listHead, tNode* pNode, tNode* pLoc,int choose, int loc);
void deleteNodeFromList(tListHead *listHead, tNode *pTar, int loc);
void printList(tListHead *listHead);

#endif