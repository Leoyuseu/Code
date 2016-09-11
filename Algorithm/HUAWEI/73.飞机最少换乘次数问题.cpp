// 设有n个城市，编号为0～n-1，m条单向航线的起点和终点由输入提供，
// 寻找一条换乘次数最少的线路方案。
// 输入
// 第一行为三个整数n、m、v，表示城市数、单向航线数和起点城市。
// 以下m行每行两个整数，表示一条边的起点、终点，保证不重复、不失败。
// 2≤n≤20，1≤m≤190
// 输出
// 共n-1行，分别是从起点城市v到其他n-1个城市最少换乘次数，
// 按照终点城市序号从小到大顺序输出，不能抵达时输出-1。
// 样例输入
// 3 2 0
// 0 1
// 1 2
// 样例输出
// 1
// 2

#include<iostream>
using namespace std;
int choice(int *d,int *visit,int n);
int main(int argc,char *argv[])
{   
	int n,m,v,s,e,min;
	cin>>n>>m>>v;
	int **a=new int*[n];
	int *visit=new int[n];
	int *d=new int[n];    //只要是数组都可以用指针表示
	for(int i=0;i<n;i++)
	{
		a[i]=new int[n];        //这个地方老是犯错，是n不是i！！！！
		visit[i]=0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i!=j)
				a[i][j]=65535;
			else
				a[i][j]=0;
		}
	for(int i=0;i<m;i++)
	{   
		cin>>s>>e;
		a[s][e]=1;
	}
	for(int i=0;i<n;i++)
		d[i]=a[v][i];
    visit[v]=1;
	for(int i=1;i<n;i++)
	{
      min=choice(d,visit,n);
	  visit[min]=1;
	  for(int j=0;j<n;j++)
	  {
		  if(visit[j]==0&&d[min]+a[min][j]<a[v][j])
			  d[j]=d[min]+a[min][j];
	  }
	}
	for(int i=0;i<n;i++)
	{
		if(i!=v&&d[i]<65535)
			cout<<d[i]<<endl;
		else if(i==v)
			  continue;
		else
			cout<<"-1"<<endl;
	}
	for(int i=0;i<n;i++)
		delete []a[i];
	delete []d;
	delete []visit;
	return 0;
}
int choice(int *d,int *visit,int n)
{
	int min=65536,pos;
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0&&d[i]<min)
		{
			min=d[i];
			pos=i;
		}
	}
	return pos;
}
