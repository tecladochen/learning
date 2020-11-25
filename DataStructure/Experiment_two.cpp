/*实验二 链表的操作实验 
一、实验目的
  1．能够用高级语言描述线性表的链式存储结构；
  2．能够用高级语言编写链表基本操作的算法并通过程序测试其正确性；
  3. 能够运用链表的基本操作原理解决更复杂的问题。
二、实验内容
  1．建立单链表，并在单链表上实现插入、删除和查找操作;
  2．将两个递增的有序单链表合并成一个非递减的有序单链表；
三、实验要求
  编程实现如下功能：
  1.根据输入表的长度n和各个数据元素值建立一个带头结点的单链表，并输出链表中各元素值，观察输入的内容与输出的内容是否一致;
  2.在链表的第i个元素之前插入一个值为x的元素，并输出插入后的链表中各元素值;
  3.删除链表中第i个元素，并输出被删除的元素值和删除后的链表中各元素值;
  4.在链表中查找第i个数据元素结点，如果查找成功，则显示“查找成功！”和该元素的值，否则显示“查找失败！”;
  5.根据输入的n和n个递增的有序数据建立一个带头结点的有序单链表L1，并输出有序链表中各元素值;
  6.根据输入的m和m个递增的有序数据建立一个带头结点的有序单链表L2，并输出有序链表中各元素值;
  7.将有序链表L1和L2合并到单链表L1中，要求使用原链中的结点，并使L1保持其原有序性，最后输出合并后的有序链表中各结点的元素值。
*/ 

#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
typedef int ElemType ;
typedef int Status;
typedef struct  LNode {
    ElemType       data;      // 数据域
    struct LNode   *next;   // 指针域
} LNode, *LinkList; 

Status LinkList_Creat(LinkList &L,int n)  
  //用头插法创建一个带头结点的单链表 
{  L=(LinkList)malloc(sizeof(LNode));   //先创建一个空链表 
   L->next=NULL; 
   printf("请按逆位序输入各个数据元素值:\n  ");//请求输入n个线性表中各个元素
   for(int i=0;i<n;i++)      //将各元素结点依次插入链表的头部 
   { LinkList p=(LinkList)malloc(sizeof(LNode));
     if (!p)   
	     return ERROR;
     scanf("%d",&p->data);
     p->next=L->next;
     L->next=p;
   }
   return OK;
}
 
Status LinkList_Insert(LinkList &L, int i, ElemType e) 
       // 在单链表L的第i个数据元素之前插入新的元素e，i的合法值是1≤i≤表长+1 
{     LinkList p=L,s;          //p指针指示链表中的头结点 
      int j=0;                 //j指示p指针所指向的结点在表中的位序号 
      while (p&&j<i-1)   //找到第i个元素的前驱结点,并用p指针指示它 
      {  p=p->next;
        ++j;
       }
      if (!p ||j>i-1)         // i不合法（找不到前驱结点）
         return ERROR;
      s=(LinkList)malloc(sizeof(LNode));  //产生新的结点 
      s->data=e;
      s->next=p->next;            //修改链指针，让新结点插入到第i-1个元素结点p的后面 
      p->next=s;
      return OK;
}
Status LinkList_Delete(LinkList &L, int i, ElemType &e)
    // 删除单链表L中的第i个数据元素，并用e返回其值，i的合法值是1<=i<=表长 
 {    LinkList p=L,q;          //p指针指示链表中的头结点
      int j=0;                 //j指示p指针所指向的结点在表中的位序号 
      while(p->next &&j<i-1)   //找到被册结点的前驱结点
      {  p=p->next;
        ++j;
      }
      if(!p->next||j>i-1)     // i不合法（找不到前驱结点）
         return ERROR;
     q=p->next;             //q指向待删结点 
     p->next=q->next;      // 修改链指针让待删结点从链中脱离出来 
     e=q->data;            //用e保存待删结点的数据元素值 
     free(q);              //释放待删结点空间 
     return OK;
}
Status LinkList_Locate(LinkList L,int i, ElemType &e) 
 //查找线性表中第i个数据元素，如果查找成功，则用e返回其数据元素值
{  LinkList  p=L->next;   //p指向链表中的首结点 
   int  j=1;              //j记录p结点在表中的位序号
   while (p&& j<i)        //沿着后继指针一个一个"点数"
   {  p=p->next;
      j++;
   }
   if (!p|| j>i)            //i值不合法
      return ERROR;   
   e=p->data;              //用e返回第i个元素的值 
   return OK;
}

Status Merge( LinkList &L1, LinkList &L2 )
//将有序单链表L1和L2合并到L1中，并使其保持其原有序性 
{ LinkList p=L1->next,q=L2->next,r;
  L1->next=NULL;    //先置L1链为空表
  r=L1;         //使r指示当前L1链的尾部 
  while(p&&q)
  { if (p->data<=q->data)
     {   r->next=p;     //p插入到r的后面
         r=p;          //r指示当前L1链的新的尾结点
         p=p->next;    //p指针下移
}
    else
       {r->next=q;     //q插入到r的后面
        r=q;          //r指示当前L1链的新的尾结点
        q=q->next;   //q指针下移
       } 
}
  if (p)
     r->next=p;
  else
     r->next=q;
  free(L2);           //释放L2的表头结点        
  return  OK;
}// Merge
void LinkList_Out(LinkList L) 
//输出单链表L中各数据元素值
{   LinkList p=L->next;      // p指向链表的首结点
    while(p)
    {  printf("%4d",p->data);   //输出p指针所指结点的数据值
       p=p->next;            // p指针后移
     }
    printf("\n");
}

int main()
//主函数 
{	
  LinkList L,L1;
  int n,i;
  ElemType x;
  printf("Please inputh length:");
  scanf("%d",&n);
  LinkList_Creat(L,n);  //用头插法创建一个带头结点的单链表 
  printf("The Linklist is:\n");
  LinkList_Out(L);      //输出单链表中各元素值 
  
  printf("Please input the insert position:");   //请求输入插入操作位置
  scanf("%d",&i);
  printf("Please input the insert elem:");     //请求输入需要插入的新元素
  scanf("%d",&x);
  if(LinkList_Insert(L,i,x)){
  		printf("The list after inserted  is:"); 
		}   //调用单链表插入函数1
  else {
  		printf("List Isert Error!\n"); 
  		return 0;
  } 		 
  LinkList_Out(L);          //输出插入操作后的单链表 

  printf("Please input the delete position:");//请求输入删除操作位置
  scanf("%d",&i);
  if(LinkList_Delete(L,i,x)){
  		printf("This is deleted:%d\n",x);
  		printf("The list after deleted  is:"); 
		}   //调用单链表插入函数1
  else {
  		printf("List Delete Error!\n"); 
  		return 0;
  } 		     
     //调用单链表删除函数
  
  LinkList_Out(L);        //输出删除操作后的单链表 
  
  printf("Please input the position you want to search:"); //请求输入待查找元素的位置
  scanf("%d",&i);
  if (LinkList_Locate(L,i,x))   // 按序号找，如果查找成功，则显示第i个元素的值，否则显示第i个元素不存在
      printf("The %dth elem is %d\n",i,x);
  else
      printf("The %dth elem is not exsit\n",i);
      
  printf("Please inputh length:");
  scanf("%d",&n);
  LinkList_Creat(L,n);  //用头插法创建一个带头结点的单链表 
  printf("The Linklist is:");
  LinkList_Out(L);      //输出单链表中各元素值 )
  
  printf("Please inputh length:");
  scanf("%d",&n);
  LinkList_Creat(L1,n);  //用头插法创建一个带头结点的单链表 
  printf("The Linklist is:");
  LinkList_Out(L1);      //输出单链表中各元素值 
  Merge(L,L1);
  printf("\nThe After Linklist is:\n");
  LinkList_Out(L);      //输出单链表中各元素值 
   return 0;		
}
