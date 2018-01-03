#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL 307
#define RAWS 1000
#define RUNS 20000

typedef struct element
{
    int value;
    struct element *next;
} tElement;

typedef struct element_head
{
    int count;
    struct element *list;
} tHead;

int decide_location (int value)
{
//    int n = 0, tmp = value;
////    while (value != 0) {
////        value = value>>1;
////        n++;
////    }
//    int sum = 0;
//    //for (int i = 0; i < n; i++) {
//        sum = (sum*33 + value) % TOTAL;
//    //}
//            
//    return sum;
//    srand(time(NULL));
//    value ^= rand();
//    return value%307;
}

void put_to_table (tHead *p, int value)
{
    tElement *dest;
    
    dest = (tElement *) malloc (sizeof(tElement));
    dest->value = value;
    dest->next = p->list;
    p->list = dest;
    p->count ++;
}

void put_to_hash(tHead *pHead, int *raw)
{
	int i;
	int loc;
	  
    for (i = 0; i<RAWS; i++)
    {
        loc = decide_location(raw[i]);
        put_to_table(&pHead[loc], raw[i]);
    }
}

int hashing (void)
{
    FILE *fp;
    int max = 0, i = 0, j = 0;
    int raw[RAWS] = {0};
    tHead *pHead;
    tElement *pElement;
    
    pHead = (tHead *) malloc (sizeof(tHead)*TOTAL);
    for (i=0; i<TOTAL; i++)
    {
        pHead[i].count = 0;
        pHead[i].list = NULL;
    }
    
    fp=fopen("w16_input.txt", "r");
    i = 0;
    while (fscanf(fp, "%d", &raw[i]) != EOF)
    {
        i++;
    }
    fclose(fp);
    
    put_to_hash(pHead, raw);
    
    for (i=0; i<TOTAL; i++)
    {
        if (pHead[i].count > max)
        {
            max = pHead[i].count;
        }

        for (j=0; j<pHead[i].count; j++)
        {
            pElement = pHead[i].list;
            pHead[i].list = pElement->next;
            free(pElement);            
        }
    }

    free(pHead);
    return max;
}

int main(void)
{
    FILE *fp;
    int i, j;
    int max_values = 0;
    srand(time(NULL));
    
    for (i=0; i<RUNS; i++)
    {
        fp=fopen("w16_input.txt", "w");
        for (j=0; j<RAWS; j++)
        {
    	      fprintf (fp, "%d\n", rand());
        }
        fclose(fp);
        max_values += hashing();
    }
    
    printf("average max: %f\n", (float)max_values/RUNS);
}

