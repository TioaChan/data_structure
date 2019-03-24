#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 100
#define OK 1
#define ERROR -1
#define OVERFLOW -2


//TODO::单链表表结构
typedef struct LNode {
	int data; //数据域
	struct LNode *next;  //指针域
}LNode,*LinkList; //*LinkList为LNode类型的指针

int getRandomNum() {//随机数
	srand((int)time(0));
	int i = rand() % 9999999 + 1000000;
	return i;
}

//TODO::初始化单链表L
int InitList(LinkList *L) {//定义一个头指针
	(*L) = (LNode*)malloc(sizeof(LNode));
	(*L)->next = NULL;
	return OK;
}

//TODO::前插法建表
void CreateList_H(LinkList L) { //头插法插入5条数据
	for (int i = 0; i < 8; ++i) {
		LNode *p;
		p = (LNode*)malloc(sizeof(LNode));
		p->data = getRandomNum()+i;
		p->next = L->next;
		L->next = p;
	}
}

//TODO::选做:后插法建表
void CreateList_R(LinkList L) {
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
}
//TODO::选做:创建一个值递增有序的单链表

//TODO::输出单链表L 中各结点的值
void PrintList(LinkList L) {
	LNode *p=L->next;
	for (int i = 1; p; i++)
	{
		printf("No.%d:%d\n", i,p->data);
		p = p->next;
	}
}
//TODO::在单链表L 中查找元素e的位置，查找成功，返回指向e的指针
int getElem(LinkList L) {
	printf("查找哪一项的数据？\n");
	int i;
	scanf("%d", &i);
	LNode *p = L->next;
	int j = 1;
	while (p&&j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;
	printf("No.%d is %d\n", i, p->data);
}
//TODO::在单链表L的第i个结点前插入一个新元素e，插入成功，返回true,插入失败，返回false
void ListInsert(LinkList L) {
	printf("TODO\n");
	LNode *p = L;
	printf("在哪一项插入数据？\n");
	int i = 0, j = 0;
	scanf("%d", &i);
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1)) {
		return ERROR;
	}
	LNode *s;
	s = (LNode*)malloc(sizeof(LNode));
	s->data = getRandomNum();
	s->next = p->next;
	p->next = s;
	printf("插入成功\n");
	return OK;
}

void getNobyData(LinkList L) {
	printf("TODO\n");
}
//TODO::删除单链表L中第i 个结点，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
int DeleteElem(LinkList L) {
	printf("删除哪一项的数据？\n");
	int i = 0, j = 0;
	scanf("%d", &i);
	LNode *p = L;
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1)) {
		return ERROR;
	}
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	printf("删除成功\n");
	return OK;
}

void main(){
	LNode *L;
	InitList(&L);//初始化：定义一个头指针 L->next=NULL;
	CreateList_H(L);
	PrintList(L);
	getElem(L);
	DeleteElem(L);
	PrintList(L);
	ListInsert(L);
	PrintList(L);
}
