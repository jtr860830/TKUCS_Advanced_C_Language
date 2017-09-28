#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define clear(a) memset(a,'\0',sizeof(a))
#define LEN 32
#define TOT 128

char word_array[TOT][LEN];

int read_file(void) {
	int count=0;
	int i;
	char c;
	int flag = 0;

	while(1) {
		for(i=0; i<LEN; i++) {                                  
			c = getchar();
			if(isalpha(c)) {
				word_array[count][i] = tolower(c);
				flag = 1;
			} else {
				if(flag) {
					word_array[count][i] = '\0';
					count++;
					flag = 0;                             
				}
				break;
			}
		}                                              
		if(c=='\n') {                                 
			break;
		}
	 }

	 return count;
}
																							
int main(void) {
	
		int count = 0;

		clear(word_array);
		count = read_file();
		
		for(int i=0; i<TOT; i++) {
			printf("%s ", word_array[i]);
		}
		printf ("\n============= \n\n");
				 
		// Write a sorting function to sort word_array by dictionary order
		for (int i=0, min=0; word_array[i][0]!='\0'; i++) {
			min=i;
			for(int j=i+1; word_array[j][0]!='\0'; j++) {
				if (strcmp(word_array[min], word_array[j])>0)
					min=j;
			}
			char temp[LEN];
			strcpy(temp, word_array[i]);
			
			for(int k=0; k<strlen(word_array[min])+1; k++) {
				if(k==strlen(word_array[min])) {
					word_array[i][k]='\0';
				}
				word_array[i][k] = word_array[min][k];
			}
			for(int k=0; k<strlen(temp)+1; k++) {
				if(k==strlen(temp)) {
					word_array[min][k]='\0';
				}
				word_array[min][k] = temp[k];
			}				
		}
		// and then print out
		for(int i=0; word_array[i][0]!='\0'; i++) {
			printf("%s\n", word_array[i]);
		}
		printf ("\n============= \n\n");
		
		// Write a print function to exclude duplicate word in order
		for(int i=0; word_array[i][0]!='\0'; i++) {
			if(i==0) puts(word_array[0]);
			if (i>0 && strcmp(word_array[i], word_array[i-1])!=0)
			printf("%s\n", word_array[i]);
		}
	 
		return 0;
}
