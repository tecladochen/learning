/*实验一 顺序表的基本操作 
一 实验目的
1．能够用高级语言描述线性表的顺序存储结构。
2．能够用高级语言编写程序实现顺序表的基本操作。
3．能够运用顺序表的基本操作原理实现有序顺序表的指定操作。
二 实验内容
1．建立顺序表。
2．在顺序表上实现插入、删除和查找操作。
3．删除有序顺序表中的重复元素。
三 实验要求
（1）根据输入顺序表的长度n和n个无序整数值建立一个顺序表；
（2）在顺序表的第i个元素之前插入一个值为x的元素，并输出插入后的顺序表中各元素值；
（3）删除顺序表中第i个元素，并输出删除后的顺序表中各元素值；
（4）在顺序表中查找值为e的数据元素，如果查找成功，则输出“查找成功！”和该元素在顺序表中的位置，否则输出“查找失败！”；
（5）根据输入顺序表的长度m和m个非递减的有序整数建立一个有序顺序表，然后删除其中所有的重复元素（即相同的整数只保留一个） ，最后输出删除后的有序顺序表中各元素值。
*/ 
#include <stdio.h>
#define  MAXLEN  30  /*线性表的最大长度*/
#define  ERROR   0
#define  OVERFLOW    -2
#define OK   1
typedef  int  ElemType;
typedef  int  Status;

typedef struct
{   ElemType  elem[MAXLEN]; /*顺序表中存放元素的数组，其中ElemType为抽象数据类型，在程序具体实现时可以用任意类型代替*/
    int length;   /*顺序表的长度，即元素个数*/
}SqList;     /*顺序表的类型*/

Status SqList_Insert(SqList &L,int i,ElemType x)
 /*在顺序表L中第i个元素前插入新元素x*/
{ if (i<1||i>L.length+1) return ERROR; /*插入位置不正确则出错*/
  if (L.length>=MAXLEN)  return OVERFLOW;  /*顺序表L中已放满元素，再做插入操作则溢出*/
  for(int j=L.length-1;j>=i-1;j--)
     L.elem[j+1]=L.elem[j];/*将第i个元素及后续元素位置向后移一位*/
  L.elem[i-1]=x;   /*在第i个元素位置处插入新元素x*/
  L.length++;    /*顺序表L的长度加1*/
  return OK;
}

Status SqList_Delete(SqList &L,int i,ElemType &e)
 /*在顺序表L中删除第i个元素*/
{  if (i<1||i>L.length)  return ERROR; /*删除位置不正确则出错*/
   e=L.elem[i-1];
   for(int j=i;j<=L.length-1;j++)
      L.elem[j-1]=L.elem[j]; /*将第i+1个元素及后继元素位置向前移一位*/
   
   L.length--;   /*顺序表L的长度减1*/
   return OK;
}

int SqList_Search(SqList L,ElemType e)
/* 在顺序表中查找值为e的元素，如果找到，则函数返回该元素在顺序表中的位置，否则返回0*/
{  int i;
   for ( i=1;i<=L.length&&L.elem[i-1]!=e;i++);  /*从第一个元素开始依次将每个元素值与给定值x比较*/
   if (i<=L.length)
       return  i;
   else
       return  0;
}

Status SqList_Create(SqList  &L)    //建立一个顺序表L
{  printf("Please input the length:");  /*请求输入顺序表中元素个数*/
  scanf("%d",&L.length);
  printf("Please input the Value:\n");  /*请求输入顺序表中各个元素*/
  for (int i=0;i<L.length;i++)
     scanf("%d",&L.elem[i]);
  return OK;
} 
Status SqList_DeleteDuplicate (SqList &L)
{  int i=0,j;
 while(i<L.length-1)
   if (L.elem[i]==L.elem[i+1])     //如果相邻的两个元素ai+1与ai+2比较相等
     { for (j=i+1;j<L.length;j++)   //则删除相等的两个元素中前面那个元素ai+1
	         L.elem[j-1]=L.elem[j];
       L.length--;              
     }
   else
     i++;
 return OK;
}
void Output(SqList  L)    //输出顺序表中各个元素值
{
   for (int i=0;i<L.length;i++)
       printf(" %d",L.elem[i]);
   printf("\n");

}

int main()  {
    SqList  L;
    int i;
    ElemType x,e;
    SqList_Create(L);
    printf("Please input the insert position:");
    scanf("%d", &i);
    printf("Please input the insert elem:");
    scanf("%d", &x);
    if (SqList_Insert(L,i,x)) {
        printf("The list after insert is :\n");
        Output(L); }
    else
        printf("插入失败！\n");
    printf("Please input delete position:");
    scanf("%d", &i);
    if (SqList_Delete(L,i,e)) {
       printf("The list after delete is :\n");
       Output(L); }
    else
        printf("删除失败！\n");
    printf("Please input find elem:");
    scanf("%d", &x);
    if ( SqList_Search(L,x))
        printf("查找成功! the position is %d\n", SqList_Search(L,x));
    else
       printf("查找失败！\n");
    SqList_Create(L);
    SqList_DeleteDuplicate (L);
	Output(L); 
    return 0;
 }
