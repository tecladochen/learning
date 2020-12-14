/** ʵ��ʮ�� ��̬���ұ��ϲ��� 
һ��ʵ��Ŀ��

1���ܹ��ø߼����Ա�д˳����ҺͶ��ֲ��Ҳ������㷨�ڼ�����е�ʵ�֡�

2���ܹ���ȷ������̬���ұ��ϲ������ԡ�

3���ܹ����ݶ��ֲ��ҵ�˼��Զ��ֲ��Ҳ������Խ�����ȷ�ķ�����

����ʵ������

1������˳����ұ����ڴ˲��ұ���ʵ��˳����Ҳ�����

2��������˳����ұ�ѡ��һ�ּ򵥵����򷽷��Դ˽�������

3. ����������˳����ұ���ʵ�ֶ��ֲ��Ҳ�����

����ʵ��Ҫ��

���ʵ�����¹��ܣ�

��1����������Ĳ��ұ�ı�n��n���ؼ���ֵ������˳����ұ�

��2����˳����ҷ���������˳����ұ��в������Ѿ������ؼ�ֵ��ȵļ�¼��

��3��ѡ��һ�����򷽷��ԣ�1���н�����˳����ұ��������

��4���ڣ�3���е�������ұ����ö��ֲ��ҷ����������Ѿ������ؼ�ֵ��ȵļ�¼ ��

��5����дmain��������Ʋ˵�ʹ�û���ͨ���˵���ѡ����ͨ�������������ܺ�����ʵ����ѡ��Ĳ��Ҳ�����
    
	 ������ÿ�β�����������������������ҳɹ�������������ҳɹ��������������¼�ڱ��е�λ�ã��������������ʧ�ܡ���
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int KeyType;
typedef int InfoType;
typedef struct{
	KeyType key;
	InfoType otherinfo;
}ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SSTable; 

int Search_Seq(SSTable ST, KeyType key)    //˳����ң��̲����㷨9-2
// ���ô������ڵ�˳����ҷ����ڲ��ұ��n����¼�в��ҳ��ؼ���ֵΪkey�ļ�¼
//�����ҳɹ����򷵻����±�λ�ã����򣬷���0
{ int i;
       ST.elem[0].key = key;    //���ڱ���
       for(i=ST.length; ST.elem[i].key!= key; i--);   //�Ӻ���ǰ���в���
       return i;   //���ҵ����򷵻��±�λ�ã���û���ҵ����򷵻�0
 } 
     
int Search_Bin(SSTable ST, KeyType key)   //���ֲ��ң��̲����㷨9-3
// ���ö��ֲ��ҷ�����������n����¼�в��ҳ��ؼ���ֵΪkey�ļ�¼
//�����ҳɹ����򷵻����±�λ�ã����򣬷���0
{   int low=1;         //���ҷ�Χ���½�
      int high=ST.length; //���ҷ�Χ���Ͻ�
      while(low<=high)
      {   int mid=(low+high)/2;//�м�λ�ã���ǰ�Ƚϵļ�¼λ��
          if(key==ST.elem[mid].key)
               return mid;      //���ҳɹ��������±�λ��
          else if(key<ST.elem[mid].key)
               high=mid-1;   //���ҷ�Χ��С��ǰ���
          else
               low=mid+1;   //���ҷ�Χ��С������
     }
    return 0;
 }
 
void Sort_Select(SSTable &ST){
	for(int i = 1; i < ST.length; i++){
		int min = i;
		for(int j = i + 1; j <= ST.length; j++){
			if(ST.elem[j].key < ST.elem[min].key)
				min = j;
			if(min != i){
				ElemType temp = ST.elem[i];
				ST.elem[i] = ST.elem[min];
				ST.elem[min] = temp;
			}
		}
	}
}

int main(){
	int select;
	SSTable ST;
	while(1){
		printf("\n");
		printf("\t1.����ѭ���\n");
		printf("\t2.˳�����\n");
		printf("\t3.���ֲ���\n");
	    printf("\t4.�˳�\n");
	    printf("\t��ѡ��");
	    scanf("%d",&select);
	    switch(select){
	    	case 1: {
	    		int e;
	    		printf("\t������˳����ȣ�");
	    		scanf("%d",&e);
	    		ST.length = e;
	    		ST.elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	    		printf("\t�����������¼�Ĺؼ���ֵ��");
	    		for(int i = 1; i <= e; i++){
	    			scanf("%d", &ST.elem[i].key);
				}
				break;
			} 
			case 2: {
				KeyType e;
				int i;
				printf("\t��������Ҫ���ҵĹؼ��֣�");
				scanf("%d", &e);
				i = Search_Seq(ST, e);
				if(i){
					printf("\t���ҳɹ��������¼�ڱ��е�λ����:%d\n", i);
				}
				else{
					printf("\t����ʧ�ܣ��ؼ��ֲ�����\n");
				}
				break;
			}
			case 3: {
				int i,e;
				Sort_Select(ST);
				printf("\t��������Ҫ���ҵĹؼ��֣�");
				scanf("%d", &e);
				i = Search_Bin(ST, e);
				if(i){
					printf("\t���ҳɹ��������¼�ڱ��е�λ����:%d\n", i);
				}
				else{
					printf("\t����ʧ�ܣ��ؼ��ֲ�����\n");
				}
				break;
			}
			case 4: {
				return 0;
			}
		}
	}
	return 0 ;
}
