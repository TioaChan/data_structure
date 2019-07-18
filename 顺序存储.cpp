#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAXSIZE 1000
#define OVERFLOW -1
#define OK 1


typedef struct {
	int *elem;
	int length;
}SqList;

int GetRandomNum() {
	srand((unsigned int)time(NULL));//设置当前时间为种子
	return rand() % 100 + 1;
}

int InitList_Sq_Reference(SqList &L) {//参数用引用
	L.elem=new int[MAXSIZE];
	if (!L.elem) {
		printf("Init List By Reference OVERFLOW!\n");
		exit(OVERFLOW);
	}
	else
	{
		L.length = 0;
		printf("Init List By Reference Completed!\n");
		return OK;
	}
}
int InitList_Sq_Address(SqList *L) {//参数用指针
	L->elem = new int[MAXSIZE];
	if (!L->elem) {
		printf("Init List By Address OVERFLOW!\n");
		exit(OVERFLOW);
	}
	else {
		L->length = 0;
		printf("Init List By Address Init Completed!\n");
		return OK;
	}
}

int PullData_Reference(SqList &L) {//参数用引用
	for (int i = 0; i < 5; i++) {
		L.elem[i]= GetRandomNum()+i;
		L.length++;
	}
	printf("Pull Data by Reference Completed!Now the L List has %d Data.\n", L.length);
	Sleep(1000);
	return OK;
}
int PullData_Address(SqList *L) {//参数用指针
	for (int i = 0; i < 5; i++) {
		L->elem[i] = GetRandomNum()+i;
		L->length++;
	}
	printf("Pull Data by Address Completedn!Now the LL List has %d Data.\n",L->length);
	Sleep(1000);
	return OK;
}

void PrintList_Reference(SqList &L)
{
	printf("\nL:");
	for (int i = 0; i < L.length; i++)
	{
		printf("No.%d  data is %d\n", i + 1, L.elem[i]);
	}
}
void PrintList_Address(SqList *L)
{
	printf("\nLL:");
	for (int i = 0; i < L->length; i++)
	{
		printf("No.%d  data is %d\n", i + 1, L->elem[i]);
	}
}

int GetElem_Address(SqList* L, int i, int& Data) {
	if (i<1 || i>L->length) {
		return ERROR;
	}
	Data=L->elem[i-1];
	return OK;
}
int GetElem_Refences(SqList &L, int i, int& Data) {
	if (i<1 || i>L.length) {
		return ERROR;
	}
	Data=L.elem[i-1];
	return OK;
}

void LocateELem_Address(SqList* L,int &i, int Data) {
	for (int j = 0; j < L->length; j++) {
		if (L->elem[j] == Data) {
			i=j+1;
		}
	}
}
void LocateELem_Refences(SqList &L, int& i, int Data) {
	for (int j = 0; j < L.length; j++) {
		if (L.elem[j] == Data) {
			i = j + 1;
		}
	}
}

void InsertElem_Address(SqList *L,int i,int Data) { //引用 传进来是个地址
	if (i < 1 || i > L->length + 1) {
		printf("i vlaue went wrong\n");
	}
	else if(L->length==MAXSIZE)
	{
		printf("list L was already full\n");
	}
	else
	{
		for (int j = L->length - 1; j >= i - 1; j--) {
			L->elem[j+1]=L->elem[j];
		}
		L->elem[i-1]=Data;
		L->length++;
		printf("insert into list L successfully\n");
	}
}
void InsertElem_Refences(SqList &LL,int i,int Data) { //地址 传进来是个sqllist 取其地址
	if (i < 1 || i > LL.length + 1) {
		printf("i vlaue went wrong\n");
	}
	else if (LL.length == MAXSIZE)
	{
		printf("list LL was already full\n");
	}
	else
	{
		for (int j = LL.length - 1; j >= i - 1; j--) {
			LL.elem[j + 1] = LL.elem[j];
		}
		LL.elem[i - 1] = Data;
		LL.length++;
		printf("insert into list LL successfully\n");
	}
}

void DeleteElem_Address(SqList *LL,int &Data,int i) {
	if (i < 1 || i > LL->length + 1) {
		printf("i vlaue went wrong\n");
	}
	else
	{
		Data=LL->elem[i-1];
		for (int j = i - 1; j < LL->length; j++) {
			LL->elem[j]=LL->elem[j+1];
		}
		LL->length--;
		printf("delete elem from list LL was successfully\n");
	}
}
void DeleteELem_Refences(SqList& L,int &Data,int i) {
	if (i < 1 || i > L.length + 1) {
		printf("i vlaue went wrong\n");
	}
	else
	{
		Data = L.elem[i - 1];
		for (int j = i - 1; j < L.length; j++) {
			L.elem[j] = L.elem[j + 1];
		}
		L.length--;
		printf("delete elem from list LL was successfully\n");
	}
}

void menu(SqList L, SqList LL);

void PrintList(SqList L, SqList LL) {
	PrintList_Reference(L);
	PrintList_Address(&LL);
	menu(L,LL);
}
void InsertList(SqList L, SqList LL) {
	int Data, i;
	printf("请输入要插入的元素：\n");
	scanf_s("%d", &Data);
	printf("请输入要插入的位置：\n");
	scanf_s("%d", &i);
	InsertElem_Address(&L,i,Data);
	InsertElem_Refences(LL,i,Data);
	printf("新的线性表如下：\n");
	PrintList(L,LL);
}
void GetList(SqList L, SqList LL) {
	int Data, i;
	printf("请输入待取值的序号：");
	scanf_s("%d",&i);
	GetElem_Refences(L, i, Data);
	printf("THE No.%d in L is %d\n",i, Data);
	GetElem_Address(&LL,i,Data);
	printf("THE No.%d in LL is %d\n",i,Data);
	menu(L, LL);
}
void LocateList(SqList L, SqList LL) {
	int Data, i;
	printf("请输入要查找的元素：\n");
	scanf_s("%d",&Data);
	LocateELem_Address(&L,i,Data);
	printf("元素位于L第%d号位置\n", i);
	LocateELem_Refences(LL, i, Data);
	printf("元素位于LL第%d号位置\n", i);
	menu(L,LL);
}
void DeleteElem(SqList L, SqList LL) {
	int Data, i;
	printf("请输入要删除的元素的位置：\n");
	scanf_s("%d", &i);
	DeleteElem_Address(&L,Data,i);
	printf("L中删除的元素为%d\n", Data);
	DeleteELem_Refences(LL,Data,i);
	printf("LL中删除的元素为%d\n", Data);
	printf("新的线性表如下：\n");
	PrintList(L, LL);
}

void menu(SqList L,SqList LL) {
	printf("\n---------------------------------\n");
	printf("输入序号进行选择：\n");
	printf("1.打印\n");
	printf("2.取值\n");
	printf("3.插入\n");
	printf("4.查找\n");
	printf("5.删除\n");
	printf("6.退出\n");
	printf("---------------------------------\n");
	int op = 0;
	scanf_s("%d", &op);
	switch (op) {
		case 1:PrintList(L,LL); break;
		case 2:GetList(L, LL); break;
		case 3:InsertList(L, LL); break;
		case 4:LocateList(L, LL); break;
		case 5:DeleteElem(L, LL); break;
		case 6:exit(0);
		default:menu(L, LL); break;
	}
}

void main() {
	SqList L,LL;
	printf("L will be inited by Reference,LL will be inited by Address\n");
	InitList_Sq_Reference(L);
	InitList_Sq_Address(&LL);
	PullData_Reference(L);
	PullData_Address(&LL);
	menu(L,LL);
}
