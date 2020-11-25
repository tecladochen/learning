/*ʵ���� ��������ۺ�Ӧ��ʵ��
һ��ʵ��Ŀ��
  1���ܹ���������Ĵ����������������ڶ���ʽ����ʽ�洢�ṹ�Ľ����� 
  2���ܹ�����������Ĳ���������������ڶ���ʽ����ʽ�洢�ṹ�Ľ����� 
  3���ܹ�������ʽ�ļӷ����㷽�������ڱ�д����������ʽ�ļӷ������㷨�С� 
����ʵ������
  ��֪����һԪ����ʽ A(x)=a1x
  e1+ a2xe2+ ����+amxem��B(x)= b1x
  e1+ b2xe2+����+ bnxen���� �� ei Ϊ����ָ���ҵ�������
  Ҫ���д�㷨ʵ������һԪ����ʽ A �� B �ļӷ�����  A(x)=A(x)+B(x)������д�����������ȷ�ԡ�
����ʵ��Ҫ��
  1. �ֱ�������������ʽ�������������ϵ����ָ���� ������������ʽ��
  2. ����������ʽ��ͣ��������ͺ�Ķ���ʽ��
  3. �����������������ϸ�Ҫ�����.
*/
#include  <stdio.h>
#include <malloc.h>
#define OK 1
typedef int Status;      //�Զ��庯������Ϊ������
typedef struct PolyNode{     // ��ı�ʾ
    float coef;             // ϵ��
    int   expn;            // ָ��
    struct PolyNode *next;
} PolyNode , *PolyNomial;  
Status PolyInsert(PolyNomial &L, PolyNode *s) 
// �����s��ָ������˳����뵽����ʽ��������L�� 
{   PolyNomial p=L;
    int j = 0;
    while (p->next&&p->next->expn<s->expn)   // �����������е����������ָ���ȽϴӶ�ȷ������λ�� 
        p=p->next;
    s->next=p->next;       // 
    p->next=s;  
    return OK;                           
}
Status CreatPolynList(PolyNomial &L,int n)
// ����һ����n��Ķ���ʽ��������
{   float coef;
    int expn;
    L=(PolyNomial)malloc(sizeof(PolyNode));        // ����һ���ձ� 
    L->next=NULL;
    for (int i = 1; i <= n; i++)       //��n������ʽ�����β���������        
    {  //printf("�������%d�����ϵ����ָ��",i);
       scanf("%f,%d",&coef,&expn) ;       // ��������ϵ����ָ��ֵ     
       PolyNomial p=(PolyNode *)malloc(sizeof(PolyNode));  //�����µĽ�� 
       p->coef=coef;
       p->expn=expn;
       PolyInsert(L,p);    // ���뵽��������
    }
    return OK; 
}
Status PolyAdd(PolyNomial &La, PolyNomial Lb )
 //  �����ʽ�ӷ�La = La + Lb:������������ʽ�Ľ�㹹��"�Ͷ���ʽ"������La���ؽ��
{   float sum;
    PolyNomial r=La;        // r����ָ�����γ������β���r    
    PolyNomial p=La->next;  //pָ��La�ĵ�һ�����
    PolyNomial q=Lb->next;  //qָ��La�ĵ�һ�����
    PolyNomial temp;
    while( p&&q) 
    {  if (p->expn<q->expn)         //p��ָ��С��q��ָ��
        {  r->next=p;          //p����Ͷ���ʽ��β��
           r=p;                //r ָ��ǰ�Ͷ���ʽ��β���
           p=p->next;          //p���� 
        }   
        else if (p->expn>q->expn)  //q��ָ��С��p��ָ��
        {  r->next=q;         //q����Ͷ���ʽ��β��
           r=q;              //r ָ��ǰ�Ͷ���ʽ��β���
           q=q->next;        //q����
      }     
        else        //ָ�����
        {   sum=p->coef+q->coef;
            if (sum!=0) 
            {   p->coef=sum;   //��д��p��ϵ����
                r->next=p;      // p����Ͷ���ʽ��β��
                r=p ;          //r ָ��ǰ�Ͷ���ʽ��β���
                p=p->next;     //p����
                temp=q;        //qΪ��ɾ���Ľ�� 
               q=q->next;     //q����
               free(temp);    //ɾ��q 
             }
         else      //��Ϊ�㣬p��q��ɾ�� 
             {   temp=p->next;   
                 free(p); 
                 p=temp; 
                 temp=q->next; 
                free(q); 
                q=temp; 
              }
         }
    }//while
    r->next=(p!=NULL)?p:q ;   //��La��Lb��ʣ��Ľ�����ӵ��Ͷ���ʽ��β��
    free(Lb);              // �ͷ�Lb��ͷ���
    return OK;
}//polyadd
void DisplayPoly(PolyNomial L)
{   PolyNomial p=L->next; 
    i f (p==NULL)             
         printf("Poly is NULL!\n");
    else       //�����һ��
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
// �����������ڲ����������� 
int  main() 
{   int m,n;
    PolyNomial La,Lb;
   //printf("������A����ʽ��������");
   scanf("%d",&m);
   CreatPolynList(La,m);
   //printf("������B����ʽ��������");
   scanf("%d",&n);
   CreatPolynList(Lb,n);
   PolyAdd(La,Lb); // �Զ���ʽLa��Lb��ͣ�������La
   //printf("��ͺ�Ķ���ʽ����Ϊ�� ");
   DisplayPoly(La); 
}


