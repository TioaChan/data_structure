#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define MAXSIZE 200  //图书表可能达到的最大长度
typedef int Status;

//顺序表的顺序存储结构
typedef struct { //图书信息定义
	char no[50];
	char name[100];
}Book;

typedef struct {
	Book *elem;  //存储空间的基地址
	int length;  //图书表长度
}SqList;//顺序表的顺序存储结构

typedef Book ElemType;

//操作结果判定
void Response(Status code) {
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

//初始化顺序表
Status InitList(SqList *L) { //C语言中&表示的不是引用，而是取地址符
	L->elem = (Book*)malloc(MAXSIZE * sizeof(Book));
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;
	return OK;
}//初始化顺序表

//插入
Status CreatElement(SqList *L) {
	int i;
	char no[50];
	char name[100];
	printf("输入图书的ISBN号：");
	scanf("%s", no);
	printf("输入图书的名称:");
	scanf("%s", name);
	printf("输入插入的位置:");
	scanf("%d", &i);
	printf("你即将向顺序表L中的第%d位插入一项数据，ISBN：%s，名称：%s\n", i, no, name);
	Book e;
	strcpy(e.no, no);
	strcpy(e.name, name);
	InsertList(L, i, e);
}

Status InsertList(SqList *L, int i, ElemType e) {//声明一个结构体e，在L中的第i个位置插入e，i的范围为1 <= i <= L.length+1
	if ((i < 1) || (i > L->length + 1)) { return ERROR; }
	if (L->length == MAXSIZE) { return ERROR; }
	int j = 0;
	for (j = L->length - 1; j >= i - 1; j--)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	++L->length;
	menu(L);
}//插入

//输出顺序表L中的元素
void PrintList(SqList *L)
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		printf("%d.no=%s,name=%s\n",i+1, L->elem[i].no, L->elem[i].name);
	}
	menu(L);
}

int LocateElem(SqList *L) {
	char no[50];
	printf("请输入要查找的ISBN号码：");
	scanf("%s", no);
	for (int i = 0; i < L->length; i++) {
		if (&L->elem[i].no == no) { printf("ISBN为%s的图书在L中位于第%d位", no, i + 1); }
		printf("未找到ISBN为%s的图书", no);
	}
	menu(L);
}

Status DeleteElem(SqList *L) {
	printf("请输入要删除记录的序号：\n");
	int i;
	scanf("%d",&i);
	if ((i < 1) || (i > L->length)) { return ERROR; }
	for (int j = i; j <= L->length - 1; j++) {
		L->elem[j - 1] = L->elem[j];
	}
	--L->length;
	printf("success!\n");
	menu(L);
}

int menu(SqList *L) {
	printf("\n---------------------------------\n");
	printf("输入序号进行选择：\n");
	printf("1.打印顺序表L所有元素\n");
	printf("2.向顺序表L中插入一条记录\n");
	printf("3.输入ISBN对顺序表L现有记录进行查找\n");
	printf("4.删除一条记录\n");
	printf("5.退出\n");
	printf("---------------------------------\n");
	int op = 0;
	scanf("%d", &op);
	switch (op) {
	case 1:PrintList(L);break;
	case 2:CreatElement(L); break;
	case 3:LocateElem(L); break;
	case 4:DeleteElem(L); break;
	default:menu(L); break;
	}
}

void main() {
	SqList L;
	printf("顺序表初始化 ");
	Response(InitList(&L)); //初始化顺序表并返回结果
	menu(&L);
}
