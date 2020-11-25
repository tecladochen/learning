/*实验三 单链表的综合应用实验
一、实验目的
  1．能够将单链表的创建操作方法运用于多项式的链式存储结构的建立； 
  2．能够将有序单链表的插入操作方法运用于多项式的链式存储结构的建立； 
  3．能够将多项式的加法运算方法运用于编写求两个多项式的加法运算算法中。 
二、实验内容
  已知两个一元多项式 A(x)=a1x
  e1+ a2xe2+ ……+amxem，B(x)= b1x
  e1+ b2xe2+……+ bnxen，其 中 ei 为整数指数且递增有序。
  要求编写算法实现两个一元多项式 A 和 B 的加法运算  A(x)=A(x)+B(x)，并编写程序测试其正确性。
三．实验要求
  1. 分别输入两个多项式的项数及各项的系数和指数， 创建两个多项式。
  2. 对两个多项式求和，并输出求和后的多项式。
  3. 程序的输入与输出请严格按要求设计.
*/
#include  <stdio.h>
#include <malloc.h>
#define OK 1
typedef int Status;      //自定义函数类型为布尔型
typedef struct PolyNode{     // 项的表示
    float coef;             // 系数
    int   expn;            // 指数
    struct PolyNode *next;
} PolyNode , *PolyNomial;  
Status PolyInsert(PolyNomial &L, PolyNode *s) 
// 将结点s按指数递增顺序插入到多项式有序链表L中 
{   PolyNomial p=L;
    int j = 0;
    while (p->next&&p->next->expn<s->expn)   // 与有序链表中的已有项进行指数比较从而确定插入位置 
        p=p->next;
    s->next=p->next;       // 
    p->next=s;  
    return OK;                           
}
Status CreatPolynList(PolyNomial &L,int n)
// 创建一个含n项的多项式有序链表
{   float coef;
    int expn;
    L=(PolyNomial)malloc(sizeof(PolyNode));        // 创建一个空表 
    L->next=NULL;
    for (int i = 1; i <= n; i++)       //将n个多项式项依次插入链表中        
    {  //printf("请输入第%d个项的系数和指数",i);
       scanf("%f,%d",&coef,&expn) ;       // 输入各项的系数和指数值     
       PolyNomial p=(PolyNode *)malloc(sizeof(PolyNode));  //产生新的结点 
       p->coef=coef;
       p->expn=expn;
       PolyInsert(L,p);    // 插入到有序链表
    }
    return OK; 
}
Status PolyAdd(PolyNomial &La, PolyNomial Lb )
 //  求多项式加法La = La + Lb:利用两个多项式的结点构成"和多项式"，并用La返回结果
{   float sum;
    PolyNomial r=La;        // r用于指向新形成链表的尾结点r    
    PolyNomial p=La->next;  //p指向La的第一个结点
    PolyNomial q=Lb->next;  //q指向La的第一个结点
    PolyNomial temp;
    while( p&&q) 
    {  if (p->expn<q->expn)         //p的指数小于q的指数
        {  r->next=p;          //p加入和多项式的尾部
           r=p;                //r 指向当前和多项式的尾结点
           p=p->next;          //p后移 
        }   
        else if (p->expn>q->expn)  //q的指数小于p的指数
        {  r->next=q;         //q加入和多项式的尾部
           r=q;              //r 指向当前和多项式的尾结点
           q=q->next;        //q后移
      }     
        else        //指数相等
        {   sum=p->coef+q->coef;
            if (sum!=0) 
            {   p->coef=sum;   //和写入p的系数域
                r->next=p;      // p加入和多项式的尾部
                r=p ;          //r 指向当前和多项式的尾结点
                p=p->next;     //p后移
                temp=q;        //q为待删除的结点 
               q=q->next;     //q后移
               free(temp);    //删除q 
             }
         else      //和为零，p与q都删除 
             {   temp=p->next;   
                 free(p); 
                 p=temp; 
                 temp=q->next; 
                free(q); 
                q=temp; 
              }
         }
    }//while
    r->next=(p!=NULL)?p:q ;   //将La或Lb中剩余的结点链接到和多项式的尾部
    free(Lb);              // 释放Lb的头结点
    return OK;
}//polyadd
void DisplayPoly(PolyNomial L)
{   PolyNomial p=L->next; 
    i f (p==NULL)             
         printf("Poly is NULL!\n");
    else       //输出第一项
   {   printf("%.2f*x^%d",p->coef,p->expn);
       p=p->next; 
   }
   while(p)
   {  if (p->coef>0)
           printf("+%.2f*x^%d",p->coef,p->expn);
       else 
            printf("%.2f*x^%d",p->coef,p->expn);
       p=p->next;
    }
}
// 主函数—用于测试上述函数 
int  main() 
{   int m,n;
    PolyNomial La,Lb;
   //printf("请输入A多项式的项数：");
   scanf("%d",&m);
   CreatPolynList(La,m);
   //printf("请输入B多项式的项数：");
   scanf("%d",&n);
   CreatPolynList(Lb,n);
   PolyAdd(La,Lb); // 对多项式La、Lb求和，并赋给La
   //printf("求和后的多项式各项为： ");
   DisplayPoly(La); 
}


