#include"datatype.h"
#include<string.h>
// nguyen mau ham
  // quan li sach 
void displaymenu();
void printfBook(Book menu[] , int n);
void addbook(Book menu[], int *n);
void updatebook(Book menu[], int n);
void deletebook(Book menu [], int *n);
void sortbook(Book menu [], int n);
void foundbook(Book menu [], int n); 
void CheckDataOfBook(Book menu [], int n); 
void SaveLibraryToFile(Book menu [], int n);
void LoadLibraryFromFile(Book menu [], int *n);
void GobackOrExit();
  // quan li khach hang
void Displaymenu();
void printfMember(member list[], int n);
void addmember(member list[], int *n);
void updatemember(member list[], int n);
void foundmember(member list[], int *n);
void blockmember(member list[], int n);
void SaveMemberToFile(member list[], int n);
void LoadMemberFromFile(member list[], int *n);

