/*ʵ��� ����Ĳ���ʵ�� 
һ��ʵ��Ŀ��
  1���ܹ��ø߼������������Ա����ʽ�洢�ṹ��
  2���ܹ��ø߼����Ա�д��������������㷨��ͨ�������������ȷ�ԣ�
  3. �ܹ���������Ļ�������ԭ���������ӵ����⡣
����ʵ������
  1���������������ڵ�������ʵ�ֲ��롢ɾ���Ͳ��Ҳ���;
  2����������������������ϲ���һ���ǵݼ�����������
����ʵ��Ҫ��
  ���ʵ�����¹��ܣ�
  1.���������ĳ���n�͸�������Ԫ��ֵ����һ����ͷ���ĵ���������������и�Ԫ��ֵ���۲����������������������Ƿ�һ��;
  2.������ĵ�i��Ԫ��֮ǰ����һ��ֵΪx��Ԫ�أ�����������������и�Ԫ��ֵ;
  3.ɾ�������е�i��Ԫ�أ��������ɾ����Ԫ��ֵ��ɾ����������и�Ԫ��ֵ;
  4.�������в��ҵ�i������Ԫ�ؽ�㣬������ҳɹ�������ʾ�����ҳɹ������͸�Ԫ�ص�ֵ��������ʾ������ʧ�ܣ���;
  5.���������n��n���������������ݽ���һ����ͷ������������L1����������������и�Ԫ��ֵ;
  6.���������m��m���������������ݽ���һ����ͷ������������L2����������������и�Ԫ��ֵ;
  7.����������L1��L2�ϲ���������L1�У�Ҫ��ʹ��ԭ���еĽ�㣬��ʹL1������ԭ�����ԣ��������ϲ�������������и�����Ԫ��ֵ��
*/ 

#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
typedef int ElemType ;
typedef int Status;
typedef struct  LNode {
    ElemType       data;      // ������
    struct LNode   *next;   // ָ����
} LNode, *LinkList; 

Status LinkList_Creat(LinkList &L,int n)  
  //��ͷ�巨����һ����ͷ���ĵ����� 
{  L=(LinkList)malloc(sizeof(LNode));   //�ȴ���һ�������� 
   L->next=NULL; 
   printf("�밴��λ�������������Ԫ��ֵ:\n  ");//��������n�����Ա��и���Ԫ��
   for(int i=0;i<n;i++)      //����Ԫ�ؽ�����β��������ͷ�� 
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
       // �ڵ�����L�ĵ�i������Ԫ��֮ǰ�����µ�Ԫ��e��i�ĺϷ�ֵ��1��i�ܱ�+1 
{     LinkList p=L,s;          //pָ��ָʾ�����е�ͷ��� 
      int j=0;                 //jָʾpָ����ָ��Ľ���ڱ��е�λ��� 
      while (p&&j<i-1)   //�ҵ���i��Ԫ�ص�ǰ�����,����pָ��ָʾ�� 
      {  p=p->next;
        ++j;
       }
      if (!p ||j>i-1)         // i���Ϸ����Ҳ���ǰ����㣩
         return ERROR;
      s=(LinkList)malloc(sizeof(LNode));  //�����µĽ�� 
      s->data=e;
      s->next=p->next;            //�޸���ָ�룬���½����뵽��i-1��Ԫ�ؽ��p�ĺ��� 
      p->next=s;
      return OK;
}
Status LinkList_Delete(LinkList &L, int i, ElemType &e)
    // ɾ��������L�еĵ�i������Ԫ�أ�����e������ֵ��i�ĺϷ�ֵ��1<=i<=�� 
 {    LinkList p=L,q;          //pָ��ָʾ�����е�ͷ���
      int j=0;                 //jָʾpָ����ָ��Ľ���ڱ��е�λ��� 
      while(p->next &&j<i-1)   //�ҵ��������ǰ�����
      {  p=p->next;
        ++j;
      }
      if(!p->next||j>i-1)     // i���Ϸ����Ҳ���ǰ����㣩
         return ERROR;
     q=p->next;             //qָ���ɾ��� 
     p->next=q->next;      // �޸���ָ���ô�ɾ��������������� 
     e=q->data;            //��e�����ɾ��������Ԫ��ֵ 
     free(q);              //�ͷŴ�ɾ���ռ� 
     return OK;
}
Status LinkList_Locate(LinkList L,int i, ElemType &e) 
 //�������Ա��е�i������Ԫ�أ�������ҳɹ�������e����������Ԫ��ֵ
{  LinkList  p=L->next;   //pָ�������е��׽�� 
   int  j=1;              //j��¼p����ڱ��е�λ���
   while (p&& j<i)        //���ź��ָ��һ��һ��"����"
   {  p=p->next;
      j++;
   }
   if (!p|| j>i)            //iֵ���Ϸ�
      return ERROR;   
   e=p->data;              //��e���ص�i��Ԫ�ص�ֵ 
   return OK;
}

Status Merge( LinkList &L1, LinkList &L2 )
//����������L1��L2�ϲ���L1�У���ʹ�䱣����ԭ������ 
{ LinkList p=L1->next,q=L2->next,r;
  L1->next=NULL;    //����L1��Ϊ�ձ�
  r=L1;         //ʹrָʾ��ǰL1����β�� 
  while(p&&q)
  { if (p->data<=q->data)
     {   r->next=p;     //p���뵽r�ĺ���
         r=p;          //rָʾ��ǰL1�����µ�β���
         p=p->next;    //pָ������
}
    else
       {r->next=q;     //q���뵽r�ĺ���
        r=q;          //rָʾ��ǰL1�����µ�β���
        q=q->next;   //qָ������
       } 
}
  if (p)
     r->next=p;
  else
     r->next=q;
  free(L2);           //�ͷ�L2�ı�ͷ���        
  return  OK;
}// Merge
void LinkList_Out(LinkList L) 
//���������L�и�����Ԫ��ֵ
{   LinkList p=L->next;      // pָ��������׽��
    while(p)
    {  printf("%4d",p->data);   //���pָ����ָ��������ֵ
       p=p->next;            // pָ�����
     }
    printf("\n");
}

int main()
//������ 
{	
  LinkList L,L1;
  int n,i;
  ElemType x;
  printf("Please inputh length:");
  scanf("%d",&n);
  LinkList_Creat(L,n);  //��ͷ�巨����һ����ͷ���ĵ����� 
  printf("The Linklist is:\n");
  LinkList_Out(L);      //����������и�Ԫ��ֵ 
  
  printf("Please input the insert position:");   //��������������λ��
  scanf("%d",&i);
  printf("Please input the insert elem:");     //����������Ҫ�������Ԫ��
  scanf("%d",&x);
  if(LinkList_Insert(L,i,x)){
  		printf("The list after inserted  is:"); 
		}   //���õ�������뺯��1
  else {
  		printf("List Isert Error!\n"); 
  		return 0;
  } 		 
  LinkList_Out(L);          //������������ĵ����� 

  printf("Please input the delete position:");//��������ɾ������λ��
  scanf("%d",&i);
  if(LinkList_Delete(L,i,x)){
  		printf("This is deleted:%d\n",x);
  		printf("The list after deleted  is:"); 
		}   //���õ�������뺯��1
  else {
  		printf("List Delete Error!\n"); 
  		return 0;
  } 		     
     //���õ�����ɾ������
  
  LinkList_Out(L);        //���ɾ��������ĵ����� 
  
  printf("Please input the position you want to search:"); //�������������Ԫ�ص�λ��
  scanf("%d",&i);
  if (LinkList_Locate(L,i,x))   // ������ң�������ҳɹ�������ʾ��i��Ԫ�ص�ֵ��������ʾ��i��Ԫ�ز�����
      printf("The %dth elem is %d\n",i,x);
  else
      printf("The %dth elem is not exsit\n",i);
      
  printf("Please inputh length:");
  scanf("%d",&n);
  LinkList_Creat(L,n);  //��ͷ�巨����һ����ͷ���ĵ����� 
  printf("The Linklist is:");
  LinkList_Out(L);      //����������и�Ԫ��ֵ )
  
  printf("Please inputh length:");
  scanf("%d",&n);
  LinkList_Creat(L1,n);  //��ͷ�巨����һ����ͷ���ĵ����� 
  printf("The Linklist is:");
  LinkList_Out(L1);      //����������и�Ԫ��ֵ 
  Merge(L,L1);
  printf("\nThe After Linklist is:\n");
  LinkList_Out(L);      //����������и�Ԫ��ֵ 
   return 0;		
}
