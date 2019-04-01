#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2

typedef struct {
	int *data;
	int length;
}SqList;

//操作结果判定
void Response(int code) {
	switch (code) {
	case 1:
		printf("%s\n", "Success");
		break;
	case -1:
		printf("%s\n", "ERROR");
		break;
	case -2:
		printf("%s\n", "OVERFLOW");
		break;
	default:
		printf("%s\n", "Nothing in here");
		break;
	}
}//操作结果判定

int getRandomNum() {//随机数
	//srand(time(NULL));
	srand((int)time(0));
	int j=rand() % 9999999 + 1000000;
	return j;
}

int InitList(SqList *L) {//初始化顺序表 TODO::填充数据
	L->data = (int*)malloc(MAXSIZE * sizeof(int));
	if (!L->data) { return OVERFLOW; }
	else { 
	L->length = 0;
	for (int i = 0; i < 4; i++) {
		L->data[i] = getRandomNum() + i;
		++L->length;
	}
	return OK;
	}
}

void PrintList(SqList *L)
{
	printf("\n");
	for (int i = 0; i < L->length; i++)
	{
		printf("No.%d  data is %d\n", i + 1, L->data[i]);
	}
	menu(L);
}

void InsertList(SqList *L) { //向第i项插入一条数据
	int i;
	printf("\n要在第几项插入一条数据？\n");
	scanf("%2d", &i);
	if ((i < 0) || (i > L->length)) { return ERROR; }
	if (L->length == MAXSIZE) { return ERROR; }
	for (int j = L->length - 1; j >= i - 1; j--) {
		L->data[j + 1] = L->data[j];
	}
	L->data[i - 1] = getRandomNum();
	++L->length;
	printf("\n插入");
	Response(OK);
	menu(L);
}

void getDatabyNo(SqList *L) {
	int no;
	printf("\n输入第n项进行查找：\n");
	scanf("%3d", &no);
	if ((no < 0) || (no > L->length)) { return ERROR; }
	else {
		printf("%d", L->data[no - 1]);
	}
	menu(L);
}

int getNobyData(SqList *L) {
	int data;
	printf("\n输入数据进行查找：\n");
	scanf("%7d", &data);
	for (int i = 0; i < L->length; i++) {
		if (data == L->data[i]) {
			printf("the Data %d is No.%d", data, i+1);
		}
		else{
			printf("cannot find Data %d", data);
		}
	}
	menu(L);
}

void DeleteElem(SqList *L) {
	int no;
	printf("\n输入第n项进行删除：\n");
	scanf("%3d", &no);
	if ((no < 0) || (no > L->length)) { return ERROR; }
	for (int i = no; i <= L->length; i++) {
		L->data[i - 1] = L->data[i];
	}
	--L->length;
	menu(L);
}

int menu(SqList *L) {
	printf("\n---------------------------------\n");
	printf("输入序号进行选择：\n");
	printf("1.打印顺序表L所有元素\n");
	printf("2.向顺序表L中插入一条记录\n");
	printf("3.输入No对顺序表L现有记录进行查找\n");
	printf("5.删除一条记录\n");
	printf("6.退出\n");
	printf("---------------------------------\n");
	int op = 0;
	scanf("%d", &op);
	switch (op) {
		case 1:PrintList(L); break;
		case 2:InsertList(L); break;
		case 3:getDatabyNo(L); break;
		case 4:getNobyData(L); break;
		case 5:DeleteElem(L); break;
		case 6:exit(0);
		default:menu(L); break;
	}
	return 0;
}

void main(){
	SqList L;
	printf("顺序表初始化 ");
	Response(InitList(&L));
	printf("\n已向表内填充了5条数据\n");
	menu(&L);
}
