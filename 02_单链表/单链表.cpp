#include <iostream>
#include <time.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data; //数据域
	struct LNode* next; //指针域
}LNode;

typedef LNode* LinkList;  //linklist为指向结构体LNode的指针类型

int GetRandomNum() {
	srand((unsigned int)time(NULL));//设置当前时间为种子
	return rand() % 100 + 1;
}

void InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	printf_s("单链表初始化成功\n");
}
void InsertData_Head(LinkList& L) {//头插
	for (int i = 0; i < 5; ++i) {
		LNode* s;
		s = new LNode;//生成一个新节点*temp
		s->data = GetRandomNum() + i;
		s->next = L->next;//将新节点的指针域指向L
		L->next = s;
	}
}
void InsertData_Rear(LinkList& L) {//尾插
	LinkList rear = L; //声明一个尾指针，并将尾指针指向头节点L
	for (int i = 0; i < 5; ++i) {
		LNode* s;
		s = new LNode;//生成一个新节点*temp
		s->data = GetRandomNum() + i;
		s->next = NULL;//新节点的指针域置空
		rear->next = s;//将新节点*temp插入尾节点*rear之后
		rear = s;//将*rear指向新的尾节点*s
	}
}
void PrintList(LinkList& L) {
	int i = 1;
	LinkList p = L->next;
	while (p)
	{
		printf_s("No.%d is %d \n", i, p->data);
		p = p->next;
		i++;
	}
	printf_s("表中共有%d个元素\n\n", i - 1);
}
int GetElem(LinkList& L, int i, ElemType& e) {
	LinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i) {
		printf_s("GetElem Failed\n");
		return 0;
	}
	e = p->data;
	printf_s("GetElem Success,the No.%d elem is ", i);
}

void SearchElem(LinkList L, ElemType& e, int& i) {
	LinkList p = L->next;
	i = 1;
	while (p && p->data != e) {
		p = p->next;
		i++;
	}
	if (p) {
		printf_s("SearchElem success,the elem %d is No.", e);
	}
	else
	{
		printf_s("SearchElem Failed！\n\n");
	}
}
void InsertElem(LinkList L, int i, ElemType& e) {
	LinkList p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) {
		printf("Insert Failed!\n");
	}
	else
	{
		LNode* s = new LNode;
		s->data = e;
		s->next = p->next;
		p->next = s;
		printf("Insert Success!\n");
	}
}
void DeleteElem(LinkList L, int i, ElemType& e) {
	LinkList p = L;
	int j = 0;
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) {
		printf("Delete Failed!\n");
	}
	else
	{
		LinkList q = p->next;
		p->next = q->next;
		e = q->data;
		delete q;
	}
}

void menu(LinkList& L) {
	int i = 0, Data = 0;
	printf("---------------------------------\n");
	printf("输入序号进行选择：\n");
	printf("1.打印\n");
	printf("2.取值\n");
	printf("3.插入\n");
	printf("4.查找\n");
	printf("5.删除\n");
	printf("6.退出\n");
	printf("---------------------------------\n");
	int op = 0;
	printf("请输入序号：");
	scanf_s("%d", &op);
	switch (op) {
	case 1:printf_s("打印操作：单链表内的数据如下：\n");
		PrintList(L); menu(L);
		break;
	case 2:
		printf_s("取值操作：请输入序号进行取值：\n");
		scanf_s("%d", &i);
		GetElem(L, i, Data);
		printf_s("%d\n", Data); menu(L);
		break;
	case 3:
		printf_s("插入操作：请输入要插入的位置：\n");
		scanf_s("%d", &i);
		printf_s("插入操作：请输入要插入的元素：\n");
		scanf_s("%d", &Data);
		InsertElem(L, i, Data);
		PrintList(L); menu(L);
		break;
	case 4:
		printf_s("查找操作：请输入元素进行查找：\n");
		scanf_s("%d", &Data);
		SearchElem(L, Data, i);
		printf_s("%d\n", i); menu(L);
		break;
	case 5:
		printf_s("删除操作：请输入要删除元素的位置：\n");
		scanf_s("%d", &i);
		DeleteElem(L, i, Data);
		printf_s("删除的元素是%d\n", Data); menu(L);
		break;
	case 6:exit(0);
	default:menu(L); break;
	}
}

int main()
{
	LNode* L;
	int i = 0, Data = 0;
	InitList(L);
	printf("---------------------------------\n");
	printf("输入序号选择插入必要数据的方法：\n");
	printf("1.前插法\n");
	printf("2.后插法\n");
	printf("---------------------------------\n");
	int op = 0;
	printf("请输入序号：");
	scanf_s("%d", &op);
	switch (op) {
	case 1:InsertData_Head(L);	break;
	case 2:InsertData_Rear(L);	break;
	default:InsertData_Head(L); break;
	}
	menu(L);
	return 0;
}
