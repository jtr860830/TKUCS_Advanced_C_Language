#include <stdio.h>
#include <stdlib.h>

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

void processDel(tListHead *listHead) {
    int loc;
    tNode *pTar = listHead->head;
    
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

    printList(listHead);
}

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
