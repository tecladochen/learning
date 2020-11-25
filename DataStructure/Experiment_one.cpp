/*ʵ��һ ˳���Ļ������� 
һ ʵ��Ŀ��
1���ܹ��ø߼������������Ա��˳��洢�ṹ��
2���ܹ��ø߼����Ա�д����ʵ��˳���Ļ���������
3���ܹ�����˳���Ļ�������ԭ��ʵ������˳����ָ��������
�� ʵ������
1������˳���
2����˳�����ʵ�ֲ��롢ɾ���Ͳ��Ҳ�����
3��ɾ������˳����е��ظ�Ԫ�ء�
�� ʵ��Ҫ��
��1����������˳���ĳ���n��n����������ֵ����һ��˳���
��2����˳���ĵ�i��Ԫ��֮ǰ����һ��ֵΪx��Ԫ�أ������������˳����и�Ԫ��ֵ��
��3��ɾ��˳����е�i��Ԫ�أ������ɾ�����˳����и�Ԫ��ֵ��
��4����˳����в���ֵΪe������Ԫ�أ�������ҳɹ�������������ҳɹ������͸�Ԫ����˳����е�λ�ã��������������ʧ�ܣ�����
��5����������˳���ĳ���m��m���ǵݼ���������������һ������˳���Ȼ��ɾ���������е��ظ�Ԫ�أ�����ͬ������ֻ����һ���� ��������ɾ���������˳����и�Ԫ��ֵ��
*/ 
#include <stdio.h>
#define  MAXLEN  30  /*���Ա����󳤶�*/
#define  ERROR   0
#define  OVERFLOW    -2
#define OK   1
typedef  int  ElemType;
typedef  int  Status;

typedef struct
{   ElemType  elem[MAXLEN]; /*˳����д��Ԫ�ص����飬����ElemTypeΪ�����������ͣ��ڳ������ʵ��ʱ�������������ʹ���*/
    int length;   /*˳���ĳ��ȣ���Ԫ�ظ���*/
}SqList;     /*˳��������*/

Status SqList_Insert(SqList &L,int i,ElemType x)
 /*��˳���L�е�i��Ԫ��ǰ������Ԫ��x*/
{ if (i<1||i>L.length+1) return ERROR; /*����λ�ò���ȷ�����*/
  if (L.length>=MAXLEN)  return OVERFLOW;  /*˳���L���ѷ���Ԫ�أ�����������������*/
  for(int j=L.length-1;j>=i-1;j--)
     L.elem[j+1]=L.elem[j];/*����i��Ԫ�ؼ�����Ԫ��λ�������һλ*/
  L.elem[i-1]=x;   /*�ڵ�i��Ԫ��λ�ô�������Ԫ��x*/
  L.length++;    /*˳���L�ĳ��ȼ�1*/
  return OK;
}

Status SqList_Delete(SqList &L,int i,ElemType &e)
 /*��˳���L��ɾ����i��Ԫ��*/
{  if (i<1||i>L.length)  return ERROR; /*ɾ��λ�ò���ȷ�����*/
   e=L.elem[i-1];
   for(int j=i;j<=L.length-1;j++)
      L.elem[j-1]=L.elem[j]; /*����i+1��Ԫ�ؼ����Ԫ��λ����ǰ��һλ*/
   
   L.length--;   /*˳���L�ĳ��ȼ�1*/
   return OK;
}

int SqList_Search(SqList L,ElemType e)
/* ��˳����в���ֵΪe��Ԫ�أ�����ҵ����������ظ�Ԫ����˳����е�λ�ã����򷵻�0*/
{  int i;
   for ( i=1;i<=L.length&&L.elem[i-1]!=e;i++);  /*�ӵ�һ��Ԫ�ؿ�ʼ���ν�ÿ��Ԫ��ֵ�����ֵx�Ƚ�*/
   if (i<=L.length)
       return  i;
   else
       return  0;
}

Status SqList_Create(SqList  &L)    //����һ��˳���L
{  printf("Please input the length:");  /*��������˳�����Ԫ�ظ���*/
  scanf("%d",&L.length);
  printf("Please input the Value:\n");  /*��������˳����и���Ԫ��*/
  for (int i=0;i<L.length;i++)
     scanf("%d",&L.elem[i]);
  return OK;
} 
Status SqList_DeleteDuplicate (SqList &L)
{  int i=0,j;
 while(i<L.length-1)
   if (L.elem[i]==L.elem[i+1])     //������ڵ�����Ԫ��ai+1��ai+2�Ƚ����
     { for (j=i+1;j<L.length;j++)   //��ɾ����ȵ�����Ԫ����ǰ���Ǹ�Ԫ��ai+1
	         L.elem[j-1]=L.elem[j];
       L.length--;              
     }
   else
     i++;
 return OK;
}
void Output(SqList  L)    //���˳����и���Ԫ��ֵ
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
        printf("����ʧ�ܣ�\n");
    printf("Please input delete position:");
    scanf("%d", &i);
    if (SqList_Delete(L,i,e)) {
       printf("The list after delete is :\n");
       Output(L); }
    else
        printf("ɾ��ʧ�ܣ�\n");
    printf("Please input find elem:");
    scanf("%d", &x);
    if ( SqList_Search(L,x))
        printf("���ҳɹ�! the position is %d\n", SqList_Search(L,x));
    else
       printf("����ʧ�ܣ�\n");
    SqList_Create(L);
    SqList_DeleteDuplicate (L);
	Output(L); 
    return 0;
 }
