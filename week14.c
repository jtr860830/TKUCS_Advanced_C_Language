#include <stdio.h>
#include <stdlib.h>

#define TOTAL 5

typedef int Int32;
typedef Int32 Buf[TOTAL];
typedef Int32 (*Comp)(Int32, Int32);

Int32 CompInc (Int32 x, Int32 y) {
    return x>=y;
}

Int32 CompDec (Int32 x, Int32 y) {
    return x<=y;
}

void bubbleSort(Buf* buf, Comp comp) {
    Int32 i, j;
    Int32 tmp;
    
    for (i = 0; i < TOTAL - 1; i++)
        for (j = 0; j < TOTAL - 1 - i; j++)
            if (comp((*buf)[j], (*buf)[j+1])) {
                tmp = (*buf)[j];
                (*buf)[j] = (*buf)[j+1];
                (*buf)[j+1] = tmp;
            }
}

void printfSortedBuf (Buf* buf) {
    Int32 i;
    for (i=0; i<TOTAL; i++) {
        printf("%d ", (*buf)[i]);
    }
    puts("");
}

Int32 main (void) {
    Int32 i, flag;
    Buf* buf = (Buf*)malloc(sizeof(Int32)*TOTAL);
    
    while (1) {
        printf("Please enter (0) increasing or (1) descesing sort: ");
        scanf("%d", &flag);
        if (flag < 0 || flag > 1) {
            printf("ERROR: no such option! \n\n");
            continue;
        }
        
        printf("  Please enter %d integers: ", TOTAL);
        for (i = 0; i < TOTAL; i++) {
            scanf("%d", &(*buf)[i]);
        }
        
        if (flag == 0) {
            bubbleSort(buf, CompInc);
        } else if (flag == 1) {
            bubbleSort(buf, CompDec);
        }
        
        printf("    Result: ");
        printfSortedBuf(buf);
        printf("\n\n");
    }
}
