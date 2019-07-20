
#include <iostream>
#include <time.h>
#include<windows.h>
typedef int Elemtype;
#define MAXSIZE 100
typedef struct {
	Elemtype data[MAXSIZE];
	int front;
	int rear;
}SqNode;

int GetRandomNum() {
	srand((unsigned int)time(NULL));//设置当前时间为种子
	return rand() % 999 + 100;
}
void menu(SqNode& q);

void InitQueue(SqNode &q) {
	q.front = q.rear = 0;
	if (!q.data) {
		printf_s("Init SqNode Failed,Try again...\n");
		InitQueue(q);
	}
	else
	{
		printf_s("Init SqNode Success.\n");
	}
}


void DestroyQueue(SqNode& q) {
	printf_s("TODO\n");
	menu(q);
}   //销毁队列

void ClearQueue(SqNode& q) {
	printf_s("TODO\n");
	menu(q);
}       //清空队列

void QueueEmpty(SqNode& q) {
	if (q.front == q.rear) {
		printf_s("queue is empty\n");
	}
	else {
		printf_s("queue is not empty\n");
	}
	menu(q);
}          //判空. 空--TRUE

void QueueLength(SqNode& q) {
	printf_s("目前队列的长度为：%d\n",((q.rear-q.front+MAXSIZE)%MAXSIZE));
	menu(q);
}         //取队列长度

void GetHead(SqNode& q, Elemtype& data) {
	if (q.rear != q.front) {
		data=q.data[q.front];
	}
	else
	{
		data = -1;
		printf_s("queue is empty\n");
		menu(q);
	}
}         //取队头元素,

void EnQueue(SqNode& q) {
	if ((q.rear + 1) % MAXSIZE == q.front) {
		printf_s("queue is full\n");
	}
	else
	{
		int i = 0;
		while (i < 5)
		{
		q.data[q.rear]=GetRandomNum();
		printf_s("%d\n",q.data[q.rear]);
		q.rear=(q.rear+1)%MAXSIZE;
		i++;
		Sleep(1000);
		}
	}
	menu(q);
}        //入队列

void DeQueue(SqNode& q,Elemtype &data) {
	if (q.front == q.rear) {
		data=-1;
		printf_s("queue is empty\n");
		menu(q);
	}
	else {
		data=q.data[q.front];
		q.front=(q.front+1)%MAXSIZE;
	}
}     //出队列

void QueueTraverse(SqNode& q){
	printf_s("TODO\n");
	menu(q);
}       //遍历


void menu(SqNode& q) {
	printf("\n---------------------------------\n");
	printf("输入序号进行选择：\n");
	printf("1.销毁\n2.清空\n3.判空\n4.求长\n5.取对头元素\n6.入队\n7.出队\n8.遍历\n10.退出\n");
	printf("---------------------------------\n");
	int op = 0,data;
	printf("输入序号：");
	scanf_s("%d", &op);
	switch (op) {
	case 1: DestroyQueue(q);break;
	case 2: ClearQueue(q);break;
	case 3: QueueEmpty(q);break;
	case 4: QueueLength(q);break;
	case 5: GetHead(q,data); printf("队头元素是：%d\n", data); menu(q); break;
	case 6: EnQueue(q);break;
	case 7: DeQueue(q,data);printf("%d\n",data); menu(q); break;
	case 8: QueueTraverse(q);break;
	case 10:exit(0);
	default:menu(q); break;
	}
}

int main(){
	SqNode q;
	InitQueue(q);
	printf("正在初始化数据...\n");
	EnQueue(q);
	menu(q);
	return 0;
}