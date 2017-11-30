#include "space.h"

tTypeScore scoreBuf[N]; //preallocated memory space

void getScoreSpace(tTypeScore **ppScore) {
    int i;
    for(i=0; i < N; i++){
        // printf("check i = %d\n", i);
        if(scoreBuf[i].used == 0) break;
    }


    *ppScore = &scoreBuf[i];

    printf("     getScoreSpace(): giving space numbered %d\n", i);

    return;
}

void returnScoreSpace(int loc) {
    scoreBuf[loc].used = 0;
    printf("     returnScoreSpace(): return space numbered %d\n", loc);
}
