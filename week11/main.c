#include "stack.h"

int main(void) {

    tStack *pStack = createStack();
    int choose;

    while (1) {
        printf("\n(1) push or (2) pop a item to/from stack: ");
        scanf("%d", &choose);

        if (choose == 1) {
            handlePushOperation(pStack);
        } else if (choose == 2) {
            handlePopOperation(pStack);
        }

        printStackContent(pStack);
    }

    return 0;
}
