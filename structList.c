#include <stdio.h>
#include <stdlib.h>

typedef struct num_list {
	int counts;
	int* pList;
} numList;

void bubbleSort(numList*);
void merge(numList*, numList*);
void swap(int*, int*);

int main(int argc, char* argv[]) {
	numList* list1;
	numList* list2;
	
	list1 = (numList*)malloc(sizeof(numList));
	list2 = (numList*)malloc(sizeof(numList));
	
	printf("%s", "plz enter how many numbers in list1: ");
	scanf("%d", &list1->counts);
	list1->pList = malloc(sizeof(int)*list1->counts);
	for (int i=0; i<list1->counts; i++)
		scanf("%d", list1->pList+i);
	bubbleSort(list1);
	puts("\n------------------------------");
	
	printf("%s", "plz enter how many numbers in list2: ");
	scanf("%d", &list2->counts);
	list2->pList = malloc(sizeof(int)*list2->counts);
	for (int i=0; i<list2->counts; i++)
			scanf("%d", list2->pList+i);
	bubbleSort(list2);
	puts("\n------------------------------");
	for (int i=0; i<list1->counts; i++)
		printf("%d ", list1->pList[i]);
	puts("");
	for (int i=0; i<list2->counts; i++)
		printf("%d ", list2->pList[i]);
	puts("\n------------------------------");
	
	merge(list1, list2);
	
	return 0;
}

void bubbleSort(numList* list) {
	for (int i=0; i<list->counts-1; i++)
		for (int j=0; j<list->counts-1-i; j++)
			if (list->pList[j] > list->pList[j+1]) {
				swap(list->pList+j, list->pList+j+1);
			}
}

void merge(numList* list1, numList* list2) {
	numList temp;
	temp.counts = list1->counts+list2->counts;
	temp.pList = (int*)malloc(sizeof(int)*(temp.counts));
	for (int i=0; i<temp.counts; i++) {
		if (i >= list1->counts) {
			temp.pList[i] = list2->pList[i-list1->counts];
		} else {
			temp.pList[i] = list1->pList[i];
		}
	}
	bubbleSort(&temp);
	for (int i=0; i<temp.counts; i++)
		printf("%d ", temp.pList[i]);
}

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}