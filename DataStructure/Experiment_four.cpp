/*ʵ���ģ�ջ�Ĳ���ʵ��
һ��ʵ��Ŀ��
  1���ܹ��ø߼���������ջ�Ĵ洢�ṹ��
  2���ܹ��ø߼����Ա�дջ�Ļ����������㷨��ͨ�������������ȷ�ԣ�
  3. �ܹ�����ջ�Ļ�������ԭ���������ӵ����⡣
����ʵ������
  1�����ʵ�ֽ���һ������Ԫ��ֵ��һ���ַ��ĵ�����������ջ����ջ����ջ�Ȳ����жϴ˵��������ַ������Ƿ񹹳ɻ��ĵĲ�����
����ʵ��Ҫ��
  1.����һ������Ԫ��ֵΪһ���ַ��Ĵ�ͷ���ĵ�������������������ַ�����, �۲����������������������Ƿ�һ�¡�
  2.����һ��ջ�ж�������֪���������ַ������Ƿ�Ϊ���ģ�����ǣ���������������е��ַ����й��ɻ��ġ�������������������е��ַ����в����ɻ��ġ���
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
		printf("�������е��ַ����й��ɻ���\n");
	else
		printf("�������е��ַ����в����ɻ���\n");
	return 0;
}
