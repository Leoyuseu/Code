// 有向无环图：拓扑排序
/* 有向无环图的拓扑排序（也可用于判断是否是有环图，寻找不到入度为0的图）
   进行拓扑排序的方法：
   1.在有向图中选一个没有前驱的顶点且输出
   2.从图中删除该顶点和所有以它为尾的弧*/
/************************************************************************/
#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<fstream>
#include<list>
using namespace std;
#define ERROR 0
struct _VerNode//顶点
{
	_VerNode *next;
	char *name;
};
struct _Edge//边
{
	char *v1;
	char *v2;
};
class CDirectGraph
{
public:
	int VerNum;//图中的顶点数
	int ArcNum;//图中的边数
	int visit[20];//标记位，标记顶点是否已访问过
	_VerNode *VerNode[20];
	int Indegree[20];//存储各顶点的入度
	list<int>ls;//存储入度为0的顶点的队列
	//char *Vexs[20];
public:
	CDirectGraph();
	~CDirectGraph();
	int LocateVex(char *name);//由顶点名获取顶点在图中的序号
	void InsertNode(_VerNode *&root,char *v);//向一个链表中插入一个结点
	void CreateGraph();
	void Show();
	void SetIndegree();//设置各个顶点的入度
	void TopologicalSort();//拓扑排序
};
CDirectGraph::CDirectGraph()
{
	int i;
	for(i=0;i<20;i++)//初始化邻接表头
	{
	VerNode[i]=(_VerNode*)malloc(sizeof(VerNode));
	if(!VerNode[i])
	exit(ERROR);
	VerNode[i]->next=NULL;
	VerNode[i]->name=new char[];
	Indegree[i]=0;
	visit[i]=0;
	}
	VerNum=0;
	ArcNum=0;
}
CDirectGraph::~CDirectGraph()
{

}
int CDirectGraph::LocateVex(char *name)//由顶点名获取顶点在图中的序号
{
	int i;
	for(i=0;i<VerNum;i++)
	{
	if(strcmp(name,VerNode[i]->name)==0)
	return i;
	}
	return -1;
}
void CDirectGraph::InsertNode(_VerNode *&root,char *v)//向一个链表中插入一个结点
{
	_VerNode *head;
	_VerNode *newNode=(_VerNode*)malloc(sizeof(_VerNode));
	if(!newNode)
	exit(ERROR);
	newNode->name=v;
	newNode->next=NULL;

	head=root;
	while(head->next)
	head=head->next;
	head->next=newNode;
	head=newNode;
}
void CDirectGraph::CreateGraph()//由邻接表创建图
{
	_Edge Edge;
	int i,j,k;
	ifstream fin;
	fin.open("data.txt");

	if(fin.is_open())
	{
	fin>>VerNum>>ArcNum;

	   for(i=0;i<VerNum;i++)
	fin>>VerNode[i]->name;
	   for(i=0;i<ArcNum;i++)
	   {

	Edge.v1=new char[];
	Edge.v2=new char[];
	fin>>Edge.v1>>Edge.v2;
	j=LocateVex(Edge.v1);
	k=LocateVex(Edge.v2);
	InsertNode(VerNode[j],Edge.v2);
	   }
	}
	fin.close();
}
void CDirectGraph::Show()//显示有向图
{
	int i;
	for(i=0;i<VerNum;i++)
	{
	_VerNode *p;
	p=VerNode[i]->next;
	cout<<VerNode[i]->name;
	while(p)
	{
	cout<<"---->"<<p->name;
	p=p->next;
	}
	cout<<endl;
	}
}
void CDirectGraph::SetIndegree()//设置图中各节点的入度
{
	int i;
	for(i=0;i<VerNum;i++)
	{
		_VerNode *p;
		p=VerNode[i]->next;
		while(p)
		{
		int k=LocateVex(p->name);
		Indegree[k]++;
		p=p->next;
		}
	}
}
void CDirectGraph::TopologicalSort()
{
	SetIndegree();
	int i;
	while(ls.size()<VerNum)//如果队列中元素小于顶点的个数
	{
	//for(i=0;i<VerNum;i++)
	for(i=VerNum-1;i>=0;i--)//正序和反序得到的结果不一样
	{
	    if(Indegree[i]==0&&visit[i]==0)//当入度为0且没有访问过
	{
	ls.push_back(i);
	visit[i]=1;
	 _VerNode *p;
	  p=VerNode[i]->next;//将以i为尾的各弧的另一个顶点的入度减1
	  while(p)
		{
		int k=LocateVex(p->name);
		Indegree[k]--;
		p=p->next;
		}
		}
		}
	}
	cout<<"图的一个拓扑排序:";
	list<int>::iterator Iter;
	for(Iter=ls.begin();Iter!=ls.end();Iter++)
	cout<<VerNode[*Iter]->name<<" ";

}
int main()
{
	CDirectGraph DG=CDirectGraph();
	DG.CreateGraph();
	cout<<"图的入度表"<<endl;
	DG.Show();
	cout<<endl;  
	DG.TopologicalSort();
}