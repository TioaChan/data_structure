#include <iostream>
#include <time.h>
#include<Windows.h>;

typedef int ElemType;
typedef struct Qnode {
	ElemType data;
	struct Qnode *next;
}Qnode,*QueuePtr;
typedef struct LinkQueue {//front做删除操作 //rear做插入操作
	QueuePtr front;
	QueuePtr rear;
}lq;

int GetRandomNum() {
	srand((unsigned int)time(NULL));//设置当前时间为种子
	return rand() % 999 + 100;
}

void menu(LinkQueue& q);

void InitQueue(LinkQueue& q){
	q.front=q.rear=new Qnode;
	if (!q.front) {
		printf_s("Init qNode Failed,Try again...\n");
		InitQueue(q);
	}
	else
	{
		printf_s("Init qNode Success.\n");
	}
}

//void DestroyQueue(LinkQueue& q) {}
//
//void ClearQueue(LinkQueue& q) {}
//
//bool QueueEmpty(LinkQueue q) {}
//
void QueueLength(LinkQueue &q) {
	int i=0;
	Qnode* p = new Qnode;
	p->next=q.front->next;
	if (q.front != q.rear) {
		while (p->next != q.rear)
		{
			p->next = p->next->next;
			i++;
		}
		printf("qnode length is %d", i + 1);
	}
	else
	{
		printf_s("qnode is empty.\n");
	}
	menu(q);
}

void GetHead(LinkQueue &q, ElemType& e) {
	if (q.front != q.rear) {
		e=q.front->next->data;
	}
	else
	{
		printf_s("qnode is empty.\n");
	}
}

void EnQueue(LinkQueue& q) {
	int i=0;
	while(i<5){
	Qnode* p = new Qnode;//为入队元素分配节点空间，用指针p指向
	if (!p) {
		EnQueue(q);
	}
	p->data=GetRandomNum();
	p->next=NULL;
	printf_s("%d\n",p->data);
	q.rear->next=p;//将新节点插入到队尾
	q.rear=p;//修改队尾指针为p
	i++;
	Sleep(1000);
	}
	menu(q);
}

void DeQueue(LinkQueue& q, ElemType& e) {//出队
	if (q.front == q.rear) {//判空
		printf_s("qnode is empty.\n");
	}
	else
	{
		Qnode *p=new Qnode;//声明新节点p
		p=q.front->next;//队列的头节点地址赋给p（q只包含两个指针，一个指向队列头节点，一个指向队列尾节点）
		e=p->data;
		q.front->next=p->next;//修改头指针
		if (q.rear == p) {//如果删的是尾节点
			q.front=q.rear;//队尾指针指向头节点
		}
		delete(p);//删除p
	}
}
//
void QueueTraverse(LinkQueue &q) {
	//int i = 0;
	Qnode* p = new Qnode;
	p->next = q.front->next;
	if (q.front != q.rear) {
		while (p->next != q.rear)
		{
			printf_s("%d\n",p->next->data);
			p->next = p->next->next;
			//i++;
		}
		printf_s("%d\n", p->next->data);
		//printf("qnode length is %d", i + 1);
	}
	else
	{
		printf_s("qnode is empty.\n");
	}
	menu(q);
}


void menu(LinkQueue& q) {
	printf("\n---------------------------------\n");
	printf("输入序号进行选择：\n");
	printf("1.销毁\n2.清空\n3.判空\n4.求长\n5.取对头元素\n6.入队\n7.出队\n8.遍历\n10.退出\n");
	printf("---------------------------------\n");
	int op = 0, data;
	printf("输入序号：");
	scanf_s("%d", &op);
	switch (op) {
	//case 1: DestroyQueue(q); break;
	//case 2: ClearQueue(q); break;
	//case 3: QueueEmpty(q); break;
	case 4: QueueLength(q); break;
	case 5: GetHead(q, data); printf("队头元素是：%d\n", data); menu(q); break;
	case 6: EnQueue(q); break;
	case 7: DeQueue(q, data); printf("%d\n", data); menu(q); break;
	case 8: QueueTraverse(q); break;
	case 10:exit(0);
	default:menu(q); break;
	}
}

int main()
{
	lq q;
	InitQueue(q);
	printf("正在初始化数据...\n");
	EnQueue(q);
	menu(q);
	return 0;
}

