#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define num_len   12
#define array_len 10
int cnt=0;

int btod(char* s) {
    for (int i=0; i<strlen(s); i++) {
        if (s[i] > '1' || s[i] < '0')
            return 0;
    }
    return strtol(s, NULL, 2);
}

int xtod(char* s) {
    for (int i=0; i<strlen(s); i++) {
        s[i] = toupper(s[i]);
    }
    for (int i=0; i<strlen(s); i++) {
        if (s[i] > 'F' || s[i] < '1')
            return 0;
    }
    return strtol(s, NULL, 16);
}

int dtod(char* s) {
    for (int i=0; i<strlen(s); i++) {
        if (s[i] < '0' || s[i] > '9')
            return 0;
    }
    return atoi(s);
}

void pushin(char* s, int* num, int (*num_for)(char*)) {
    if (num_for(s)) {
        *num = num_for(s);
        cnt++;
    } else {
        puts("wrong input");
        return;
    }
        
}


void printAll(int* arr, int n) {
    for (int i=0; i<n; i++)
        printf("%d, ", arr[i]);
    puts("");
    return;
}

int main(void) {
	char s_buf[num_len];
    int num_array[array_len] = {0};
    
    int (*translate)(char*) = NULL;
    
    while(1) {
        
        printf("Enter a number (prefix, x:16, d:10, b:2) (-1 to End): ");
        scanf("%s", s_buf);
        
        if (strcmp(s_buf, "-1")==0)
            break;

        switch (s_buf[0]) {
        	case 'x':
                translate = xtod;
                break;
            case 'b':
                translate = btod;
                break;
            case 'd':
                translate = dtod;
                break;
            default:
                puts("wrong input");
                continue;
        }
        
        pushin(&s_buf[1], num_array+cnt, translate);
        printf("Numbers in array: ");
        printAll(num_array, cnt);
    }

    return 0;
}