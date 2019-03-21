#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;       //单链表表结构

int menu(LNode *L) {
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
	case 1:PrintList(L); break;
	case 2:CreatElement(L); break;
	case 3:LocateElem(L); break;
	case 4:DeleteElem(L); break;
	case 5:exit(0);
	default:menu(L); break;
	}
}

void main() {
	LNode L;
	printf("顺序表初始化 ");
}