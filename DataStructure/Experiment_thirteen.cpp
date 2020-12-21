#include<stdio.h>
#include<stdlib.h>
 typedef struct {
 	int key;
 }RecdType;
 typedef struct TNode{
 	RecdType data;
 	struct TNode *lchild;
 	struct TNode *rchild;
 }TNode,*BiTree;
int InsertDST (BiTree &T,RecdType e);
int CreateDST(BiTree &T,RecdType item[], int n);
int RSearchDST(BiTree T, int key, BiTree f, BiTree &p);
int SearchDST(BiTree T, int key);
 int main(){
 	
 	int n;
 	RecdType item[20];
 	BiTree T,f,p;
 	printf("输入序列长度：");
 	scanf("%d",&n);
 	printf("请输入序列值："); 
 	for(int i = 0; i < n; i++){
	 	scanf("%d",&item[i].key);
	 }
 	CreateDST(T,item,n);
 	printf("请输入待查找值：");
 	int s;
 	scanf("%d",&s);
 	if(SearchDST(T,s))
 		printf("查找成功！\n");
	else
		printf("查找失败！\n");
	return 0;
 }	
 int InsertDST (BiTree &T,RecdType e){
 	BiTree p,s;
 	if(!RSearchDST(T,e.key,NULL,p)){
	 	s = (BiTree)malloc(sizeof(TNode));
	 	s->data = e;
	 	s->lchild = s->rchild = NULL;
	 	if(!p) T = s;
	 	else if(e.key<p->data.key)
	 		p->lchild = s;
 		else p->rchild = s;
 		return 1;
	 }
 	else return 0;
 }
 int CreateDST(BiTree &T,RecdType item[], int n){
 	int i;
 	for(i = 0;i < n; i++){
	 	InsertDST(T,item[i]);
	 }
 	return 1;
 }
 int RSearchDST(BiTree T, int key, BiTree f, BiTree &p){
 	if(!T){
	 	p =f;
	 	return 0;
	 }
	 else if(key == T->data.key){
	  p = T;
	  return 1;
 	}
 	else if(key < T->data.key){
	 	RSearchDST(T->lchild,key,T,p);
	 }
	else{
		RSearchDST(T->rchild,key,T,p);
	}			
}
int SearchDST(BiTree T, int key){
	if(!T || key == T->data.key)
		return 1;
	else if(key < T->data.key) 
		SearchDST(T->lchild,key);
	else 
		SearchDST(T->rchild,key);
	return 0;
}
