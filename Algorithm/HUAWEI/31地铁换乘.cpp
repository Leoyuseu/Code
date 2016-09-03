// 已知2条地铁线路，其中A为环线，B为东西向线路，线路都是双向的。
// 经过的站点名分别如下，两条线交叉的换乘点用T1、T2表示。编写程序，
// 任意输入两个站点名称，输出乘坐地铁最少需要经过的车站数量
// （含输入的起点和终点，换乘站点只计算一次）。
// 地铁线A（环线）经过车站：A1 A2 A3 A4 A5 A6 A7 A8 A9 T1 A10 
// 						A11 A12 A13 T2 A14 A15 A16 A17 A18
// 地铁线B（直线）经过车站：B1 B2 B3 B4 B5 T1 B6 B7 B8 B9 B10 
// 							T2 B11 B12 B13 B14 B15

// 方法一：迪杰特斯拉算法：
#include<iostream>
#include<string>
using namespace std;
String name[35]={"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","A11","A12","A13","A14","A15","A16","A17","A18", "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10","B11","B12","B13","B14","B15","T1","T2"};

int getlocation(const string &str)                       //通过站名找下表
{
	for(int i=0;i<35;i++)
		if(name[i]==str)
			return i;
}
int choice(int d[],bool visit[])                       //选择距离最短的点，迪杰特斯拉算法
{
	int min=65535,pos;
	for(int i=0;i<35;i++)
	{
		if(d[i]<min&&!visit[i])
		{
			min=d[i];
			pos=i;
		}
	}
	return pos;
}

void creat(int a[35][35])                               //创建邻接表
{
    for(int i=0;i<35;i++)
		for(int j=0;j<35;j++)
			a[i][j]=65535;
	for(int i=0;i<35;i++)
		a[i][i]=0;
	int b[21]={0,1,2,3,4,5,6,7,8,33,9,10,11,12,34,13,14,15,16,17,0};
	for(int i=0;i<=19;i++)
	{
		a[b[i]][b[i+1]]=1;
		a[b[i+1]][b[i]]=1;
	}
	int c[17]={18,19,20,21,22,33,23,24,25,26,27,34,28,29,30,31,32};
	for(int i=0;i<=15;i++)
	{
		a[c[i]][c[i+1]]=1;
		a[c[i+1]][c[i]]=1;
	}
}
int main()
{   
	bool visit[35]={false};
	int d[35],pos,num;
	int a[35][35];
	creat(a);
	string start,end;
	cin>>start>>end;
	int s=getlocation(start);
	int e=getlocation(end);
	visit[s]=true;
	for(int i=0;i<35;i++)
		d[i]=a[s][i];
	for(int i=1;i<35;i++)                                //n-1次找最短点
	{
		pos=choice(d,visit);
		if(pos==e)
		{
			num=d[pos];
			break;
		}
		visit[pos]=true;
		for(int j=0;j<35;j++)
		{
			if(d[j]>d[pos]+a[pos][j]&&!visit[j])              //更新最短距离
				d[j]=d[pos]+a[pos][j];
		}
	}
	cout<<num<<endl;
	return 0;	
}

// 方法二：邻接表BFS法 （这种方法在这题是错的，求出的只是一种路径，
// 但不一定是最短，放在这仅为练手）
#include<iostream>
#include<string>
using namespace std;
string na[35]={"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","A11","A12","A13","A14",
"A15","A16","A17","A18",              "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10","B11","B12","B13","B14","B15","T1","T2"};

int visit[35]={0};
int getlocation(const string &str)                       //通过站名找下表
{
	for(int i=0;i<35;i++)
		if(na[i]==str)
			return i;
}
struct arr{
	int vertex;
	arr *next;
};
struct node{
	string name;
	arr *firstarr;
};

struct graph{
	int vernum;
	int arrnum;
	node a[35];
};


void creat(graph &g)
{
	for(int i=0;i<g.vernum;i++)
	{
		g.a[i].name=na[i];
		g.a[i].firstarr=NULL;
	}
	arr *p,*q;
	int b[21]={0,1,2,3,4,5,6,7,8,33,9,10,11,12,34,13,14,15,16,17,0};
	int c[17]={18,19,20,21,22,33,23,24,25,26,27,34,28,29,30,31,32};
	int start,end;
	for(int i=0;i<20;i++)
	{
		start=b[i];
		end=b[i+1];
		 p=new arr;
		q=new arr;
		p->vertex=end;
		q->vertex=start;
		p->next=g.a[start].firstarr;             //无向边，考虑双向
		q->next=g.a[end].firstarr;
		g.a[start].firstarr=p;
		g.a[end].firstarr=q;	
	}
		for(int i=0;i<16;i++)
	{
		start=c[i];
		end=c[i+1];
		 p=new arr;
		q=new arr;
		p->vertex=end;
		q->vertex=start;
		p->next=g.a[start].firstarr;
		q->next=g.a[end].firstarr;
		g.a[start].firstarr=p;
		g.a[end].firstarr=q;	
	}
}

void DFS(graph &g,int s,int e,int parent[])
{   
	if(s==e)                    //与BFS遍历不同，找到终点就可以返回
		return;
	arr *p=g.a[s].firstarr;          
	int s1;
	visit[s]=1;               //访问过的设为1
	while(p)
	{   
        s1=p->vertex;
		if(!visit[s1])
		{
			parent[s1]=s;           //记录路径
			DFS(g,s1,e,parent);          
		}
		p=p->next;
	}
}

int print_path(int parent[],int s,int e)
{
	int num=0,m=e;
	cout<<na[m]<<" ";
	while(m!=s)
	{
         m=parent[m];
		 cout<<na[m]<<" "; 
		 num++;               //通过路径回溯计算最小距离
	}
	return num;
}
int main()
{
	graph g;
	g.vernum=35;
	g.arrnum=36;
	creat(g);
	string start,end;
	cin>>start>>end;
	int s,e;
	s=getlocation(start);
	e=getlocation(end);
	int parent[35];
	
	DFS(g,s,e,parent);
	int min=print_path(parent,s,e);
	cout<<min<<endl;
	return 0;
}
