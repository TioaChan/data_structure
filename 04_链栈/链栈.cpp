// 链栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <time.h>
#include <windows.h>
typedef int ElemType;

typedef struct StackNode {
	ElemType Data;
	struct StackNode *next;
}StackNode,*LinkStack;

int GetRandomNum() {
	srand((unsigned int)time(NULL));//设置当前时间为种子
	return rand() % 100 + 1;
}

void menu(LinkStack& s);

void InitStack(LinkStack &s) {
	s=NULL;
	printf_s("Init Stack success.\n");
}

void StackEmpty(LinkStack& s) {
	if (s == NULL) {
		printf_s("Stack is empty.\n");
	}
	else
	{
		printf_s("Stack is not empty.\n");
	}
	menu(s);
}

void GetTop(LinkStack& s,int& e) {
	if (s == NULL) {
		printf_s("Stack is empty.\n");
	}
	else
	{
		printf_s("the top element is %d\n",s->Data);
	}
	menu(s);
}

void Push(LinkStack &s) {
	int i = 0;
	printf_s("PUSHING..\n");
	while (i <= 5)
	{
		StackNode *temp=new StackNode;
		//LinkStack temp=new LinkStack;
		//LinkStack temp;
		temp->Data=GetRandomNum();
		printf_s("%d\n", temp->Data);
		temp->next=s;
		s=temp;
		i++; 
		Sleep(1000);
	}
	printf_s("DONE!\n");
	menu(s);
}

void Pop(LinkStack &s, int& e) {
	if (s != NULL)
	{
		e=s->Data;
		printf_s("%d\n",e);
		LinkStack p=s;//临时保存栈顶元素的空间，准备释放
		s=s->next;
		delete p;
	}
	else
	{
		printf_s("stack is empty.\n");
	}
	menu(s);
}

void TraverseList(LinkStack& s) {
	if (s != NULL)
	{
		printf_s("%d\n", s->Data);
		TraverseList(s->next);
	}
	else
	{
		printf_s("stack is empty.\n");
		menu(s);
	}
}

void menu(LinkStack& s) {
	int i = 0, e = 0;
	printf("---------------------------------\n");
	printf("输入序号进行选择：\n1.判空\n2.入栈\n3.出栈\n4.取栈顶元素\n5.递归遍历\n10.退出\n");
	printf("---------------------------------\n");
	int op = 0;
	printf("请输入序号：");
	scanf_s("%d", &op);
	switch (op) {
	case 1:StackEmpty(s);
		break;
	case 3:Pop(s, e);
		break;
	case 2:Push(s);
		break;
	case 4:GetTop(s, e);
		break;
	case 5:TraverseList(s);break;
	case 10:exit(0);
	default:menu(s); break;
	}
}

int main()
{
	LinkStack s;
	InitStack(s);
	menu(s);
	return 0;
}
