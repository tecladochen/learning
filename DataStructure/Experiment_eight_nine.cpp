/*实验八和九 二叉树的遍历及其应用操作实验
一、实验目的
  1.能够用高级语言描述二叉树的二叉链表存储结构；
  2.能够用高级语言编写二叉树遍历操作的算法实现。
  3.能够将二叉树的递归定义及其遍历操作特点灵活应用于解决二叉树中更复杂的问题。
二、实验内容
  编程完成如下操作：
  1．创建二叉链表表示的二叉树；
  2．实现二叉树的先根、中根和后根遍历操作；
  3．利用二叉树的遍历操作实现叉树的复制、判断两棵二叉树是否相等、求树中叶子结点的个数、求树的深度和查找等操作。
三、实验要求
  1.假设二叉树的结点值是字符，先根据输入一棵二叉树标明空子树的完整先根遍历序列或者根据输入一棵二叉树的先根遍历序列和中根遍历序列，建立一棵以二叉链表表示的二叉树，并输出建立后的二叉树的先根、中根、后根遍历序列，观察其建立的二叉树是否正确；
  2.复制上述建立的二叉树，并输出复制后的二叉树的后根遍历序列，观察其复制操作是否正确；
  3.判断复制后形成的二叉树是否与原二叉树相等,如果相等,则报告“这两棵树是相等的，复制操作成功”，否则报告“这两棵树是不相等的，复制操作不成功”；
  4.求出其中一棵树中叶子结点的个数并输出其值；
  5.求出其中一棵树中的深度并输出其值；
  6.输入一个指定的字符x，在指定的一棵二叉树中查找值为x的结点，如果查找成功，则输出“OK”，否则输出“ERROR”；
  7.主程序中要求设计一个菜单，允许用户通过菜单来选择依次选择执行“建立一棵二叉树”、“复制二叉树”、“判断两棵二叉树相等”、“求二叉树的叶子结点个数”、“求二叉树的深度”和“查找”的操作。
*/

#include<stdio.h>
#include<stdlib.h>
typedef char TElemType;
typedef struct BiTNode{//结点结构 
	TElemType data;//数据域
	struct BiTNode *lchild, *rchild;//左孩子域和右孩子域 
}BiTNode, *BiTree; 
void CreateTree_empty(BiTree &T){//由表明空子树的完整先根遍历序列建立一个二叉树 
	char ch;
	scanf("%c",&ch);
	if(ch == '#')
		T = NULL;//#表示空树
	else{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateTree_empty(T->lchild);
		CreateTree_empty(T->rchild);
	} 
	return;
}
BiTree CreateTree_PreAndIn(char PreOrder[], char InOrder[], int PreIndex,int InIndex, int count){//由先根和中根遍历序列建立一个二叉树 
	BiTree T;
	if(count > 0){//先根和中根非空，count 表示二叉树中结点数
		char r = PreOrder[PreIndex];
		int i = 0;
		for(; i < count; i++){//寻找根结点在中根遍历序列中的位置
		if(r == InOrder[InIndex + i])
			break;
		}
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = r;
		T->lchild = CreateTree_PreAndIn(PreOrder,InOrder,PreIndex + 1, InIndex,i);
		T->rchild = CreateTree_PreAndIn(PreOrder,InOrder,PreIndex + i + 1, InIndex + i + 1, count -i - 1);
	}
	else
		T = NULL;
	return T;
	
}
void PreRootTraverse(BiTree T){//先根遍历二叉树序列 
	if(T){
		printf("%c",T->data);
		PreRootTraverse(T->lchild);
		PreRootTraverse(T->rchild);
	}
} 
void InRootTraverse(BiTree T){//中根遍历二叉树序列 
	if(T){
		InRootTraverse(T->lchild);
		printf("%c",T->data);
		InRootTraverse(T->rchild);
	}
} 
void PostRootTraverse(BiTree T){//后根遍历二叉树序列 
	if(T){
		PostRootTraverse(T->lchild);
		PostRootTraverse(T->rchild);
		printf("%c",T->data);
	}
} 
void CopyTree(BiTree T1, BiTree &T2){//二叉树的复制 
	if(T1){
		T2 = (BiTree)malloc(sizeof(BiTNode));
		if(!T2){
			printf("空间分配失败!\n");
			return;
		}
		T2->data = T1->data;
		CopyTree(T1->lchild, T2->lchild);
		CopyTree(T1->rchild, T2->rchild);
	}
	else
		T2 = NULL;
	return;
} 
int IsSameTree(BiTree T1, BiTree T2){//判断是否是相同的树 
	if(!T1 && !T2)
		return 1;
	if(T1 && T2)
		if(T1->data == T2->data)
			if(IsSameTree(T1->lchild, T2->lchild))
				if(IsSameTree(T1->rchild, T2->rchild))
					return 1;
	return 0;
}
void Leaf_Tree(BiTree T, int &num){//求一棵二叉树的叶结点和数目 
	if(T){
		if(T->lchild == NULL && T->rchild == NULL)
			num++;
		Leaf_Tree(T->lchild,num);
		Leaf_Tree(T->rchild,num);
	}
}
int Depth_Tree(BiTree T){//求一棵二叉树的深度 
	int depthLeft,depthRight,depthval;
	if(T != NULL){
		depthLeft = Depth_Tree(T->lchild);
		depthRight = Depth_Tree(T->rchild);
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
	else
		depthval = 0;
	return depthval;
} 
int Search_Tree(BiTree &T, char x){//在一棵二叉树中查找一个值 
	if(T != NULL){
		if(T->data == x)
			return 1;
		else
			return (Search_Tree(T->lchild,x) != 0 ? Search_Tree(T->lchild,x) : Search_Tree(T->rchild,x));
	}
	return 0;
} 
BiTree CreateTree(){//建立二叉树模块 
	system("cls");
			int i;
			printf("\t1.使用完整的先根遍历序列建立\n");
			printf("\t2.使用先根序列和中根序列建立\n");
			printf("\t请选择:");
aaa:			
			scanf("%d",&i);
			if(i == 1){
				BiTree T;
				getchar();
				printf("\t请输入带#的完整先根遍历序列:");
				
				CreateTree_empty(T);
//				printf("\t该二叉树的中根序列是:");
//				InRootTraverse(T);
//				printf("\t该二叉树的后根序列是:");
//				PostRootTraverse(T); 
				return T;
			}
			else if(i == 2){
				char PreOrder[20],InOrder[20];
				int i = 0;
				BiTree T;
				printf("\t请输入先根序列:");
				getchar(); 
				scanf("%s",PreOrder);
				printf("\t请输入中根序列:");
				getchar();
				scanf("%s",InOrder);
				for(; PreOrder[i] != '\0'; i++);
//				printf("%d",i); 
				T = CreateTree_PreAndIn(PreOrder,InOrder,0,0,i);
//				printf("\t该二叉树的后根序列是:");
//				PostTootTraverse(T);
				return T;
			}
			else
			getchar();
			 printf("\t输入错误！\n\t请重新输入:");
			 goto aaa;
}
void menu(){//主程序菜单函数 
	printf("\t    选择菜单\n");
	printf("\t1.建立一棵二叉树\n");
	printf("\t2.复制二叉树\n");
	printf("\t3.判断倆棵二叉树相等\n");
	printf("\t4.求二叉树的叶子结点个数\n");
	printf("\t5.求二叉树的深度\n");
	printf("\t6.查找\n");
	printf("\t7.退出\n");
	printf("\n\t请选择:");
	return; 
}
void Control(){//程序主控制函数 
	menu();
	int num=0;
	scanf("%d",&num);
	switch(num){
		case 1:{
			BiTree T;
			T = CreateTree();
			printf("\t该二叉树的先根，中根，后根遍历序列是:\n\t");
			PreRootTraverse(T);
			printf("\n\t");
			InRootTraverse(T);
			printf("\n\t");
			PostRootTraverse(T);putchar('\n');
			break;
		}
		case 2:{
			BiTree T,T2;
			T = CreateTree();
			CopyTree(T,T2);
			printf("\t该树的后根遍历序列是:");
			PostRootTraverse(T); 
			printf("\t复制的树的后根遍历序列是:");
			PostRootTraverse(T2);
			break;
		}
		case 3:{
			BiTree T1,T2;
			printf("\t创建第一棵树\n");
			T1 = CreateTree();
			printf("\t创建第二棵树\n");
			T2 = CreateTree();
			if(IsSameTree(T1, T2))
				printf("\t这俩棵树是相等的!\n");
			else
				printf("\t这俩棵树是不相等的!\n");
			break;
		}
		case 4:{
			int num;
			BiTree T;
			T = CreateTree();
			Leaf_Tree(T,num);
			printf("\t这棵树的叶子结点有%d个!\n",num);
			break;
		} 
		case 5:{
			int depth;
			BiTree T;
			T = CreateTree();
			depth = Depth_Tree(T);
			printf("\t这棵树的深度是%d\n",depth);
			break;
		}
		case 6:{
			char x;
			BiTree T;
			T = CreateTree();
			printf("\t请输入要查找的字符:");
			getchar();
			x = getchar();
			if(Search_Tree(T,x))
				printf("\t这棵树中能找到%c\n",x);
			else
				printf("\t这棵树中找不到%c\n",x);
			break;
		}
		case 7:{
			return;
		}
	}
}
int main(){//主函数 
	Control();
	return 0;
}
