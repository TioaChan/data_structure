#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define MAXSIZE 200  //图书表可能达到的最大长度
typedef int Status;


//顺序表的顺序存储结构
typedef struct { //图书信息定义
	char no[3];
	char name[5];
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
Status InsertList(SqList *L, int i, ElemType e) {//声明一个结构体e，在L中的第i个位置插入e，i的范围为1 <= i <= L.length+1
	if ((i < 1) || (i > L->length + 1)) { return ERROR; }
	if (L->length == MAXSIZE) { return ERROR; }
	int j;
	for (j = L->length - 1; j >= i - 1; j--)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	++L->length;
	return OK;
}

void main() {
	SqList L;
	printf("顺序表初始化结果：");
	Response(InitList(&L)); //初始化顺序表并返回结果
	int i;
	char no[3];
	char name[5];
	printf("输入图书的ISBN号：");
	scanf("%s", no);
	printf("输入图书的名称:");
	scanf("%s", name);
	printf("输入插入的位置:");
	scanf("%d", &i);
	//CreatElement(&L, no, name);   //向L中填充数据
	printf("你即将向顺序表L中的第%d位插入一项数据，ISBN：%c 名称：%c", i, no, name);
	Book e;
	strcpy(e.no, no);
	strcpy(e.name, name);
	printf("顺序表插入结果：");
	Response(InsertList(&L, i, e));
}
