#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum telecom {CHT, FET, TWN};
char* arr[4] = {"CHT", "FET", "TWN"};

typedef struct {
	char num[11];
	enum telecom tele;
} mobile;

typedef struct {
	char num[11];
	char local[3];
} landline;

typedef union {
	mobile mobileNum;
	landline landNum;
} phone;

typedef struct userData {
	char name[10];
	phone phoneNum;
	struct userData* next;
} user;

user* createUser(void);
void sort(user*);
void printResult(user*);

int main(void) {
	user* head = NULL;
	
	while (1) {
		user* temp = createUser();
		user* curr = head;
		user* tail = head;
		
		if (!head)
			head = temp;
		else {
			while (tail->next)
				tail = tail->next;
			if (temp->name[0] <= head->name[0]) {
				temp->next = head;
				head = temp;
			} else if (temp->name[0] >= tail->name[0]) {
				tail->next = temp;
			} else {
				while (curr->next) {
					if (curr->next->name[0] >= temp->name[0]) 
						break;
					curr = curr->next;
				}
				temp->next = curr->next;
				curr->next = temp;
			}
		}
		
		printf("Enter q to quit or continue: ");
		char ch[2] = {'\0', '\0'};
		scanf("%s", ch);
		if (ch[0] == 'q')
			break;
	}
	printResult(head);
	return 0;
}

user* createUser(void) {
	user* u = (user*)malloc(sizeof(user));
	printf("%s", "Please Enter your name: ");
	scanf("%s", u->name);
	
	char c[11];
	printf("%s", "Please enter your phone number: ");
	scanf("%s", c);
	if (c[1] == '9') {
		strcpy(u->phoneNum.mobileNum.num, c);
		printf("%s", "Please choose your telecom (1)CHT (2)FET (3)TWN: ");
		int choose;
		scanf("%d", &choose);
		if (choose == 1)
			u->phoneNum.mobileNum.tele = CHT;
		else if (choose == 2)
			u->phoneNum.mobileNum.tele = FET;
		else if (choose == 3)
			u->phoneNum.mobileNum.tele = TWN;
		else {
			puts("Wrong input");
		}
	} else {
		strncpy(u->phoneNum.landNum.local, c, 2);
		u->phoneNum.landNum.local[2] = '\0';
		strcpy(u->phoneNum.landNum.num, c);
	}
	
	
	u->next = NULL;
	return u;
}

void printResult(user* list) {
	puts("\nResult:\n");
	while (list != NULL) {
		printf("%s%s\n", "name: ", list->name);
		printf("%s%s\n", "phone: ", list->phoneNum.mobileNum.num);
		if (list->phoneNum.mobileNum.num[1] == '9')
			printf("%s%s\n\n", "Telecom: ", arr[list->phoneNum.mobileNum.tele]);
		else
			printf("%s%s\n\n", "Locale number: ", list->phoneNum.landNum.local);
		list = list->next;
	}
}
