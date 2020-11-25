/*ʵ��˺;� �������ı�������Ӧ�ò���ʵ��
һ��ʵ��Ŀ��
  1.�ܹ��ø߼����������������Ķ�������洢�ṹ��
  2.�ܹ��ø߼����Ա�д�����������������㷨ʵ�֡�
  3.�ܹ����������ĵݹ鶨�弰����������ص����Ӧ���ڽ���������и����ӵ����⡣
����ʵ������
  ���������²�����
  1���������������ʾ�Ķ�������
  2��ʵ�ֶ��������ȸ����и��ͺ������������
  3�����ö������ı�������ʵ�ֲ����ĸ��ơ��ж����ö������Ƿ���ȡ�������Ҷ�ӽ��ĸ�������������ȺͲ��ҵȲ�����
����ʵ��Ҫ��
  1.����������Ľ��ֵ���ַ����ȸ�������һ�ö����������������������ȸ��������л��߸�������һ�ö��������ȸ��������к��и��������У�����һ���Զ��������ʾ�Ķ������������������Ķ��������ȸ����и�������������У��۲��佨���Ķ������Ƿ���ȷ��
  2.�������������Ķ���������������ƺ�Ķ������ĺ���������У��۲��临�Ʋ����Ƿ���ȷ��
  3.�жϸ��ƺ��γɵĶ������Ƿ���ԭ���������,������,�򱨸桰������������ȵģ����Ʋ����ɹ��������򱨸桰���������ǲ���ȵģ����Ʋ������ɹ�����
  4.�������һ������Ҷ�ӽ��ĸ����������ֵ��
  5.�������һ�����е���Ȳ������ֵ��
  6.����һ��ָ�����ַ�x����ָ����һ�ö������в���ֵΪx�Ľ�㣬������ҳɹ����������OK�������������ERROR����
  7.��������Ҫ�����һ���˵��������û�ͨ���˵���ѡ������ѡ��ִ�С�����һ�ö��������������ƶ������������ж����ö�������ȡ��������������Ҷ�ӽ����������������������ȡ��͡����ҡ��Ĳ�����
*/

#include<stdio.h>
#include<stdlib.h>
typedef char TElemType;
typedef struct BiTNode{//���ṹ 
	TElemType data;//������
	struct BiTNode *lchild, *rchild;//��������Һ����� 
}BiTNode, *BiTree; 
void CreateTree_empty(BiTree &T){//�ɱ����������������ȸ��������н���һ�������� 
	char ch;
	scanf("%c",&ch);
	if(ch == '#')
		T = NULL;//#��ʾ����
	else{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateTree_empty(T->lchild);
		CreateTree_empty(T->rchild);
	} 
	return;
}
BiTree CreateTree_PreAndIn(char PreOrder[], char InOrder[], int PreIndex,int InIndex, int count){//���ȸ����и��������н���һ�������� 
	BiTree T;
	if(count > 0){//�ȸ����и��ǿգ�count ��ʾ�������н����
		char r = PreOrder[PreIndex];
		int i = 0;
		for(; i < count; i++){//Ѱ�Ҹ�������и����������е�λ��
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
void PreRootTraverse(BiTree T){//�ȸ��������������� 
	if(T){
		printf("%c",T->data);
		PreRootTraverse(T->lchild);
		PreRootTraverse(T->rchild);
	}
} 
void InRootTraverse(BiTree T){//�и��������������� 
	if(T){
		InRootTraverse(T->lchild);
		printf("%c",T->data);
		InRootTraverse(T->rchild);
	}
} 
void PostRootTraverse(BiTree T){//����������������� 
	if(T){
		PostRootTraverse(T->lchild);
		PostRootTraverse(T->rchild);
		printf("%c",T->data);
	}
} 
void CopyTree(BiTree T1, BiTree &T2){//�������ĸ��� 
	if(T1){
		T2 = (BiTree)malloc(sizeof(BiTNode));
		if(!T2){
			printf("�ռ����ʧ��!\n");
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
int IsSameTree(BiTree T1, BiTree T2){//�ж��Ƿ�����ͬ���� 
	if(!T1 && !T2)
		return 1;
	if(T1 && T2)
		if(T1->data == T2->data)
			if(IsSameTree(T1->lchild, T2->lchild))
				if(IsSameTree(T1->rchild, T2->rchild))
					return 1;
	return 0;
}
void Leaf_Tree(BiTree T, int &num){//��һ�ö�������Ҷ������Ŀ 
	if(T){
		if(T->lchild == NULL && T->rchild == NULL)
			num++;
		Leaf_Tree(T->lchild,num);
		Leaf_Tree(T->rchild,num);
	}
}
int Depth_Tree(BiTree T){//��һ�ö���������� 
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
int Search_Tree(BiTree &T, char x){//��һ�ö������в���һ��ֵ 
	if(T != NULL){
		if(T->data == x)
			return 1;
		else
			return (Search_Tree(T->lchild,x) != 0 ? Search_Tree(T->lchild,x) : Search_Tree(T->rchild,x));
	}
	return 0;
} 
BiTree CreateTree(){//����������ģ�� 
	system("cls");
			int i;
			printf("\t1.ʹ���������ȸ��������н���\n");
			printf("\t2.ʹ���ȸ����к��и����н���\n");
			printf("\t��ѡ��:");
aaa:			
			scanf("%d",&i);
			if(i == 1){
				BiTree T;
				getchar();
				printf("\t�������#�������ȸ���������:");
				
				CreateTree_empty(T);
//				printf("\t�ö��������и�������:");
//				InRootTraverse(T);
//				printf("\t�ö������ĺ��������:");
//				PostRootTraverse(T); 
				return T;
			}
			else if(i == 2){
				char PreOrder[20],InOrder[20];
				int i = 0;
				BiTree T;
				printf("\t�������ȸ�����:");
				getchar(); 
				scanf("%s",PreOrder);
				printf("\t�������и�����:");
				getchar();
				scanf("%s",InOrder);
				for(; PreOrder[i] != '\0'; i++);
//				printf("%d",i); 
				T = CreateTree_PreAndIn(PreOrder,InOrder,0,0,i);
//				printf("\t�ö������ĺ��������:");
//				PostTootTraverse(T);
				return T;
			}
			else
			getchar();
			 printf("\t�������\n\t����������:");
			 goto aaa;
}
void menu(){//������˵����� 
	printf("\t    ѡ��˵�\n");
	printf("\t1.����һ�ö�����\n");
	printf("\t2.���ƶ�����\n");
	printf("\t3.�жςz�ö��������\n");
	printf("\t4.���������Ҷ�ӽ�����\n");
	printf("\t5.������������\n");
	printf("\t6.����\n");
	printf("\t7.�˳�\n");
	printf("\n\t��ѡ��:");
	return; 
}
void Control(){//���������ƺ��� 
	menu();
	int num=0;
	scanf("%d",&num);
	switch(num){
		case 1:{
			BiTree T;
			T = CreateTree();
			printf("\t�ö��������ȸ����и����������������:\n\t");
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
			printf("\t�����ĺ������������:");
			PostRootTraverse(T); 
			printf("\t���Ƶ����ĺ������������:");
			PostRootTraverse(T2);
			break;
		}
		case 3:{
			BiTree T1,T2;
			printf("\t������һ����\n");
			T1 = CreateTree();
			printf("\t�����ڶ�����\n");
			T2 = CreateTree();
			if(IsSameTree(T1, T2))
				printf("\t������������ȵ�!\n");
			else
				printf("\t���������ǲ���ȵ�!\n");
			break;
		}
		case 4:{
			int num;
			BiTree T;
			T = CreateTree();
			Leaf_Tree(T,num);
			printf("\t�������Ҷ�ӽ����%d��!\n",num);
			break;
		} 
		case 5:{
			int depth;
			BiTree T;
			T = CreateTree();
			depth = Depth_Tree(T);
			printf("\t������������%d\n",depth);
			break;
		}
		case 6:{
			char x;
			BiTree T;
			T = CreateTree();
			printf("\t������Ҫ���ҵ��ַ�:");
			getchar();
			x = getchar();
			if(Search_Tree(T,x))
				printf("\t����������ҵ�%c\n",x);
			else
				printf("\t��������Ҳ���%c\n",x);
			break;
		}
		case 7:{
			return;
		}
	}
}
int main(){//������ 
	Control();
	return 0;
}
