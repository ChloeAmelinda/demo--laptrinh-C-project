#include<stdio.h>
#include"function.h"
#include<string.h>
#include<stdlib.h>
//logic ham 
  // ham quan li sach
void displaymenu(){
	printf("------Menu-------\n");
	printf("1. Hien thi danh sach trong thu vien \n");
	printf("2. Them sach vao thu vien \n");
	printf("3. Sua thong tin sach trong thu vien \n");
	printf("4. Xoa sach trong thu vien \n");
	printf("5. Tim kiem thong tin sach \n");
	printf("6. Sap xep sach theo gia tien \n");
	printf("7. Thoat khoi chuong trinh  \n");

}
void printfBook(Book menu[], int n){
	system("cls");
	printf("*********** All Book *********** \n");
	printf("| id     |         name        |       author              |     title             |     price |    \n");
	int i;
	for(i=0; i<n ; i++){
		printf("| %d\t |%-20s |    %-18s     |   %-15s     |     %d    |\n", menu[i].id , menu[i].namebook , menu[i].author, menu[i].title , menu[i].price);

	}
}
int  information( char *str) {
    return strlen(str) > 0;
}
int  length( char *str, int maxLength) {
    return strlen(str) <= maxLength;
}
int  titleDuped(Book menu[], int n, char *title) {
	int i;
    for ( i = 0; i < n; i++) {
        if (strcmp(menu[i].namebook, title) == 0) {
            return 1;
        }
    }
    return 0; 
}
void addbook(Book menu[], int *n) {
    system("cls"); 
    
    printf("**** Library management using C ****\n");
     menu[*n].id=*n+1;
    do{
	printf("Them ten sach vao thu vien :");
	fflush(stdin);
	fgets(menu[*n].namebook, sizeof(menu[*n].namebook) , stdin);
	menu[*n].namebook[strcspn(menu[*n].namebook, "\n")] = 0; 
	if (!information(menu[*n].namebook)){
			printf("Ten sach trong\n");
		} else if(!length(menu[*n].namebook, 50)){
			printf("Ten sach qua dai\n");
		} else if(titleDuped(menu, *n, menu[*n].namebook)){
			printf("Ten sach da ton tai\n");
		} else {
			break;
		}
	}while(1);
    printf("Them ten tac gia vao thu vien : ");
    fflush(stdin); 
    fgets(menu[*n].author, sizeof(menu[*n].author), stdin);
    menu[*n].author[strcspn(menu[*n].author, "\n")] = 0; 

    printf("Nhap the loai sach vao thu vien: ");
    fflush(stdin); 
    fgets(menu[*n].title, sizeof(menu[*n].title), stdin);
    menu[*n].title[strcspn(menu[*n].title, "\n")] = 0; 

    printf("Nhap gia tien cua sach: ");
    scanf("%d", &menu[*n].price); 
	(*n)++;

	
}
void updatebook(Book menu[], int n){
	system("cls");
	printf("**** Library management using C ****\n");

	int position;
	printf("Moi ban nhap vao vi tri muon update:");
	scanf("%d", &position);
	int findIndex=-1;
	int i; 
	
	for( i=0 ;i<n; i++){
		if(menu[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Khong tim thay sach de update \n");
		printf("Ban da nhap khong dung id cua sach. Vui long nhap lai");
	} else{
		// hien thi danh sach truoc khi sua
		printf("| id     |         name        |       author              |     title             |     price |    \n");
		printf("| %d\t |%-20s |    %-18s     |   %-15s     |     %d    |\n", 
			   menu[position-1].id , menu[position].namebook ,
			    menu[position-1].author,
				 menu[position-1].title ,
				  menu[position-1].price);
		getchar();
		printf("Moi ban nhap vao ten sach : \n");
		fgets(menu[findIndex].namebook, 100, stdin);
		menu[findIndex].namebook[strcspn(menu[findIndex].namebook, "\n")] = '\0';
		
		printf("Moi ban nhap vao ten tac gia  : \n");
		fgets(menu[findIndex].author, 100, stdin);
		menu[findIndex].author[strcspn(menu[findIndex].author, "\n")] = '\0';
		
		printf("Moi ban nhap vao ten the loai : \n");
		fgets(menu[findIndex].title, 100, stdin);
		menu[findIndex].title[strcspn(menu[findIndex].title, "\n")] = '\0';
		
		printf("Moi ban nhap vao gia tien : \n");
		scanf("%d", &menu[findIndex].price);
		}
}
void deletebook(Book menu [], int *n){
	system("cls");
	printf("**** Library management using C ****\n");

	int position;
	printf("Moi ban nhap vao id muon xoa:");
	scanf("%d", &position);
	int findIndex=-1;
	int i;
	for( i=0;i<*n;i++){
		if(menu[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Khong tim thay sach de xoa");
		printf("Ban da nhap khong dung id cua sach. Vui long nhap lai"); 
	}else{
		for(i=findIndex;i<*n;i++){
			menu[i]=menu[i+1];
		}
		(*n)=*n -1;
		printf("%d ", *n);
	}
	// gan lai id moi cho sach 
	for (i = 0; i < *n; i++) {
        menu[i].id = i + 1; 
    }
}
void sortbook(Book menu[], int n){
	system("cls");
	int choice; 
	printf("**** Library management using C ****\n");
	printf("1.Tang dan\n");
	printf("2.Giam dan \n");
	printf("Lua chon cua ban la:");
	scanf ("%d", &choice);
	int i,j;
	if(choice == 1){
		for ( i=0; i<n; i++){ //tang dan
			for( j =i+1; j<n ;j++){
				if(menu[i].price > menu[j].price){
					Book temp=menu[i];
					menu[i]=menu[j];
					menu[j]=temp;
				}
			}
		}
		printf("Sap xep thanh cong\n");
	}// tang dan
	else if(choice ==2 ){
		for ( i=0; i<n; i++){ //giam dan
			for( j =i+1; j<n ;j++){
				if(menu[i].price < menu[j].price){
					Book temp=menu[i];
					menu[i]=menu[j];
					menu[j]=temp;
				}
			}
		}
	printf("Sap xep thanh cong\n");
	}// giam  dan
}
void foundbook(Book menu [], int n){
	system("cls");
	printf("**** Library management using C ****\n");

	char ten[100];
	int found=0;
	printf("nhap ten sach can tim: ");
	scanf("%s",ten); 
	int i;
    for( i = 0; i < n; i++){
        if(strstr(menu[i].namebook ,ten) !=NULL){
        	printf("| id     |         name          |       author              |     title             |     price  |    \n");
       		printf("| %d\t |%-20s |    %-18s     |   %-15s     |     %d    |\n", 
			   menu[i].id , menu[i].namebook ,
			    menu[i].author,
				 menu[i].title ,
				  menu[i].price);
			found=1;
            break;
        }
    }
    if(found == 0){
        printf("Khong tim thay ten sach ban vua nhap\n");
        printf("Ban da nhap sai id. Vui long nhap lai !");
    }
}
void SaveLibraryToFile(Book menu [], int n){

	// Mo file 
	FILE *ptr=fopen("LibraryData.dat","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	fwrite(menu,sizeof(Book),n,ptr);
	printf("Luu thong tin thanh cong");
	// Dong file 
	fclose(ptr);
}
void LoadLibraryFromFile(Book menu [], int *n){
	int i;
	// Mo file 
	FILE *ptr = fopen("LibraryData.dat", "rb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}else{
	Book readBook[100];
	*n=fread(readBook,sizeof(Book),100,ptr);
	
	printf("Lay Du Lieu Thanh Cong\n");
	// Dong file 
	fclose(ptr);
	}
}
void GobackOrExit(){

	int pick;
	printf("\n");
	printf("1. Quay lai \n");
	printf("2. Thoat khoi toan man hinh  \n");
	printf("Lua chon cua ban la:");
	scanf("%d",&pick);
	
	if(pick ==1 ){// neu chon 1
		system("cls");
	}
	if(pick == 2){// neu chon 2
		system("cls");
		printf("*********** All Book *********** \n");
		printf("Cam on ban da su dung chuong trinh\n");
		exit(0); 
	}
	while(pick<0 && pick>3){
		printf("Nhap sai . Xin vui long nhap lai\n");
	}
}
  // ham quan li khach hang
void Displaymenu(){
	printf("------Menu-------\n");
	printf("1.Hien thi danh sach khach hang cua thu vien\n");
	printf("2.Them khach hang vao thu vien \n");
	printf("3.Sua thong tin khach hang \n");
	printf("4.Tim kiem khach hang theo ten \n");
	printf("5.Thoat khoi chuong trinh \n");
}
void printfMember( member list[], int n){
	system("cls");
	int i;
	printf("************* All Member*************\n");
	printf("|id      | name                | phone           | status     \n");
	for(i=0; i<n; i++){
		printf("| %d      | %-20s| %-16s|%-20s  \n", list[i].memberId,
				list[i].namemember, 
				list[i].phonemember,
				list[i].status);
	}
}
void addmember(member list[], int *n){
	system("cls");
	printf("**** Library management using C ****\n");
	list[*n].memberId=*n+1;
	
	printf("Them ten khach hang vao thu vien :");
	fflush(stdin);
	fgets(list[*n].namemember, sizeof(list[*n].namemember) , stdin);
	list[*n].namemember[strcspn(list[*n].namemember, "\n")] = 0; 
	
	printf("Them so dien thoai khach hang :");
	fflush(stdin);
	fgets(list[*n].phonemember, sizeof(list[*n].phonemember) , stdin);
	list[*n].phonemember[strcspn(list[*n].phonemember, "\n")] = 0; 
	
	printf("Them the status cua khach hang :");
	fflush(stdin);
	fgets(list[*n].status, sizeof(list[*n].status) , stdin);
	list[*n].status[strcspn(list[*n].status, "\n")] = 0; 
	(*n)++;
}
void editmember(member list[], int n){
	system("cls");
	printf("**** Library management using C ****\n");
	int position;
	printf("Moi ban nhap vao vi tri muon update:");
	scanf("%d", &position);
	int findIndex=-1;
	int i; 
	for( i=0 ;i<n; i++){
		if(list[i].memberId==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Khong tim thay khach hang de sua \n");
		printf("Ban da nhap khong dung id cua khach. Vui long nhap lai");
	} else{
		printf("|id      | name                | phone           | status     \n");
		printf("| %d      | %-20s| %-16s|%-20s  \n", list[position-1].memberId,
				list[position-1].namemember, 
				list[position-1].phonemember,
				list[position-1].status);
		getchar();
		printf("Moi ban nhap vao ten khach : \n");
		fgets(list[findIndex].namemember, 100, stdin);
		list[findIndex].namemember[strcspn(list[findIndex].namemember, "\n")] = '\0';
		
		printf("Moi ban nhap vao so dien thoai  : \n");
		fgets(list[findIndex].phonemember, 100, stdin);
		list[findIndex].phonemember[strcspn(list[findIndex].phonemember, "\n")] = '\0';
		
		}
}
void foundmember(member list[], int *n){
	system("cls");
	printf("**** Library management using C ****\n");
	char  ten[100];
	int found=0;
	printf("nhap ten khach hang can tim: ");
	getchar();
	scanf("%s", ten);
	int i;
    for( i = 0; i < *n; i++){
        if(strstr(list[i].namemember , ten) != NULL){
       		printf("| %d      | %s               | %s           |%s  \n", list[i].memberId,
				list[i].namemember, 
				list[i].phonemember,
				list[i].status);
			found=1;
            break;
        }
    }
    if(found == 0){
        printf("Khong tim thay ten khach hang vua nhap \n");
        printf("Ban da nhap sai id. Vui long nhap lai !");
    }
}
void SaveMemberToFile(member list[], int n){
	// Mo file 
	FILE *ptr=fopen("LibraryData.dat","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}
	fwrite(list,sizeof(member),n,ptr);
	printf("Luu thong tin thanh cong");
	// Dong file 
	fclose(ptr);
}
void LoadMemberFromFile(member list[], int *n){
	int i;
	// Mo file 
	FILE *ptr = fopen("LibraryData.dat", "rb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file");
	}else{
	member readmember[100];
	*n=fread(readmember,sizeof(member),100,ptr);
	
	printf("Lay Du Lieu Thanh Cong\n");
	// Dong file 
	fclose(ptr);	
	}
}
