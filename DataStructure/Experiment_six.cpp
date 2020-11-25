/*ʵ���� ѭ�����е��ۺ�Ӧ��ʵ�� 
һ��ʵ��Ŀ�� 
  �ܹ���ѭ������������ģ���������ѭ������������ԭ���������⡣ 
����ʵ������ 
  ��д����ģ���������ѭ���������Ĺ���ԭ�� 
����ʵ��Ҫ�� 
  1. ��ѭ��˳����л��������������ݣ����Ӽ��̡������������ַ���Ȼ������� �ַ��洢��ѭ�������У�ֱ������س��������Ϊֹ�� 
  2. ��ȡ����ѭ��˳������е����ݲ������ֱ������Ϊ��Ϊֹ�� 
  3. ���á�����һ���洢��Ԫ���ķ������ֶ��е��������п�����
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 10
typedef char QElemType;
typedef int Status;
typedef struct {       
 QElemType *base;
 int front;
 int rear;
}SqQueue; 
//��������
Status InitQueue(SqQueue &Q){
 Q.base = (QElemType *) malloc (MAXQSIZE * sizeof(QElemType));
 if(!Q.base)
 return 0;
 Q.front = Q.rear = 0;
 return 1;
}
//��Ӳ���
Status Push(SqQueue &Q, QElemType e){
 if(Q.front == (Q.rear + 1) % MAXQSIZE){
 printf("The Queue is OVERFLOW!\n");
 return 0;
 }
 Q.base[Q.rear] = e;
 Q.rear = (Q.rear + 1) % MAXQSIZE;
 return 1;
}
//���Ӳ���
Status Pop(SqQueue &Q, QElemType &e){
 if(Q.front == Q.rear){
 //printf("The Queue is NULL!\n");
 return 0;
 }
 e = Q.base[Q.front];
 Q.front = (Q.front + 1) % MAXQSIZE;
 return 1;
} 
int main(){
 int count = 0;
 QElemType e;
 SqQueue Q;
 InitQueue(Q);
 e = getchar();
 while(e != '\n'){
 if(count == 9){
 printf("ѭ����������!\n");
 break;
 }
 Push(Q, e);
 count++;
 e = getchar();
 }
 while(Pop(Q, e)){
 putchar(e);
 }
 return 0;
} 

 
