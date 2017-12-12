#include "space.h"

tTypeScore scoreBuf[N]; //preallocated memory space
unsigned char scoreBitmap = 0x0; // 0 is empty, 1 is set

tTypeId idBuf[N]; //preallocated memory space
unsigned char idBitmap = 0x0;

int checkFreeScoreSpace(void) {
    if (scoreBitmap == 0xF)
        return 0;
    else
        return 1;
}

void getScoreSpace(void** ppScore) {
    int i;
    for (i = 0; i < N; i++) {
        // printf("check i = %d\n", i);
        if (TEST_BIT(scoreBitmap, i) == 0)
            break;
    }

    *ppScore = (void*)&scoreBuf[i];
    scoreBuf[i].loc = i;
    SET_BIT(scoreBitmap, i);

    printf("     getScoreSpace(): giving space numbered %d, result bitmap 0x%x\n", i, scoreBitmap);

    return;
}

void returnScoreSpace(int loc) {
    CLEAR_BIT(scoreBitmap, loc);
    printf("     returnScoreSpace(): return space numbered %d, result bitmap 0x%x\n", loc, scoreBitmap);
}

int checkFreeIdSpace(void) {
    if (idBitmap == 0xF)
        return 0;
    else
        return 1;
}

void getIdSpace(void** ppId) {
    int i;
    for (i = 0; i < N; i++) {
        // printf("check i = %d\n", i);
        if (TEST_BIT(idBitmap, i) == 0)
            break;
    }

    *ppId = (void*)&idBuf[i];
    idBuf[i].loc = i;    
    SET_BIT(idBitmap, i);

    printf("     getIdSpace(): giving space numbered %d, result bitmap 0x%x\n", i, idBitmap);

    return;
}

void returnIdSpace(int loc) {
    CLEAR_BIT(idBitmap, loc);
    printf("     returnIdSpace(): return space numbered %d, result bitmap 0x%x\n", loc, idBitmap);
}
