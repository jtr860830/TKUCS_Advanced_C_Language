#include "stack.h"

tStack *createStack(void) {
    tStack *tmp;
    tmp = (tStack *)malloc(sizeof(tStack));
    tmp->count = 0;
    tmp->head = NULL;
    return tmp;
}

void handlePushOperation(tStack *pStack) {

    if (pStack->count >= N)
        printf("  handlePushOperation(): space full \n");
    else {
        tNode *tmp = pStack->head;
        tNode *createNode = (tNode *)malloc(sizeof(tNode));

        int score;
        printf("  handlePushOperation(): enter score value: ");
        scanf("%d", &score);

        getScoreSpace(&(createNode->dataPtr));
        // printf("check get space\n");
        (createNode->dataPtr)->score = score;
        (createNode->dataPtr)->loc = pStack->count;
        pStack->count++;
        (createNode->dataPtr)->used = 1;

        pStack->head = createNode;
        createNode->next = tmp;
    }
    return;
}

void handlePopOperation(tStack *pStack)
{
    if (pStack->count == 0) {
        printf("  handlePopOperation(): nothing in stack \n");
    } else {
        tNode *tmp = pStack->head;
        pStack->head = pStack->head->next;

        printf("  handlePopOperation(): poped value: %d\n", tmp->dataPtr->score);
        returnScoreSpace(pStack->count);

        pStack->count --;
        free(tmp);        
    }
}

void printStackContent(tStack *pStack) {
    tNode *tmp = pStack->head;
    printf("   printStackContent(): stack items -> ");

    if(tmp == NULL) return;
    do {
        printf("%d(%d) ", tmp->dataPtr->score, tmp->dataPtr->loc);
        tmp = tmp->next;
    } while (tmp != NULL);
}
