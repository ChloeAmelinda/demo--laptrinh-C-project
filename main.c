#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
int main(int argc, char *argv[]) {
	// cau truc sach co san 
	  // danh sach cho book
	Book menu[100]={
	{1,"Flow","George Orwell",  "Science Fiction",24},
	{2, "Dune",  "Frank Herbert" , "Science Fiction", 89 },
	{3,"Sapi",  "Yuval Noah Harari" , "Non-Fiction    " , 48},
	{4, "Itte",  "Stephen King" , "Horror         " , 66},
	{5, "Emma", "Jane Austen"  , "Romance Novel  " , 86},
	};
	  // danh sach khach hang
	member list[100]={
	{1,"Vu Thu Trang" , "12345678", "changiuoi"},
	{2,"Krista Antony" , "0246810" ,"thich ngu "},
	{3,"chloe Amelinda" , "1357911", "hahaha"},
	{4,"Bach Phung Nghi" , "87654321", "oioioi"},
	{5,"Yuki Yamamoto" , "123454321", "8386"},
	
	};
	// khai bao bien 
	int n=5;
	int count=0; 
	int choice;
//	SaveLibraryToFile(menu, n);
	printf("**** Library management using C ****\n");
	printf("Ban co 2 lua chon :\n");
	printf("1. Quan li sach trong thu vien\n");
	printf("2. Quan li danh sach khach hang cua thu vien \n");
	printf("Moi ban nhap lua chon :");
	scanf("%d", &choice);
	if (choice==1){// cua BOOK
	
	do{
		system("cls");
		printf("**** Library management using C ****\n");
		displaymenu();
		printf("\n");
		printf("Moi ban nhap lua chon :");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printfBook( menu, n);
				GobackOrExit();
				printf("\n");
				break;
			case 2:
				addbook(menu, &n);
				SaveLibraryToFile(menu, n);
				GobackOrExit();
				
				break;
			case 3:
				updatebook(menu, n);
				SaveLibraryToFile(menu,  n);
				GobackOrExit();
			
				printf("\n");
				break;
			case 4:
				deletebook(menu, &n);
				SaveLibraryToFile(menu,  n);
				GobackOrExit();
			
				printf("\n");
				break;
			case 5: 
				foundbook(menu, n);
				GobackOrExit();
				printf("\n");
				break;
			case 6:
				sortbook(menu, n);
				GobackOrExit();
				printf("\n");
				break;
			case 7:// thoat 
				system("cls");
				printf("*********** All Book *********** \n");
				printf("Chuong trinh ket thuc \n");
				printf("Cam on quy khach da su dung dich vu !");
				printf("\n");
				break;
			default:
				printf("Loi du lieu . Xin vui long nhap lai\n");		
		}
	} while(choice !=7);
}//Quan li sach
	else if( choice == 2){ // cua KHACH HANG
	do{
		system("cls");
		printf("**** Library management using C ****\n");
		Displaymenu();
		printf("Lua chon cua ban la:");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				printfMember( list, n);
				GobackOrExit();
				
				break;
			case 2:
				addmember(list, &n);
				SaveMemberToFile(list, n);
				GobackOrExit();
				
				printf("\n");
				break;
			case 3:
				editmember( list, n);
				SaveMemberToFile(list, n);
				GobackOrExit();
			
				break;
			
			case 4:
				foundmember(list, &n);
				SaveMemberToFile(list, n);
				GobackOrExit();
				break;
			case 5:
				printf("Thoat khoi chuong trinh\n");
				printf("Cam on quy khach da su dung chuong trinh\n"); 
				break;
			default:
				printf("Loi du lieu . Xin vui long nhap lai\n");
			
		}
	}while(choice !=8);
	}// quan li khach hang

	return 0; 
}
