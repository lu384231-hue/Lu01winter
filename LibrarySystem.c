#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
struct Book{
	int id;
	char name[50];
	char author[50];
	int count;
};
struct Book books[MAX];
int bookNum = 0;

void menu(){
	printf("\n====图书馆管理系统====\n");
	printf("1.添加图书\n");
	printf("2.显示所有图书\n");
	printf("3.查询图书\n");
	printf("4.删除图书\n");
	printf("0.退出系统\n");
}
void addBook(){
	printf("输入图书编号：");
	scanf("%d",&books[bookNum].id);
	getchar();
	
	printf("输入书名：");
	scanf("%s",books[bookNum].name );
	
	printf("输入作者：");
	scanf("%s",books[bookNum].author );
	
	printf("输入数量：");
	scanf("%d",&books[bookNum].count );
	
	bookNum++;
	printf("图书添加成功！\n"); 
}
void showBooks(){
	int i;
	if(bookNum==0){
		printf("暂无图书信息！\n");
		return;
	}
	printf("\n编号\t书名\t作者\t数量\n");
	for( i=0; i<bookNum; i++){
		printf("%d\t%s\t%s\t%d\n",books[i].id,books[i].name ,books[i].author ,books[i].count );
	}
}
void searchBook(){
	char name[50];
	int i,found=0;
	printf("请输入要查询的书名：");
	scanf("%s",name);
	
	for( i=0; i< bookNum; i++){
		if(strcmp(books[i].name, name)==0){
			printf("编号：%d\n作者：%s\n数量：%d\n",books[i].id ,books[i].author ,books[i].count );
			found = 1;
			break;
		}
	}
		if(!found){
			printf("未找到该图书！\n");
	}
}
void deleteBook(){
	int id,i,j;
	printf("输入要删除的图书编号：");
	scanf("%d",&id);
	
	for( i=0; i<bookNum; i++){
		if(books[i].id == id){
			for( j=i; j<bookNum-1; j++){
				books[j] = books[j+1];
			}
			bookNum--;
			printf("图书删除成功！\n");
			return;
		}
	}
	printf("未找到该图书！\n");
}
void loadData(){
	FILE *fp = fopen("books.txt","r");
	if(fp == NULL) return;
	
	while(fscanf(fp,"%d %s %s %d",&books[bookNum].id ,books[bookNum].name ,books[bookNum].author ,&books[bookNum].count )!=EOF){
		bookNum++;
	}
	fclose(fp);
}
void saveData(){
	int i;
	FILE *fp = fopen("books.txt","w");
	for( i=0; i<bookNum; i++){
		fprintf(fp,"%d %s %s %d\n",books[i].id,books[i].name ,books[i].author ,books[i].count );
	}
	fclose(fp);
	printf("数据已保存，系统退出。\n");
}

int main(){
	int choice;
	loadData();
	do{
		menu();
		printf("请选择功能：");
		scanf("%d",&choice);
		getchar();
		
		switch(choice){
			case 1:addBook();break;
			case 2:showBooks();break;
			case 3:searchBook();break;
			case 4:deleteBook();break;
			case 0:saveData();break;
			default: printf("输入错误，请重新选择！\n");
		} 
	}while(choice!=0);
	
	return 0;
}














































