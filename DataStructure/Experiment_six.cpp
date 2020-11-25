/*实验六 循环队列的综合应用实验 
一、实验目的 
  能够将循环队列运用于模拟键盘输入循环缓冲区工作原理问题的求解。 
二、实验内容 
  编写程序模拟键盘输入循环缓冲区的工作原理。 
三．实验要求 
  1. 用循环顺序队列缓存键盘输入的内容，即从键盘“按键”输入字符，然后将输入的 字符存储到循环队列中，直到输入回车或队列满为止。 
  2. 读取键盘循环顺序队列中的内容并输出，直到队列为空为止。 
  3. 采用“少用一个存储单元”的方法区分队列的判满的判空条件
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
//创建队列
Status InitQueue(SqQueue &Q){
 Q.base = (QElemType *) malloc (MAXQSIZE * sizeof(QElemType));
 if(!Q.base)
 return 0;
 Q.front = Q.rear = 0;
 return 1;
}
//入队操作
Status Push(SqQueue &Q, QElemType e){
 if(Q.front == (Q.rear + 1) % MAXQSIZE){
 printf("The Queue is OVERFLOW!\n");
 return 0;
 }
 Q.base[Q.rear] = e;
 Q.rear = (Q.rear + 1) % MAXQSIZE;
 return 1;
}
//出队操作
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
 printf("循环队列已满!\n");
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

 
