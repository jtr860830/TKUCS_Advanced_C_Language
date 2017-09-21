#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	for(int i=1; i<=81; i++) {
		printf("%d*%d=%2d, ", i%9==0?i/9:i/9+1, i%9==0?9:i%9, (i%9==0?i/9:i/9+1)*(i%9==0?9:i%9));
		if(i%9==0) puts("");
	}
	return 0;
}