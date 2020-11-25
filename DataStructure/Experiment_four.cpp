/*实验四：栈的操作实验
一、实验目的
  1．能够用高级语言描述栈的存储结构；
  2．能够用高级语言编写栈的基本操作的算法并通过程序测试其正确性；
  3. 能够运用栈的基本操作原理解决更复杂的问题。
二、实验内容
  1．编程实现建立一个数据元素值是一个字符的单链表，并借助栈的入栈、出栈等操作判断此单链表中字符序列是否构成回文的操作。
三、实验要求
  1.建立一个数据元素值为一个字符的带头结点的单链表，并输出单链表中字符序列, 观察输入的内容与输出的内容是否一致。
  2.借助一个栈判断上述已知单链表中字符序列是否为回文，如果是，则输出“此链表中的字符序列构成回文”，否则输出“此链表中的字符序列不构成回文”。
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	char data;
	struct LNode *next;
}LNode, *LinkList;
typedef struct SNode{
	char data;
	struct SNode *next;
}SNode, *LinkStack;
int Link_create(LinkList &L){
	char node;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LinkList r = L,p;
	printf("please input some characters:");
	scanf("%c",&node);
	while(node != '\n'){
		p = (LinkList)malloc(sizeof(LNode));
		if(!p)
			return 0;
		p->data = node;
		p->next = NULL;
		r->next = p;
		r = p;
		scanf("%c",&node);
	}
	return 0;
}
int DisplayList(LinkList L){
	LinkList p = L->next;
	printf("The LinkList Is :");
	while(p){
		printf("%c",p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}
int Push(LinkStack &S, char e){
	LinkStack p = (LinkStack)malloc(sizeof(SNode));
	if(!p)
		return 1;
	p->data = e;
	p->next = S;
	S = p;
	return 0;
}
int Pop(LinkStack &S, char &e){
	if(S == NULL){
		printf("The stack is NULL!\n");
		return 1;
	}
	LinkStack p = S;
	e = p->data;
	S = p->next;
	free(p);
	return 0;
}
int IsHuiWen(LinkList L){
	char e;
	LinkStack S;
	LinkList p = L->next;
	while(p){
		Push(S,p->data);
		p = p->next;
	}
	p = L->next;
	while(p){
		Pop(S,e);
		if(p->data == e)
			p = p->next;
		else
			break;
	}
	if(!p){
		return 1;
	}
	else
		return 0;
}
int main(){
	LinkList L;
	Link_create(L);
	DisplayList(L);
	if(IsHuiWen(L) == 1)
		printf("此链表中的字符序列构成回文\n");
	else
		printf("此链表中的字符序列不构成回文\n");
	return 0;
}
