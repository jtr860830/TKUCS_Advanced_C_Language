#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *sheetRoot;

void change_row (int*, int);
void change_column (int*, int);
void printAll(int*, int);
void swap(int*, int*);

int main(int argc, char* argv[]) {
	int size = argc-2;
	sheetRoot = (int*)malloc(sizeof(int)*(size));
	
	for (int i=2; i<argc; i++) 
		*(sheetRoot+i-2) = atoi(*(argv+i));

//	for (int i=0; i<size; i++)
//		printf("%d", *(sheetRoot+i));

	printAll(sheetRoot, size);
	puts("-----------------------");
	change_row(sheetRoot, size);
	puts("-----------------------");
	change_column(sheetRoot, size);


}

void printAll(int* arr, int size) {
	for (int i=0; i<size; i++) {
		printf("%2d ", *(arr+i));
		if ((i+1)%(int)sqrt(size) == 0)
			puts("");
	}
}

void change_row(int *arr, int size) {
	for (int i=0; i<sqrt(size); i++) {
		swap(arr+i, arr+i+(int)sqrt(size)*2);
	}
	printAll(arr, size);
}

void change_column(int* arr, int size) {
	for (int i=0; i<size; i+=(int)sqrt(size)) {
		swap(arr+i, arr+i+2);
	}
	printAll(arr, size);
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
