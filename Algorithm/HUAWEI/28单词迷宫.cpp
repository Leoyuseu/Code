// 题目简介： 
// Word Maze 是一个网络小游戏，你需要找到以字母标注的食物，但要求以给定
// 单词字母的顺序吃掉。如上图，假设给定单词if，你必须先吃掉i然后才能吃掉f。 
// 但现在你的任务可没有这么简单，你现在处于一个mí宫Maze（n×m的矩阵）当中，
// 里面到处都是以字母标注的食物，但你只能吃掉能连成给定单词W的食物。 
// 如下图，指定W为“SOLO”，则在地图中红色标注了单词“SOLO”。 
// 注意区分英文字母大小写,你只能上下左右行走。
// 运行时间限制:  无限制
// 内存限制:  无限制
// 输入:
// 输入第一行包含两个整数n、m(0<n, m<21)分别表示n行m列的矩阵，第二行长度
// 不超过100的单词W，从第3行到底n+3行是只包含大小写英文字母的长度为m的字符串。
// 输出:
// 如果能在地图中连成给定的单词，则输出“YES”，否则输出“NO”。
// 注意：每个字只能用一次。
// 样例输入:
// 5 5
// SOLO
// CPUCY
// EKLQH
// CRSOL
// EKLQO
// PGRBC
// 样例输出:yes 
/*题目解答： 
其实没想象中的那么复杂，就是要考虑的边边角角问题多了些。 
主要思路： 
1、创建一个字符串数组用于存放n*m的字母； 
2、创建一个整型（或bool型）数组，用于标记相应位置处的元素是否被访问过； 
3、找到第一个字母（如S）后，进入查找下一个字母（如O）的程序，找到之后，在递归进入查找下一个字母的程序，以此类推。若递归到需要查找的单词进入结尾时（如需要查找的为SOLO，查找顺序为S —> O —–> L ——>O——->’\0′），遇到’\0‘，则证明该单词被找到； 
需要chǔ理的边界问题： 
为了说明需要注意的细节，我们可以把输入的测试数据改为： 
5 5 
SQOC 
CPUCY 
EKLQH 
CRSOL 
EKSQO 
PGRBC 
主要差别在于，有两个S，当按照顺序查找S —-> Q ——> O ——> C，从Q查找O时，Q的上方和右方都是O。 
这道题里面需要考虑的编编脚脚问题主要有： 
1、越界问题。如当一个元素位于最右下角，那么只能去检查它的上方和左方，而不能检查它的右方和下方，etc. 
2、每个元素只能访问一次的问题。用数组标记是否被访问过即可解决。 
4、查找S时，有两个S，从第一个S找未成功后，能接着查找是否存在别的S，然后能找到索要查找单词的可能性； 
3、当一个方向失败之后，还能接下去尝试其他方案。这就涉及到上下左右四个判断语句不能用if esle if else if….之类的结构，而是if   if  if   if； */

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
void search(char **p,bool **visit,const string &w,int pos,int n,int m,int s,int e);
int main(){  
	//freopen("mi.txt","r",stdin);
	int n,m,pos=0;
	cin>>n>>m;
	string w;
	cin>>w;
	char **p=new char*[n];
	bool **visit=new bool*[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new char[m];
        visit[i]=new bool[m];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>p[i][j];
			visit[i][j]=false;
		}
	for(int i=0;i<n;i++)                 //寻找首字母（考虑有多个符合）
	{
		for(int j=0;j<m;j++)
		{
			if(p[i][j]==w[pos])
			{
				visit[i][j]=true;
				search(p,visit,w,pos+1,n,m,i,j);	
			}
		}
		
	}
	
    cout<<"NO"<<endl;
	for(int i=0;i<n;i++)
	{
		delete []p[i];
		delete []visit[i];
	}
	return 0;	
}

void search(char **p,bool **visit,const string &w,int pos,int n,int m,int s,int e)
{
	
	if(pos==w.size())              //终止条件不能为x==尾字母，因为单词中字母可能重复
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			delete []p[i];
			delete []visit[i];
		}
		exit(0);
	}                                                        //四个方向寻找
	
	if(s-1>=0&&visit[s-1][e]==false&&p[s-1][e]==w[pos])
	{
		visit[s-1][e]=true;
		search(p,visit,w,pos+1,n,m,s-1,e);
	}
	if(e-1>=0&&visit[s][e-1]==false&&p[s][e-1]==w[pos])
	{
		visit[s][e-1]=true;
		search(p,visit,w,pos+1,n,m,s,e-1);
	}
	if(s+1<n&&visit[s+1][e]==false&&p[s+1][e]==w[pos])
	{
		visit[s+1][e]=true;
		search(p,visit,w,pos+1,n,m,s+1,e);
	}
	if(e+1<m&&visit[s][e+1]==false&&p[s][e+1]==w[pos])
	{
		visit[s][e+1]=true;
		search(p,visit,w,pos+1,n,m,s,e+1);
	}
	else
		return ;
}
