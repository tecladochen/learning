/** 实验十二 静态查找表上查找 
一、实验目的

1．能够用高级语言编写顺序查找和二分查找操作的算法在计算机中的实现。

2．能够正确分析静态查找表上操作特性。

3．能够根据二分查找的思想对二分查找操作的性进行正确的分析。

二、实验内容

1．建立顺序查找表，并在此查找表上实现顺序查找操作。

2．对上述顺序查找表选择一种简单的排序方法对此进行排序

3. 在上述有序顺序查找表上实现二分查找操作。

三、实验要求

编程实现如下功能：

（1）根据输入的查找表的表长n和n个关键字值，建立顺序查找表；

（2）用顺序查找方法在上述顺序查找表中查找与已经给定关键值相等的记录；

（3）选择一种排序方法对（1）中建立的顺序查找表进行排序；

（4）在（3）中的有序查找表中用二分查找方法查找与已经给定关键值相等的记录 ；

（5）编写main函数，设计菜单使用户能通过菜单的选择多次通过调用上述功能函数来实现所选择的查找操作，
    
	 并且在每次操作后都输出其操作结果：若查找成功，则输出“查找成功”并输出这条记录在表中的位置，否则输出“查找失败”。
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

int Search_Seq(SSTable ST, KeyType key)    //顺序查找，教材中算法9-2
// 采用带监视哨的顺序查找方法在查找表的n个记录中查找出关键字值为key的记录
//若查找成功，则返回其下标位置；否则，返回0
{ int i;
       ST.elem[0].key = key;    //“哨兵”
       for(i=ST.length; ST.elem[i].key!= key; i--);   //从后往前进行查找
       return i;   //若找到，则返回下标位置；若没有找到，则返回0
 } 
     
int Search_Bin(SSTable ST, KeyType key)   //二分查找，教材中算法9-3
// 采用二分查找方法在有序表的n个记录中查找出关键字值为key的记录
//若查找成功，则返回其下标位置；否则，返回0
{   int low=1;         //查找范围的下界
      int high=ST.length; //查找范围的上界
      while(low<=high)
      {   int mid=(low+high)/2;//中间位置，当前比较的记录位置
          if(key==ST.elem[mid].key)
               return mid;      //查找成功，返回下标位置
          else if(key<ST.elem[mid].key)
               high=mid-1;   //查找范围缩小到前半段
          else
               low=mid+1;   //查找范围缩小到后半段
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
		printf("\t1.创建循序表\n");
		printf("\t2.顺序查找\n");
		printf("\t3.二分查找\n");
	    printf("\t4.退出\n");
	    printf("\t请选择：");
	    scanf("%d",&select);
	    switch(select){
	    	case 1: {
	    		int e;
	    		printf("\t请输入顺序表长度：");
	    		scanf("%d",&e);
	    		ST.length = e;
	    		ST.elem = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	    		printf("\t请输入各个记录的关键字值：");
	    		for(int i = 1; i <= e; i++){
	    			scanf("%d", &ST.elem[i].key);
				}
				break;
			} 
			case 2: {
				KeyType e;
				int i;
				printf("\t请输入需要查找的关键字：");
				scanf("%d", &e);
				i = Search_Seq(ST, e);
				if(i){
					printf("\t查找成功，这个记录在表中的位置是:%d\n", i);
				}
				else{
					printf("\t查找失败，关键字不存在\n");
				}
				break;
			}
			case 3: {
				int i,e;
				Sort_Select(ST);
				printf("\t请输入需要查找的关键字：");
				scanf("%d", &e);
				i = Search_Bin(ST, e);
				if(i){
					printf("\t查找成功，这个记录在表中的位置是:%d\n", i);
				}
				else{
					printf("\t查找失败，关键字不存在\n");
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
