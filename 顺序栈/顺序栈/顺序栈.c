#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 100    //顺序栈初始化时分配的存储空间长度

typedef struct {
	int *base;   //栈底指针,栈中元素为字符
	int *top;    //栈顶指针
	int stacksize;   //栈可用的最大容量
}SqStack;       //顺序栈结构

int getRandomNum() {//随机数
	srand((int)time(0));
	int i = rand() % 9999999 + 1000000;
	return i;
}

//初始化顺序栈S
void InitStack(SqStack *S){
	S->base = (char *)malloc(MAXSIZE * sizeof(char));   //为S分配存储空间,也可以使用下面注释掉的语句
	//S.base =new char[MAXSIZE];
	if (!S->base) exit(-1);
	S->top = S->base;        //空栈时，s.top和s.base均指向栈底
	S->stacksize = MAXSIZE;   //初始化栈的最大容量为MAXSIZE
	printf("\n顺序栈初始化成功");
}

//TODO::清空顺序栈 
void ClearStack(SqStack *S){
	if (S->base) {
		S->top = S->base;
	}
	printf("\n顺序栈清空成功");
}

//TODO::入栈操作，向顺序栈S的栈顶处插入新元素e，插入成功，返回true,插入失败，返回false
void Push(SqStack *S) {
	if (S->top - S->base == S->stacksize) { printf("\nPush ERROR"); }
	*S->top++ = getRandomNum();
	printf("\nPush SUCCESS");
}

//TODO::出栈操作，删除顺序栈S的栈顶元素，被删元素用参数e返回，删除成功，函数返回true,删除失败，函数返回false
void Pop(SqStack *S) {
	int e;
	if (S->top - S->base) { printf("\nPop ERROR"); }
	e = *--S->top;
	printf("\ne is %d",e);
	printf("\nPop SUCCESS");
}

//TODO::取顺序栈S的栈顶元素，用参数e返回取得的栈顶元素

//TODO::求顺序栈S的长度

//TODO::输出顺序栈S中的元素（从栈顶到栈顶的顺序输出
void PrintStack(SqStack *S)
{
	int *p;
	for (p = S->base; p < S->top; p++){   //用指针p依次指向栈中的元素，将其输出
		printf("\ne is %d", *p);
	}
}


//TODO::操作菜单



int main()
{
	SqStack S;
	InitStack(&S);
	Push(&S);
	PrintStack(&S);
}
