#include <stdio.h>
#include <stdlib.h>
#define MAXINT 9999 
#define MAX_VERTEX_NUM 50  //图中最大的顶点数
#define MAXQSIZE 100  //队列的最大长度
#define MAX_VEX_NUM 50
typedef struct arcnode
   { int adjvex;    //邻接顶点的位置序号值
     struct arcnode *nextarc; //指向下一条边的指针
    } arcnode;  //边的结点类型
typedef struct vexnode
   { arcnode *firstarc;  //指向与该顶点相关联的第一条边的指针
     int tag;   //顶点的访问标志
    } vexnode;  //顶点类型
typedef struct
  { vexnode adjlist[MAX_VERTEX_NUM];  //存储顶点信息的数组
    int vexnum,arcnum;  //顶点数和边数
  }Agraph;   //用邻接表表示的图类型
typedef struct
   { int *base;
     int front;
     int rear;
   } Sqqueue;  //顺序队列类型
typedef struct
  { int cost[MAX_VEX_NUM][MAX_VEX_NUM];  //邻接矩阵
    int vexnum,arcnum;   //图的顶点数和边数
  }Mgraph;


Agraph creatadjlist(Agraph G)
  //依次输入边的顶点对，建立用邻接表表示的无向图G
 { arcnode *p;
   int v1,v2,i;
   printf("请输入图的顶点数:");//提示输入图中顶点数
   scanf("%d,%d",&G.vexnum);
   printf("请输入图的边数:");//提示输入图中边数
   scanf("%d,%d",&G.arcnum);
   for(i=1;i<=G.vexnum;i++)
    { G.adjlist[i].tag=0;  //初始化各顶点的访问标志为0
      G.adjlist[i].firstarc=NULL;  //初始化每个链表为空
    }
   printf("请输入图的各边的顶点对:\n");//提示输入图中各边的顶点对
   for(i=1;i<=G.arcnum;i++)
    {
      scanf("%d,%d",&v1,&v2);
      p=(arcnode *)malloc(sizeof(arcnode));  //生成一条边<v1,v2>的结点
      p->adjvex=v2;    //为结点v2的位置序号值赋值
      p->nextarc=G.adjlist[v1].firstarc;   //将结点v2插入到顶点v1的链表的表头
      G.adjlist[v1].firstarc=p;
      p=(arcnode *)malloc(sizeof(arcnode));  //生成一条边<v2,v1)的结点
      p->adjvex=v1;    //为结点v1的位置序号值赋值
      p->nextarc=G.adjlist[v2].firstarc;   //将结点v1插入到顶点v2的链表的表头
      G.adjlist[v2].firstarc=p;
   }
  return G;
 }
void display(Agraph G)    //图的邻接表的输出函数
 { arcnode *p;
   int i;
   for(i=1;i<=G.vexnum;i++) //依次输出邻接表中各顶点
    { printf("\n%5d:",i);
      for(p=G.adjlist[i].firstarc;p;p=p->nextarc)
         printf("%5d",p->adjvex);
      printf("\n");
    }
  }

Agraph dfs(Agraph G,int v)  //从顶点v出发，深度优先遍历无向图G
 { int w;
   arcnode *p;
   printf("%5d",v);    //访问顶点v
   G.adjlist[v].tag=1;  //顶点v的访问标志置为1
   p=G.adjlist[v].firstarc; //p[v]指向与顶点v相关联的第一条边的结点
   while(p!=NULL)
    { w=p->adjvex;  //读取到与v相邻接的顶点w
      if(G.adjlist[w].tag==0)  //如果顶点w未被访问
        G=dfs(G,w);    //从顶点w出发，继续对G进行深度优先遍历
      p=p->nextarc;
    }
  return G;  
 }

Sqqueue  initqueue(Sqqueue Q)//初始化顺序队列Q
  { Q.base=(int *)malloc(MAXQSIZE*sizeof(int));
    if(!Q.base)
      printf("OVERFLOW\n");
    else
      Q.front=Q.rear=0;
    return Q;
  }

Sqqueue enqueue(Sqqueue Q,int x)//入队列函数
  { if ((Q.rear+1)%MAXQSIZE==Q.front)
       printf("ERROR\n");
    else
       {Q.base[Q.rear]=x;
Q.rear=(Q.rear+1)%MAXQSIZE;
       }
    return Q;
  }

Sqqueue dequeue(Sqqueue Q,int *x)//出队列函数
  {  if (Q.front==Q.rear)
printf("ERROR\n");
     else
{ *x=Q.base[Q.front];
  Q.front=(Q.front+1)%MAXQSIZE;
        }
    return Q;
  }

void bfs(Agraph G,int v) //从顶点v出发，广度优先遍历无向图G
 { int v1,w;
   arcnode *p;
   Sqqueue Q;
   Q.base=NULL;
   Q=initqueue(Q);
   printf("%5d",v);   //访问顶点v
   G.adjlist[v].tag=1;  //置顶点v的标志值为1
   Q=enqueue(Q,v);   //将顶点v入队
   while(Q.front!=Q.rear)
    { Q=dequeue(Q,&v1);  //队首元素出队,并用v1保存队首元素
      p=G.adjlist[v1].firstarc;  //p指向与顶点v1相关联的第一条边的结点
      while(p!=NULL)
        { w=p->adjvex;  //读取到与v1相邻接的顶点w
         if (G.adjlist[w].tag==0)   //如果顶点w未被访问
            { printf("%5d",w);   //访问顶点w
             G.adjlist[w].tag=1;  //顶点w的访问标志置为1
              Q=enqueue(Q,w);
             }
         p=p->nextarc;   //p指向与顶点v1相关的下一条边的结点
        }
     }
  }

  

 void createUDN(Mgraph &G)  
{
 int i,j,k,w;
 int v1,v2;
 printf("输入顶点数 G.vexnum:");
 scanf("%d,%d",&G.vexnum);
 printf("输入边数 G.arcnum:");
 scanf("%d,%d",&G.arcnum);
 for(i=1;i<=G.vexnum;i++)
    for(j=1;j<=G.vexnum;j++)
        G.cost[i][j]=MAXINT;
  for(k=1;k<=G.arcnum;k++)
  {
 	printf("输入第%d条边vi、vj和权值w（int）:\n",k);
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
        printf("———");
    printf("\n");
    for(i=1;i<=G.vexnum;i++)
    {   printf("%d|",i);
        for(j=1;j<=G.vexnum;j++)
            printf("%d\t",G.cost[i][j]);
        printf("\n\n");
    }
}
  

  void prim(Mgraph G,int v)
 //根据无向网G，以v为起始顶点构造一棵最小生成树，并输出树的各条边，
{  int i,j,k,min;
   struct    //定义从顶点集U到V-U的权值最小的边的辅助数组
    { int lowcost;  //lowcost用来存放权值
      int closest;    //closet用来存放顶点序号
     }closedge[MAX_VEX_NUM];
   for (i=1;i<=G.vexnum;i++)    //初始化数组closedge
     if (i!=v)
{ closedge[i].lowcost=G.cost[v][i];
          closedge[i].closest=v;
        }
   closedge[v].lowcost=0;       //初始U={v}
   for(i=1;i<G.vexnum;i++)
     { k=1;
       min=MAXINT;
       for (j=1;j<=G.vexnum; j++)    //找树中的下一个顶点
          if (closedge[j].lowcost!=0&&closedge[j].lowcost<min)
             { min=closedge[j].lowcost;
              k=j;
              }               //选择最小权值及对应的顶点p
       printf("%d--%d:%d\n",closedge[k].closest,k,min); //输出最小边及权值
       closedge[k].lowcost=0;  //将新顶点p加到生成树中，并入U集合
       for (j=1; j<=G.vexnum;j++)
          if (G.cost[k][j]<closedge[j].lowcost)
             {  closedge[j].lowcost=G.cost[k][j];
                closedge[j].closest=k;
               }    //新顶点并入生成树后，重新选择最小边
       }
}



int main()//主函数
 { int v,x;
   Agraph G;
   Sqqueue Q;
   Mgraph G1;
   while(1)
   {
        printf("\n  1----建立无向图\n");
        printf("  2----深度优先遍历\n");
        printf("  3----广度优先遍历\n");
        printf("  4----建立无向网\n");
        printf("  5----构造最小生成树\n");
        printf("  6----退出\n");
        printf("Please input the select(1-6):");
        scanf("%d",&x);
        switch(x)
        {
            case 1: printf("\n建立邻接表:\n");
                    G=creatadjlist(G); //调用建立邻接表表示的图的函数
                    printf("邻接表是:\n");
                    display(G);break;
            case 2: printf("输入遍历的起始顶点:"); //提示输入遍历的起始顶点
                    scanf("%d",&v);dfs(G,v);  //调用图的深度优先遍历函数
                    break;
            case 3: printf("输入遍历的起始顶点:"); //提示输入遍历的起始顶点
                    scanf("%d",&v);bfs(G,v); //调用图的广度优先遍历函数
                    break;
            case 4: createUDN(G1);
                    printf("创建成功:\n");
                    display1(G1);break;
            case 5: printf("输入构造最小生成树的起始顶点:");
                    scanf("%d",&v);
                    prim(G1,v);break;
            case 6: return  0;
        }
   }
  return 1;
}


