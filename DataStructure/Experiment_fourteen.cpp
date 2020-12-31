#include <stdio.h>
#include <stdlib.h>
#define MAXINT 9999 
#define MAX_VERTEX_NUM 50  //ͼ�����Ķ�����
#define MAXQSIZE 100  //���е���󳤶�
#define MAX_VEX_NUM 50
typedef struct arcnode
   { int adjvex;    //�ڽӶ����λ�����ֵ
     struct arcnode *nextarc; //ָ����һ���ߵ�ָ��
    } arcnode;  //�ߵĽ������
typedef struct vexnode
   { arcnode *firstarc;  //ָ����ö���������ĵ�һ���ߵ�ָ��
     int tag;   //����ķ��ʱ�־
    } vexnode;  //��������
typedef struct
  { vexnode adjlist[MAX_VERTEX_NUM];  //�洢������Ϣ������
    int vexnum,arcnum;  //�������ͱ���
  }Agraph;   //���ڽӱ��ʾ��ͼ����
typedef struct
   { int *base;
     int front;
     int rear;
   } Sqqueue;  //˳���������
typedef struct
  { int cost[MAX_VEX_NUM][MAX_VEX_NUM];  //�ڽӾ���
    int vexnum,arcnum;   //ͼ�Ķ������ͱ���
  }Mgraph;


Agraph creatadjlist(Agraph G)
  //��������ߵĶ���ԣ��������ڽӱ��ʾ������ͼG
 { arcnode *p;
   int v1,v2,i;
   printf("������ͼ�Ķ�����:");//��ʾ����ͼ�ж�����
   scanf("%d,%d",&G.vexnum);
   printf("������ͼ�ı���:");//��ʾ����ͼ�б���
   scanf("%d,%d",&G.arcnum);
   for(i=1;i<=G.vexnum;i++)
    { G.adjlist[i].tag=0;  //��ʼ��������ķ��ʱ�־Ϊ0
      G.adjlist[i].firstarc=NULL;  //��ʼ��ÿ������Ϊ��
    }
   printf("������ͼ�ĸ��ߵĶ����:\n");//��ʾ����ͼ�и��ߵĶ����
   for(i=1;i<=G.arcnum;i++)
    {
      scanf("%d,%d",&v1,&v2);
      p=(arcnode *)malloc(sizeof(arcnode));  //����һ����<v1,v2>�Ľ��
      p->adjvex=v2;    //Ϊ���v2��λ�����ֵ��ֵ
      p->nextarc=G.adjlist[v1].firstarc;   //�����v2���뵽����v1������ı�ͷ
      G.adjlist[v1].firstarc=p;
      p=(arcnode *)malloc(sizeof(arcnode));  //����һ����<v2,v1)�Ľ��
      p->adjvex=v1;    //Ϊ���v1��λ�����ֵ��ֵ
      p->nextarc=G.adjlist[v2].firstarc;   //�����v1���뵽����v2������ı�ͷ
      G.adjlist[v2].firstarc=p;
   }
  return G;
 }
void display(Agraph G)    //ͼ���ڽӱ���������
 { arcnode *p;
   int i;
   for(i=1;i<=G.vexnum;i++) //��������ڽӱ��и�����
    { printf("\n%5d:",i);
      for(p=G.adjlist[i].firstarc;p;p=p->nextarc)
         printf("%5d",p->adjvex);
      printf("\n");
    }
  }

Agraph dfs(Agraph G,int v)  //�Ӷ���v������������ȱ�������ͼG
 { int w;
   arcnode *p;
   printf("%5d",v);    //���ʶ���v
   G.adjlist[v].tag=1;  //����v�ķ��ʱ�־��Ϊ1
   p=G.adjlist[v].firstarc; //p[v]ָ���붥��v������ĵ�һ���ߵĽ��
   while(p!=NULL)
    { w=p->adjvex;  //��ȡ����v���ڽӵĶ���w
      if(G.adjlist[w].tag==0)  //�������wδ������
        G=dfs(G,w);    //�Ӷ���w������������G����������ȱ���
      p=p->nextarc;
    }
  return G;  
 }

Sqqueue  initqueue(Sqqueue Q)//��ʼ��˳�����Q
  { Q.base=(int *)malloc(MAXQSIZE*sizeof(int));
    if(!Q.base)
      printf("OVERFLOW\n");
    else
      Q.front=Q.rear=0;
    return Q;
  }

Sqqueue enqueue(Sqqueue Q,int x)//����к���
  { if ((Q.rear+1)%MAXQSIZE==Q.front)
       printf("ERROR\n");
    else
       {Q.base[Q.rear]=x;
Q.rear=(Q.rear+1)%MAXQSIZE;
       }
    return Q;
  }

Sqqueue dequeue(Sqqueue Q,int *x)//�����к���
  {  if (Q.front==Q.rear)
printf("ERROR\n");
     else
{ *x=Q.base[Q.front];
  Q.front=(Q.front+1)%MAXQSIZE;
        }
    return Q;
  }

void bfs(Agraph G,int v) //�Ӷ���v������������ȱ�������ͼG
 { int v1,w;
   arcnode *p;
   Sqqueue Q;
   Q.base=NULL;
   Q=initqueue(Q);
   printf("%5d",v);   //���ʶ���v
   G.adjlist[v].tag=1;  //�ö���v�ı�־ֵΪ1
   Q=enqueue(Q,v);   //������v���
   while(Q.front!=Q.rear)
    { Q=dequeue(Q,&v1);  //����Ԫ�س���,����v1�������Ԫ��
      p=G.adjlist[v1].firstarc;  //pָ���붥��v1������ĵ�һ���ߵĽ��
      while(p!=NULL)
        { w=p->adjvex;  //��ȡ����v1���ڽӵĶ���w
         if (G.adjlist[w].tag==0)   //�������wδ������
            { printf("%5d",w);   //���ʶ���w
             G.adjlist[w].tag=1;  //����w�ķ��ʱ�־��Ϊ1
              Q=enqueue(Q,w);
             }
         p=p->nextarc;   //pָ���붥��v1��ص���һ���ߵĽ��
        }
     }
  }

  

 void createUDN(Mgraph &G)  
{
 int i,j,k,w;
 int v1,v2;
 printf("���붥���� G.vexnum:");
 scanf("%d,%d",&G.vexnum);
 printf("������� G.arcnum:");
 scanf("%d,%d",&G.arcnum);
 for(i=1;i<=G.vexnum;i++)
    for(j=1;j<=G.vexnum;j++)
        G.cost[i][j]=MAXINT;
  for(k=1;k<=G.arcnum;k++)
  {
 	printf("�����%d����vi��vj��Ȩֵw��int��:\n",k);
 	scanf(" %d %d %d",&v1,&v2,&w);
 	G.cost[v1][v2]=w;
 	G.cost[v2][v1]=G.cost[v1][v2];
  }
} 

void display1(Mgraph G)    
{
int i,j;
    printf(" |");
    for(i=1;i<=G.vexnum;i++)
        printf("%d\t",i);
    printf("\n");
    for(i=1;i<=G.vexnum;i++)
        printf("������");
    printf("\n");
    for(i=1;i<=G.vexnum;i++)
    {   printf("%d|",i);
        for(j=1;j<=G.vexnum;j++)
            printf("%d\t",G.cost[i][j]);
        printf("\n\n");
    }
}
  

  void prim(Mgraph G,int v)
 //����������G����vΪ��ʼ���㹹��һ����С����������������ĸ����ߣ�
{  int i,j,k,min;
   struct    //����Ӷ��㼯U��V-U��Ȩֵ��С�ıߵĸ�������
    { int lowcost;  //lowcost�������Ȩֵ
      int closest;    //closet������Ŷ������
     }closedge[MAX_VEX_NUM];
   for (i=1;i<=G.vexnum;i++)    //��ʼ������closedge
     if (i!=v)
{ closedge[i].lowcost=G.cost[v][i];
          closedge[i].closest=v;
        }
   closedge[v].lowcost=0;       //��ʼU={v}
   for(i=1;i<G.vexnum;i++)
     { k=1;
       min=MAXINT;
       for (j=1;j<=G.vexnum; j++)    //�����е���һ������
          if (closedge[j].lowcost!=0&&closedge[j].lowcost<min)
             { min=closedge[j].lowcost;
              k=j;
              }               //ѡ����СȨֵ����Ӧ�Ķ���p
       printf("%d--%d:%d\n",closedge[k].closest,k,min); //�����С�߼�Ȩֵ
       closedge[k].lowcost=0;  //���¶���p�ӵ��������У�����U����
       for (j=1; j<=G.vexnum;j++)
          if (G.cost[k][j]<closedge[j].lowcost)
             {  closedge[j].lowcost=G.cost[k][j];
                closedge[j].closest=k;
               }    //�¶��㲢��������������ѡ����С��
       }
}



int main()//������
 { int v,x;
   Agraph G;
   Sqqueue Q;
   Mgraph G1;
   while(1)
   {
        printf("\n  1----��������ͼ\n");
        printf("  2----������ȱ���\n");
        printf("  3----������ȱ���\n");
        printf("  4----����������\n");
        printf("  5----������С������\n");
        printf("  6----�˳�\n");
        printf("Please input the select(1-6):");
        scanf("%d",&x);
        switch(x)
        {
            case 1: printf("\n�����ڽӱ�:\n");
                    G=creatadjlist(G); //���ý����ڽӱ��ʾ��ͼ�ĺ���
                    printf("�ڽӱ���:\n");
                    display(G);break;
            case 2: printf("�����������ʼ����:"); //��ʾ�����������ʼ����
                    scanf("%d",&v);dfs(G,v);  //����ͼ��������ȱ�������
                    break;
            case 3: printf("�����������ʼ����:"); //��ʾ�����������ʼ����
                    scanf("%d",&v);bfs(G,v); //����ͼ�Ĺ�����ȱ�������
                    break;
            case 4: createUDN(G1);
                    printf("�����ɹ�:\n");
                    display1(G1);break;
            case 5: printf("���빹����С����������ʼ����:");
                    scanf("%d",&v);
                    prim(G1,v);break;
            case 6: return  0;
        }
   }
  return 1;
}


