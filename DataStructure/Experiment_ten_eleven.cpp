/**实验10-11  内排序的操作实验

一、实验目的

1．能够清楚表述主要内部排序方法的设计思路。

2．能够用高级语言编写主要内部排序算法在计算机中的实现。

3．能够分析比较主要的内部排序方法之间的性能特点。

二、实验内容

编程实现统计直接插入排序、冒泡排序、简单选择排序、希尔排序、快速排序和归并排序算法在运行时的比较次数和移动次数。

三、实验要求

1．输入同样一组整型数据，作为待排序记录的关键字序列。

2. 在进行直接插入排序、冒泡排序、简单选择排序的同时统计在排序过程中对关键字的比较次数和移动次数，并分别输出排序前的数据序列和排序后的数据序列及其统计结果。

3. 在进行希尔排序、快速排序和归并排序的同时统计在排序过程中对关键字的比较次数和移动次数，并分别输出排序前的数据序列和排序后的数据序列及其统计结果。

4. 在主程序中设计一个菜单，使用户可选择执行其中的任何一种或几种排序，并查看排序结果。
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 80   //顺序表的最大长度
typedef int KeyType;   // 将关键字类型定义为整型
typedef int InfoType;  // 将其它数据项类型也定义为整型

typedef struct {
	KeyType key; // 关键字项
	InfoType other; // 其它数据项
}RedType;  // 记录类型

typedef struct{
	RedType r[MAXSIZE + 1];  //一般情况将r[0]闲置
	int length; // 顺序表长度
}SqList;   //顺序表的类型

struct number{ 
     int cpn ;      //记录比较次数
     int mvn ;      //记录移动次数
  } cm[6];         //分别用来记录三种排序的比较和移动次数，并可将此数组定义为全局变量

void menu(){ //选择菜单
	printf("\n");
	printf("1.直接插入排序\n");
	printf("2.冒泡排序\n");
	printf("3.简单选择排序\n");
	printf("4.希尔排序\n");
	printf("5.快速排序\n");
	printf("6.归并排序\n");
	printf("7.重新输入整数序列\n");
	printf("8.退出\n");
	return ;
 
}

void displaySqList(SqList L){ //打印序列
	printf("[ ");
	for(int i = 1; i <= L.length; i++){
		printf("%4d ",L.r[i].key);
	} 
	printf(" ]\n");
	return;
} 

void Sort_Insert(SqList &L){ //带监视哨的直接插入排序算法 
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

void Sort_Bubble(SqList &L){ //冒泡排序 
	int i,j,change;
    RedType temp;
    change = 1;                    //设置交换标志变量，初值为真
   for (i = L.length; i > 1 && change; --i)     //控制做n-1趟排序
     { change = 0;               //每趟排序开始时设置交换标志变量值为假
       for(j = 1;j < i; ++j)
         if (cm[1].cpn++, L.r[j].key > L.r[j+1].key) //比较关键字值时,比较次数加1
           { temp = L.r[j];    //相邻的两个记录交换
             L.r[j] = L.r[j+1];
             L.r[j+1] = temp; 
			   cm[1].mvn += 3;   //移动次数加3        
             change= 1;
           }//if
     }// for i
}

void Sort_Select(SqList &L){ //简单选择排序
	for(int i = 1; i < L.length; ++i)  //控制n-1趟排
     {  int min = i;          //假设无序子表中的第一条记录的关键字最小
        for(int j = i+1; j <= L.length; ++j)
     	     if (cm[2].cpn++, L.r[j].key < L.r[min].key)//比较关键字值时,比较次数加1
     	         min = j;
        if (min != i)        //如果最小关键字记录不在无序子表的第一个位置，则交换
        {   RedType temp = L.r[i];  //将最小关键字记录与无序子表中第一个记录交换
             L.r[i] = L.r[min];
             L.r[min] = temp;	
             cm[2].mvn += 3;   //移动次数加3 
        }//if 
     } //for i	
}

void Sort_shell(SqList &L, int dk){ //希尔排序 
	int i,j; 
    for(i = 1+dk; i <= L.length; i++)
        if (cm[3].cpn++, L.r[i].key < L.r[i-dk].key)     //将 L.r[i]插入有序增量子表 
        	{ L.r[0] = L.r[i];    //将待插入的第i个记录暂存在r[0]中，同时r[0]为监视哨
        	  cm[3].mvn++;
           	  L.r[i] = L.r[i-dk];
           	  cm[3].mvn++;
           	  for(j = i - 2 * dk; j > 0 && cm[3].cpn++,L.r[0].key < L.r[j].key; j -= dk)
     	         L.r[j + dk] = L.r[j];       // 将前面的较大者L.r[j+dk]后移
     	         cm[3].mvn++;
              L.r[j+dk] = L.r[0];            // 将L.r[i]插入第j+dk个位置
              cm[3].mvn++;
            }
}

void Sort_Shell(SqList &L, int dlta[],int t){
	for(int k = 0; k < t; ++k)
        Sort_shell (L, dlta[k]); 
}

int Partition(SqList &L,int low,int high)  //对L中的子表L.r[low..high]做一趟快速排序
{  L.r[0] = L.r[low];      //将无序区低下标的记录设置为枢轴,并暂存在r[0]中 
   cm[4].mvn++;
   KeyType privotkey = L.r[low].key;//将枢轴记录的关键字暂存在变量pivotkey中
   cm[4].mvn++;
   while(low < high)      // 当low==high时，结束本趟排序
   {   while(low < high && L.r[high].key >= privotkey)    //向前搜索
        {--high;
        cm[4].cpn++;
		   }
		cm[4].cpn++; 
       if(low < high){
	      L.r[low++] = L.r[high];    //将比枢轴小的记录移至低端low的位置 ，然后low后移一位 
		  cm[4].mvn++;
		}
       while(low < high && L.r[low].key <= privotkey)    //向后搜索
         {
         	++low;
         	cm[4].cpn++; 
		   }
		   cm[4].cpn++; 
       if (low < high) {
          L.r[high--] = L.r[low];      //将比枢轴小的记录移至低端low的位置  ，然后high前移一位         	   
          cm[4].mvn++;
      }
  }
   L.r[low] = L.r[0];      //枢轴记录移至最后位置
   cm[4].mvn++;
   return low;	        //返回枢轴所在的位置
}

void Q_Sort(SqList &L,int low,int high){//对表r[low..high]采用递归形式的快速排序算法 
    if (low < high)                          //如果无序表长大于1
	{  int pivotloc = Partition(L,low,high);//完成一次划分，确定枢轴位置
       Q_Sort(L,low,pivotloc-1);  //递归调用，完成左子表的排序
       Q_Sort(L,pivotloc+1,high);  //递归调用，完成右子表的排序	
    }	
}

void Sort_Quick(SqList &L){ //快速排序 
	Q_Sort(L, 1, L.length);
}

void Merge(RedType SR[],RedType TR[],int i,int m,int n)
//将两个相邻有序表SR[i .. m] 与SR[m+1.. n]归并为有序表TR[i .. n]
{ int  j = m + 1,k = i;         
  while(i <= m && j <= n)      // 将SR中两个相邻有就有序子表由小到大并入TR中 
   {   if(cm[5].cpn++,SR[i].key <= SR[j].key){
           TR[k++] = SR[i++];
           cm[5].mvn++;
		   }
       else {
       	TR[k++]=SR[j++];  
       	cm[5].mvn++;
	   }  
   }
  while (i <= m)           //将前一有序子表的剩余部分复制到TR
	  {
	  	TR[k++] = SR[i++]; 
	  	cm[5].mvn++;
	  } 
  while (j <= n)           //将后一有序子表的剩余部分复制到TR
      {
      	TR[k++]=SR[j++];
      	cm[5].mvn++;
	  }
 
}//算法7-10 

void M_Sort(RedType SR[],RedType TR1[],int s,int t)
// 将SR[s..t]归并排序为TR[s..t] 
{   RedType TR2[MAXSIZE + 1];
    if(s == t) {
	TR1[s] = SR[s];
	cm[5].mvn++;//也可以不加，看到时候的调试
}
    else {//待排序的记录序列只含一条记录
    	int m = (s + t) / 2;    // 以m为分界点，将无序表分成前、后两部分
    	M_Sort(SR,TR2,s,m);//对前部分递归归并为有序子表TR2[s..m]
    	M_Sort(SR,TR2,m+1,t);//对后部分递归归并为有序子表TR2[m+1..t] 
    	Merge(TR2,TR1,s,m,t);//将TR2[s..m]与TR2[s..m]归并成有序表TR1[s..t]
    }
}//算法7-11

void Sort_Merge(SqList &L){ //归并排序 
	M_Sort(L.r,L.r,1,L.length);
} 

void Control(){ //主控制函数 
	int e;
	int num = 1;
	int select;
	SqList L;
	printf("请输入序列的长度:");
	scanf("%d",&e);
	L.length = e;
	printf("请输入一个整数的序列:");
	for(int i = 1; i <= L.length; i++){
		scanf("%d",&L.r[i].key);
	}
	while(1){
		SqList temp;
		menu();
		printf("请选择:");
		scanf("%d", &select);
		printf("排序前:");
		displaySqList(L);
		temp = L;
		switch(select){
			case 1:{
			Sort_Insert(temp);
			printf("排序后:");
			displaySqList(temp);
			printf("比较次数是 %d ,移动次数是 %d \n",cm[0].cpn,cm[0].mvn);
			cm[0].cpn = 0;
			cm[0].mvn = 0;
			break;
			}
			case 2:{
			Sort_Bubble(temp);
			printf("排序后:");
			displaySqList(temp);
			printf("比较次数是 %d ,移动次数是 %d \n",cm[1].cpn,cm[1].mvn);
			cm[1].cpn = 0;
			cm[1].mvn = 0;
			break;
			}
			case 3:{
			Sort_Select(temp);
			printf("排序后:");
			displaySqList(temp);
			printf("比较次数是 %d ,移动次数是 %d \n",cm[2].cpn,cm[2].mvn);
			cm[2].cpn = 0;
			cm[2].mvn = 0;
			break;
			}
			case 4:{
			int dlta[] = {5,3,1};
			Sort_Shell(temp,dlta,3);
			printf("排序后:");
			displaySqList(temp);
			printf("比较次数是 %d ,移动次数是 %d \n",cm[3].cpn,cm[3].mvn);
			cm[3].cpn = 0;
			cm[3].mvn = 0;
			break;
			}
			case 5:{
			Sort_Quick(temp);
			printf("排序后:");
			displaySqList(temp);
			printf("比较次数是 %d ,移动次数是 %d \n",cm[4].cpn,cm[4].mvn);
			cm[4].cpn = 0;
			cm[4].mvn = 0;
			break;
			}
			case 6:{
			Sort_Merge(temp);
			printf("排序后:");
			displaySqList(temp);
			printf("比较次数是 %d ,移动次数是 %d \n",cm[5].cpn,cm[5].mvn);
			cm[5].cpn = 0;
			cm[5].mvn = 0;
			break;
			}
			case 7:{
			printf("请输入序列的长度:");
			scanf("%d",&e);
			L.length = e;
			printf("请输入一个整数的序列:");
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
