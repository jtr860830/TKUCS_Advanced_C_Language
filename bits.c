#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned int int32;

int32 input = 0b00110001110;
int32 high = 6;	//max value = 31
int32 low = 4;	//min value = 0

bool checkRangeLoop();
bool checkRangeNoLoop();

int main(void) {
	printf("%s\n", checkRangeLoop()==1?"true":"False");
	printf("%s\n", checkRangeNoLoop()==1?"true":"False");
	return 0;
}

bool checkRangeLoop() {
	int32 check = 0;
	for (int i=0; i<=high; i++) {
		if (i<low) {
			check<<=1;
			//printf("%d\n", check);
		} else {
			check = (check<<1)+pow(2, low);
			//printf("%d\n", check);
		}
	}
	//printf("%d\n", check);
	return ((input&check) > 0);
}

bool checkRangeNoLoop() {
	int32 check = pow(2, high+1) - pow(2, low);
	//printf("%d\n", check);
	return ((input&check) > 0);
}