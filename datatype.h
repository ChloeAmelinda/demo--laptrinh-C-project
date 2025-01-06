#include<stdbool.h>

typedef struct{
	int id ;
	char namebook[100];
	char author[100];
	char title[100];
	int price;
} Book;
typedef struct{
	int  memberId;
	char namemember[100];
	char phonemember[100];
	char status[100];
}member; 

typedef struct{
	int day, month, year;
}Date;
