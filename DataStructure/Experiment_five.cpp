/*实验五 队列的操作实验
一、实验目的
  1．能够用高级语言描述队列的存储结构；
  2．能够用高级语言编写队列的基本操作的算法并通过程序测试其正确性。
二、实验内容
  编程完成建立一个仅用尾指针标识的循环链队列，并在此循环链队列上实现入队、出队操作。
三、实验要求
  1. 根据输入的队列长度n和各元素值建立一个带头结点的循环链表表示的队列（循环链队列），并且只设一个尾指针来指向尾结点，然后输出队列中各元素值。
  2. 将数据元素e入队，并输出入队后的队列中各元素值。
  3. 将循环链队列的队首元素出队，并输出出队元素的值和出队后队列中各元素值。
*/

#include<stdio.h>
#include<stdlib.h>
typedef int Status;
typedef struct CQNode{
	int data;
	struct CQNode *next;
}CQNode, *CQLink;
Status CQLink_InitQueue( CQLink &rear){
	rear = (CQLink)malloc(sizeof(CQNode));
	if(!rear)
		return 0;
	rear->next = rear;
	return 0;
}
Status CQLink_EnQueue(CQLink &rear, int e){
	CQLink p = (CQLink) malloc (sizeof(CQNode));
	if(!p)
		return 0;
	p->data = e;
	p->next = rear->next;
	rear->next = p;
	rear = p;
	return 0;
}
Status CQLink_DeQueue(CQLink &rear, int &e){
	if(rear->next == rear){
		printf("The Queue is NULL!\n");
		return 0;
	}
	CQLink p = rear->next->next;
	e = p->data;
	rear->next->next = p->next;
	if(p == rear)
		rear = rear->next;
	free(p);
	return 0;
}
Status CQLink_Display(CQLink rear){
	CQLink p = rear->next->next;
	printf("当前队列数据:");
	for(;p->next != rear->next->next; p = p->next){
		printf("%d  ",p->data);
	}
	putchar('\n');
	return 0;
}
Status CQLink_Create(CQLink &rear, int n){
	int e;
	CQLink_InitQueue(rear);
	printf("请输入队列数据:");
	for(int i = 1; i <= n; i++){
		scanf("%d",&e);
		CQLink_EnQueue(rear, e);
	}
}
int main(){
	int n, e;
	CQLink rear;
	printf("请输入队列长度:");
	scanf("%d",&n);
	CQLink_Create(rear, n);
	CQLink_Display(rear);
	printf("请输入一个数值 e :");
	scanf("%d", &e);
	CQLink_EnQueue(rear, e);
	printf("将 e 入队后队列的数据:");
	CQLink_Display(rear);
	printf("再按一次（Enter）键输出出队操作后结果！");
	getchar();
	getchar();
	CQLink_DeQueue(rear, e);
	printf("【结果】 ： ");
	CQLink_Display(rear);
	printf("出队的值为 %d\n", e); 
	return 0; 
} 
