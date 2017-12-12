#include "stack.h"

tList* createList(void) {
	tList* pList;

	pList = (tList*)malloc(sizeof(tList));
	pList->count = 0;
	pList->head = NULL;

	return pList;
}

void handlePutOperation(tList *pList) {

	int choose;
	printf("  handlePutOperation(): which type do you want (1) score (2) ID: ");
	scanf("%d", &choose);

	if (choose == 1) {
		if (checkFreeScoreSpace()) {
			tNode* tmp = pList->head;
			tNode* createNode = (tNode*)malloc(sizeof(tNode));

			int score;
			printf("  handlePutOperation(): enter score value: ");
			scanf("%d", &score);

			getScoreSpace(&(createNode->dataPtr));
			// printf("check get space\n");
			((tTypeScore*)createNode->dataPtr)->type = choose;
			((tTypeScore*)createNode->dataPtr)->score = score;
			pList->count++;

			pList->head = createNode;
			createNode->next = tmp;
		} else {
			printf("  handlePutOperation(): score space full \n");
			return;
		}
	} else if (choose == 2) {
		if (checkFreeIdSpace()) {
			
			tNode *tmp = pList->head;
			tNode *createNode = (tNode *)malloc(sizeof(tNode));

			int id;
			printf("  handlePutOperation(): enter ID value: ");
			scanf("%d", &id);

			getIdSpace(&(createNode->dataPtr));
			// printf("check get space\n");
			((tTypeScore *)createNode->dataPtr)->type = choose;			
			((tTypeId *)createNode->dataPtr)->id = id;
			pList->count++;

			pList->head = createNode;
			createNode->next = tmp;
		} else {
			printf("  handlePutOperation(): id space full \n");
			return;
		}
	} else {
		printf("  handlePutOperation(): no such type \n");
		return;
	}

	return;
}



void handleRemoveOperation(tList *pList, int choose) {
	tNode *pNode;
	tTypeScore *pScore;
	tTypeId *pId;
	int i;

	if (pList->count == 0) {
		printf("  handlePopOperation(): nothing in list = \n");
		return;
	}
	if (choose > pList->count) {
		printf("  handlePopOperation(): exceed range = \n");
		return;
	}

	if (choose == 1) {
		pNode = pList->head;
        pList->head = pList->head->next;
        pList->count --;
	} else {
		choose --;
		tNode* pre = pList->head;
		for(i=0; i < choose-1; i++) {
			pre = pre->next;
		}

		//pre -> tmp -> ...
		tNode* tmp = pre->next;
		pNode = tmp;
       	pre->next = tmp->next;
        pList->count --;
	}

	if (((tTypeScore*)pNode->dataPtr)->type == 1) {
		pScore = (tTypeScore*)pNode->dataPtr;
		printf("  handleRemoveOperation(): removed type 1, value %d\n", pScore->score);
		returnScoreSpace(pScore->loc);
	} else {
		pId = (tTypeId*)pNode->dataPtr;
		printf("  handleRemoveOperation(): removed type 2, value %d\n", pId->id);
		returnIdSpace(pId->loc);
	}

	free(pNode);    
}

void printListContent(tList* pList) {
	int i;
	tNode* pNode = pList->head;

	printf("   printListContent(): list items -> ");
	for (i = 0; i < pList->count; i++) {
		printf("type%d ", ((tTypeScore*)pNode->dataPtr)->type);
		pNode = pNode->next;
	}
	printf("\n");
}
