/*ʵ���� ���еĲ���ʵ��
һ��ʵ��Ŀ��
  1���ܹ��ø߼������������еĴ洢�ṹ��
  2���ܹ��ø߼����Ա�д���еĻ����������㷨��ͨ�������������ȷ�ԡ�
����ʵ������
  �����ɽ���һ������βָ���ʶ��ѭ�������У����ڴ�ѭ����������ʵ����ӡ����Ӳ�����
����ʵ��Ҫ��
  1. ��������Ķ��г���n�͸�Ԫ��ֵ����һ����ͷ����ѭ�������ʾ�Ķ��У�ѭ�������У�������ֻ��һ��βָ����ָ��β��㣬Ȼ����������и�Ԫ��ֵ��
  2. ������Ԫ��e��ӣ��������Ӻ�Ķ����и�Ԫ��ֵ��
  3. ��ѭ�������еĶ���Ԫ�س��ӣ����������Ԫ�ص�ֵ�ͳ��Ӻ�����и�Ԫ��ֵ��
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
	printf("��ǰ��������:");
	for(;p->next != rear->next->next; p = p->next){
		printf("%d  ",p->data);
	}
	putchar('\n');
	return 0;
}
Status CQLink_Create(CQLink &rear, int n){
	int e;
	CQLink_InitQueue(rear);
	printf("�������������:");
	for(int i = 1; i <= n; i++){
		scanf("%d",&e);
		CQLink_EnQueue(rear, e);
	}
}
int main(){
	int n, e;
	CQLink rear;
	printf("��������г���:");
	scanf("%d",&n);
	CQLink_Create(rear, n);
	CQLink_Display(rear);
	printf("������һ����ֵ e :");
	scanf("%d", &e);
	CQLink_EnQueue(rear, e);
	printf("�� e ��Ӻ���е�����:");
	CQLink_Display(rear);
	printf("�ٰ�һ�Σ�Enter����������Ӳ���������");
	getchar();
	getchar();
	CQLink_DeQueue(rear, e);
	printf("������� �� ");
	CQLink_Display(rear);
	printf("���ӵ�ֵΪ %d\n", e); 
	return 0; 
} 
