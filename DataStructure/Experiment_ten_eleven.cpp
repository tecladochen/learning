/**ʵ��10-11  ������Ĳ���ʵ��

һ��ʵ��Ŀ��

1���ܹ����������Ҫ�ڲ����򷽷������˼·��

2���ܹ��ø߼����Ա�д��Ҫ�ڲ������㷨�ڼ�����е�ʵ�֡�

3���ܹ������Ƚ���Ҫ���ڲ����򷽷�֮��������ص㡣

����ʵ������

���ʵ��ͳ��ֱ�Ӳ�������ð�����򡢼�ѡ������ϣ�����򡢿�������͹鲢�����㷨������ʱ�ıȽϴ������ƶ�������

����ʵ��Ҫ��

1������ͬ��һ���������ݣ���Ϊ�������¼�Ĺؼ������С�

2. �ڽ���ֱ�Ӳ�������ð�����򡢼�ѡ�������ͬʱͳ������������жԹؼ��ֵıȽϴ������ƶ����������ֱ��������ǰ���������к��������������м���ͳ�ƽ����

3. �ڽ���ϣ�����򡢿�������͹鲢�����ͬʱͳ������������жԹؼ��ֵıȽϴ������ƶ����������ֱ��������ǰ���������к��������������м���ͳ�ƽ����

4. �������������һ���˵���ʹ�û���ѡ��ִ�����е��κ�һ�ֻ������򣬲��鿴��������
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 80   //˳������󳤶�
typedef int KeyType;   // ���ؼ������Ͷ���Ϊ����
typedef int InfoType;  // ����������������Ҳ����Ϊ����

typedef struct {
	KeyType key; // �ؼ�����
	InfoType other; // ����������
}RedType;  // ��¼����

typedef struct{
	RedType r[MAXSIZE + 1];  //һ�������r[0]����
	int length; // ˳�����
}SqList;   //˳��������

struct number{ 
     int cpn ;      //��¼�Ƚϴ���
     int mvn ;      //��¼�ƶ�����
  } cm[6];         //�ֱ�������¼��������ıȽϺ��ƶ����������ɽ������鶨��Ϊȫ�ֱ���

void menu(){ //ѡ��˵�
	printf("\n");
	printf("1.ֱ�Ӳ�������\n");
	printf("2.ð������\n");
	printf("3.��ѡ������\n");
	printf("4.ϣ������\n");
	printf("5.��������\n");
	printf("6.�鲢����\n");
	printf("7.����������������\n");
	printf("8.�˳�\n");
	return ;
 
}

void displaySqList(SqList L){ //��ӡ����
	printf("[ ");
	for(int i = 1; i <= L.length; i++){
		printf("%4d ",L.r[i].key);
	} 
	printf(" ]\n");
	return;
} 

void Sort_Insert(SqList &L){ //�������ڵ�ֱ�Ӳ��������㷨 
	int i,j;
	for(i = 2; i <= L.length; i++){
		if(cm[0].cpn++ , L.r[i].key < L.r[i - 1].key){
			L.r[0] = L.r[i];
			cm[0].mvn++;
			L.r[i] = L.r[i - 1];
			cm[0].mvn++;
			for(j = i - 2; cm[0].cpn++, L.r[0].key < L.r[j].key; j--){
				L.r[j + 1] = L.r[j];
				cm[0].mvn++;
			}
			L.r[j + 1] = L.r[0];
			cm[0].mvn++;
		}
	}
} 

void Sort_Bubble(SqList &L){ //ð������ 
	int i,j,change;
    RedType temp;
    change = 1;                    //���ý�����־��������ֵΪ��
   for (i = L.length; i > 1 && change; --i)     //������n-1������
     { change = 0;               //ÿ������ʼʱ���ý�����־����ֵΪ��
       for(j = 1;j < i; ++j)
         if (cm[1].cpn++, L.r[j].key > L.r[j+1].key) //�ȽϹؼ���ֵʱ,�Ƚϴ�����1
           { temp = L.r[j];    //���ڵ�������¼����
             L.r[j] = L.r[j+1];
             L.r[j+1] = temp; 
			   cm[1].mvn += 3;   //�ƶ�������3        
             change= 1;
           }//if
     }// for i
}

void Sort_Select(SqList &L){ //��ѡ������
	for(int i = 1; i < L.length; ++i)  //����n-1����
     {  int min = i;          //���������ӱ��еĵ�һ����¼�Ĺؼ�����С
        for(int j = i+1; j <= L.length; ++j)
     	     if (cm[2].cpn++, L.r[j].key < L.r[min].key)//�ȽϹؼ���ֵʱ,�Ƚϴ�����1
     	         min = j;
        if (min != i)        //�����С�ؼ��ּ�¼���������ӱ�ĵ�һ��λ�ã��򽻻�
        {   RedType temp = L.r[i];  //����С�ؼ��ּ�¼�������ӱ��е�һ����¼����
             L.r[i] = L.r[min];
             L.r[min] = temp;	
             cm[2].mvn += 3;   //�ƶ�������3 
        }//if 
     } //for i	
}

void Sort_shell(SqList &L, int dk){ //ϣ������ 
	int i,j; 
    for(i = 1+dk; i <= L.length; i++)
        if (cm[3].cpn++, L.r[i].key < L.r[i-dk].key)     //�� L.r[i]�������������ӱ� 
        	{ L.r[0] = L.r[i];    //��������ĵ�i����¼�ݴ���r[0]�У�ͬʱr[0]Ϊ������
        	  cm[3].mvn++;
           	  L.r[i] = L.r[i-dk];
           	  cm[3].mvn++;
           	  for(j = i - 2 * dk; j > 0 && cm[3].cpn++,L.r[0].key < L.r[j].key; j -= dk)
     	         L.r[j + dk] = L.r[j];       // ��ǰ��Ľϴ���L.r[j+dk]����
     	         cm[3].mvn++;
              L.r[j+dk] = L.r[0];            // ��L.r[i]�����j+dk��λ��
              cm[3].mvn++;
            }
}

void Sort_Shell(SqList &L, int dlta[],int t){
	for(int k = 0; k < t; ++k)
        Sort_shell (L, dlta[k]); 
}

int Partition(SqList &L,int low,int high)  //��L�е��ӱ�L.r[low..high]��һ�˿�������
{  L.r[0] = L.r[low];      //�����������±�ļ�¼����Ϊ����,���ݴ���r[0]�� 
   cm[4].mvn++;
   KeyType privotkey = L.r[low].key;//�������¼�Ĺؼ����ݴ��ڱ���pivotkey��
   cm[4].mvn++;
   while(low < high)      // ��low==highʱ��������������
   {   while(low < high && L.r[high].key >= privotkey)    //��ǰ����
        {--high;
        cm[4].cpn++;
		   }
		cm[4].cpn++; 
       if(low < high){
	      L.r[low++] = L.r[high];    //��������С�ļ�¼�����Ͷ�low��λ�� ��Ȼ��low����һλ 
		  cm[4].mvn++;
		}
       while(low < high && L.r[low].key <= privotkey)    //�������
         {
         	++low;
         	cm[4].cpn++; 
		   }
		   cm[4].cpn++; 
       if (low < high) {
          L.r[high--] = L.r[low];      //��������С�ļ�¼�����Ͷ�low��λ��  ��Ȼ��highǰ��һλ         	   
          cm[4].mvn++;
      }
  }
   L.r[low] = L.r[0];      //�����¼�������λ��
   cm[4].mvn++;
   return low;	        //�����������ڵ�λ��
}

void Q_Sort(SqList &L,int low,int high){//�Ա�r[low..high]���õݹ���ʽ�Ŀ��������㷨 
    if (low < high)                          //������������1
	{  int pivotloc = Partition(L,low,high);//���һ�λ��֣�ȷ������λ��
       Q_Sort(L,low,pivotloc-1);  //�ݹ���ã�������ӱ������
       Q_Sort(L,pivotloc+1,high);  //�ݹ���ã�������ӱ������	
    }	
}

void Sort_Quick(SqList &L){ //�������� 
	Q_Sort(L, 1, L.length);
}

void Merge(RedType SR[],RedType TR[],int i,int m,int n)
//���������������SR[i .. m] ��SR[m+1.. n]�鲢Ϊ�����TR[i .. n]
{ int  j = m + 1,k = i;         
  while(i <= m && j <= n)      // ��SR�����������о������ӱ���С������TR�� 
   {   if(cm[5].cpn++,SR[i].key <= SR[j].key){
           TR[k++] = SR[i++];
           cm[5].mvn++;
		   }
       else {
       	TR[k++]=SR[j++];  
       	cm[5].mvn++;
	   }  
   }
  while (i <= m)           //��ǰһ�����ӱ��ʣ�ಿ�ָ��Ƶ�TR
	  {
	  	TR[k++] = SR[i++]; 
	  	cm[5].mvn++;
	  } 
  while (j <= n)           //����һ�����ӱ��ʣ�ಿ�ָ��Ƶ�TR
      {
      	TR[k++]=SR[j++];
      	cm[5].mvn++;
	  }
 
}//�㷨7-10 

void M_Sort(RedType SR[],RedType TR1[],int s,int t)
// ��SR[s..t]�鲢����ΪTR[s..t] 
{   RedType TR2[MAXSIZE + 1];
    if(s == t) {
	TR1[s] = SR[s];
	cm[5].mvn++;//Ҳ���Բ��ӣ�����ʱ��ĵ���
}
    else {//������ļ�¼����ֻ��һ����¼
    	int m = (s + t) / 2;    // ��mΪ�ֽ�㣬�������ֳ�ǰ����������
    	M_Sort(SR,TR2,s,m);//��ǰ���ֵݹ�鲢Ϊ�����ӱ�TR2[s..m]
    	M_Sort(SR,TR2,m+1,t);//�Ժ󲿷ֵݹ�鲢Ϊ�����ӱ�TR2[m+1..t] 
    	Merge(TR2,TR1,s,m,t);//��TR2[s..m]��TR2[s..m]�鲢�������TR1[s..t]
    }
}//�㷨7-11

void Sort_Merge(SqList &L){ //�鲢���� 
	M_Sort(L.r,L.r,1,L.length);
} 

void Control(){ //�����ƺ��� 
	int e;
	int num = 1;
	int select;
	SqList L;
	printf("���������еĳ���:");
	scanf("%d",&e);
	L.length = e;
	printf("������һ������������:");
	for(int i = 1; i <= L.length; i++){
		scanf("%d",&L.r[i].key);
	}
	while(1){
		SqList temp;
		menu();
		printf("��ѡ��:");
		scanf("%d", &select);
		printf("����ǰ:");
		displaySqList(L);
		temp = L;
		switch(select){
			case 1:{
			Sort_Insert(temp);
			printf("�����:");
			displaySqList(temp);
			printf("�Ƚϴ����� %d ,�ƶ������� %d \n",cm[0].cpn,cm[0].mvn);
			cm[0].cpn = 0;
			cm[0].mvn = 0;
			break;
			}
			case 2:{
			Sort_Bubble(temp);
			printf("�����:");
			displaySqList(temp);
			printf("�Ƚϴ����� %d ,�ƶ������� %d \n",cm[1].cpn,cm[1].mvn);
			cm[1].cpn = 0;
			cm[1].mvn = 0;
			break;
			}
			case 3:{
			Sort_Select(temp);
			printf("�����:");
			displaySqList(temp);
			printf("�Ƚϴ����� %d ,�ƶ������� %d \n",cm[2].cpn,cm[2].mvn);
			cm[2].cpn = 0;
			cm[2].mvn = 0;
			break;
			}
			case 4:{
			int dlta[] = {5,3,1};
			Sort_Shell(temp,dlta,3);
			printf("�����:");
			displaySqList(temp);
			printf("�Ƚϴ����� %d ,�ƶ������� %d \n",cm[3].cpn,cm[3].mvn);
			cm[3].cpn = 0;
			cm[3].mvn = 0;
			break;
			}
			case 5:{
			Sort_Quick(temp);
			printf("�����:");
			displaySqList(temp);
			printf("�Ƚϴ����� %d ,�ƶ������� %d \n",cm[4].cpn,cm[4].mvn);
			cm[4].cpn = 0;
			cm[4].mvn = 0;
			break;
			}
			case 6:{
			Sort_Merge(temp);
			printf("�����:");
			displaySqList(temp);
			printf("�Ƚϴ����� %d ,�ƶ������� %d \n",cm[5].cpn,cm[5].mvn);
			cm[5].cpn = 0;
			cm[5].mvn = 0;
			break;
			}
			case 7:{
			printf("���������еĳ���:");
			scanf("%d",&e);
			L.length = e;
			printf("������һ������������:");
			for(int i = 1; i <= L.length; i++){
			scanf("%d",&L.r[i].key);
				}
			break;
			}
			case 8:{
				exit(0);
				break;
			}
		}
	}
} 

int main(){
	Control();
	return 0;
}
