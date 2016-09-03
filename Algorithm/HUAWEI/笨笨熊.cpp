// 森林里的苯苯熊要乔迁新喜，上次他已经将物品打包完成，并约了朋友来帮忙。接下来他要选定一个搬家的时间，想了很久，就决定在国庆节进行，因为国庆放假朋友们都有时间啦。但是在森林里，从他现在房子到新豪宅，所经之地有山有水，路途曲折，甚至有些道路是不通的。
//     请你和他一起查看指定的地图，看看从笨笨熊现在的房子到新宅之间，道路是否是畅通的呢？
//     地图是R行、C列的矩阵，矩阵的每一个格子刚好是一天的行程。  
//     矩阵由“B”、“-”、“#”、“H”四种字符成员组成，其中：
//     B：代表苯苯熊现在的房子；
//     H：代表笨笨熊新的豪宅；
//     -：代表可以通行的道路；
//     #：代表无法通过的障碍(高山、大河等)；
//     此外，森林里也有交通规则地：在任务位置，只能向“上、下、左、右”四个方向中的其中一个方向行走。
// 输入: 4  // R的数值
// 4  // C的数值，下面是地图。
// --##---
// B-----H
// #---#--
// -------
// 输出: Y //代表道路可达或N //代表道路不通
// 样例输入: 1-row    5-column      -B-H# 
// 样例输出: Y 
#include<iostream>
#include<string>
using namespace std;
static int r,c;
int tra(string *p,int **visit,int a,int b)
{
	visit[a][b]=1;
	if(p[a][b]=='#')
		return 0;
	if(p[a][b]=='H')
		return 1;
	if(a-1>=0&&visit[a-1][b]==0&&tra(p,visit,a-1,b)==1)             //递归
		return 1;
	if(a+1<r&&visit[a+1][b]==0&&tra(p,visit,a+1,b)==1)
		return 1;
	if(b-1>=0&&visit[a][b-1]==0&&tra(p,visit,a,b-1)==1)
		return 1;
	if(b+1<c&&visit[a][b+1]==0&&tra(p,visit,a,b+1)==1)
		return 1;
	return 0;
}

int main(int argc,char *argv[])
{
	cin>>r>>c;
	string *p=new string[r];
	int **visit=new int*[r];              //指针的指针   int[r]指向r个元素int数组的第一个元素
	for(int i=0;i<r;i++)
	{
		cin>>p[i];
		visit[i]=new int[c];
	}
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			visit[i][j]=0;
	int flag=0,m;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(p[i][j]=='B')
			{
				m=tra(p,visit,i,j);
				flag=1;
				break;
			}
		}
		if(1==flag)
			break;
	}
	if(m==1)
		cout<<"Y"<<endl;
	else
		cout<<"N"<<endl;
	delete []p;
	for(int i=0;i<r;i++)
		delete []visit[i];     //释放分配在系统堆中的内存，不会随着程序结束而自动释放。 
	return 0;
}