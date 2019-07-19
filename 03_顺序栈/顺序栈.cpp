#include <iostream>
#include <time.h>
#include <windows.h>


#define MAXSIZE 100
typedef int Elemtype;

typedef struct {
	Elemtype data[MAXSIZE];
	int top;
}SqStack;

int GetRandomNum() {
	srand((unsigned int)time(NULL));//设置当前时间为种子
	return rand() % 100 + 1;
}

void menu(SqStack& sl);

void Push(SqStack& sl) {
	printf("\n---------------------------------\n");
	int i=0;
	while (i <= 5) {
		if (sl.top == MAXSIZE - 1) {
			printf_s("sl is full\n");
			break;
		}
		else
		{
			sl.top++;
			sl.data[sl.top] = GetRandomNum();
			printf_s("%d\n", sl.data[sl.top]);
			i++;
			Sleep(1000);
		}
	}
	menu(sl);
}

void Pop(SqStack& sl) {
	if (sl.top == -1) {
		printf_s("sl is empty\n");
	}
	else
	{
		printf_s("%d\n", sl.data[sl.top]);
		--sl.top;
	}
	menu(sl);
}

void menu(SqStack& sl) {
	printf("\n---------------------------------\n");
	printf("输入序号进行选择：\n");
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.退出\n");
	printf("---------------------------------\n");
	int op = 0;
	scanf_s("%d", &op);
	switch (op) {
	case 1:Push(sl); break;
	case 2:Pop(sl); break;
	case 3:exit(0);
	default:menu(sl); break;
	}
}

int main() {
	SqStack sl;
	sl.top = -1;
	menu(sl);
}