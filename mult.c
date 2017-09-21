#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	for(int i=0; i<81; i++) {
		printf("%d*%d=%2d, ", i/9+1, i%9+1, (i/9+1)*(i%9+1));
		if(i%9+1==9) puts("");
	}
	return 0;
}
