// N个城市（N<=10）,从0到9编号，城市间要么有路，要么没路，
// 计算城市A到B之间到底有多少条路。
// 输入：N A B（1<N<=10,0<=A,B<=9）A为出发城市，B为目的城市。
// 然后n行表示行编号的城市到其他城市有没有路，0表示没有，1表示有路。
// 输出：A到B有多少条路
// 输入：3 0 2
//       1 1 1
//       1 1 1
//       1 1 1
// 输出：2
/*方法一：邻接矩阵法*/
#include<iostream>
#include<string>
using namespace std;
int main()
{ 
    int n,a,b;
	cin>>n>>a>>b;
	int **r=new int*[n];
	int *visit=new int[n];
	int *que=new int[n];
	for(int i=0;i<n;i++)
	{
		r[i]=new int[n];
		visit[i]=0;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>r[i][j];
	int top=-1,tail=-1,s,num=0;
	que[++tail]=a;
	visit[a]=1;
	while(top!=tail)
	{
        int s=que[++top];           //出列一个
			for(int i=0;i<n;i++)
			{
				if(r[s][i]==1&&visit[i]==0&&i!=b)     //连通性&&访问过没
				{
				    que[++tail]=i;
				    visit[i]=1;
				}
				else if(r[s][i]==1&&i==b)      //到达b时，不需要对b进行操作，直接判断队列中下一个
				    num++;              //到达一次路线加1
			}
	}
	cout<<num<<endl;
	delete []que;
    delete []visit;
	for(int i=0;i<n;i++)
		delete []r[i];
	return 0;
}


//*方法二：转化为邻接表法*（自找麻烦，放在这只为说明如何用数组模拟邻接表）
#include<iostream> 
using namespace std;
int main()
{  
	int n,a,b;
	cin>>n>>a>>b;
	int **map=new int*[n];
	for(int i=0;i<n;i++)
		map[i]=new int[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];
	bool visit[10]={false};
	for(int i=0;i<n;i++)              //转换为类似邻接单链表的矩阵
	{
		int index=0;
		for(int j=0;j<n;j++)
		{
			if(map[i][j]&&i!=j)
				map[i][index++]=j;
		}
		map[i][index]=-1;
	}
	int *quene=new int[n];
	int top=0,count=0;
	quene[top]=a;
	int tail=top+1;
	visit[a]=true;
	while(top!=tail)                        //广度搜索
	{
		int begin=quene[top];
		for(int i=0;map[begin][i]!=-1;i++)
		{
			if(map[begin][i]!=b&&visit[map[begin][i]]==false)    //待搜索的进队列
			{
				quene[tail++]=map[begin][i];
			    visit[i]=true;                            //已访问的城市标记为已读，使路不重复走
			}
			else if(map[begin][i]==b)                            //到达目的点，条数加1
				count++;
		}
		top++;                                                //搜索完成的出队列
	}
	cout<<count<<endl;
	delete []quene;
	for(int i=0;i<n;i++)
		delete []map[i];
	return 0;	
}




#include <vector>  
#include <string>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
  
int cityCount = 0;  
int citySrc = 0;  
int cityDst = 0;  
  
vector<vector<int> > PathVec;  
  
int GetCountOfPath(int citySrc, int cityDst, vector<int> exceptCity ){  
	exceptCity.push_back(cityDst);  
	int result = 0;  
	//查找cityDst周边的  
	for (int i = 0 ; i< cityCount ; i++){  
		if (i == citySrc){  
		result += PathVec[i][cityDst];  
		}  
		else if(i != cityDst && 1 == PathVec[i][cityDst] && exceptCity.end() == find(exceptCity.begin() , exceptCity.end() , i))  
		{  
		result += GetCountOfPath(citySrc , i , exceptCity);  
 	}  
	return result;  
}  
  
  
  
//字符串转vec  
  
vector<int> stringToVec(const string& str)  
{  
	vector<int> InputVec;  
	char *p;  
	p = strtok(const_cast<char*>(str.c_str())," ");  
	while(p)  
	{  
		if (' ' == *p)  
		{  
		p=strtok(NULL," ");  
		continue;  
		}  
		InputVec.push_back(atoi(p));  
		p=strtok(NULL," ");  
	}  
	return InputVec;  
}  
void main()  
{  
	  
	//输入第一行 “N A B”(1 < N <= 10; 0 <= A,B <= 9; A != B)，N表示有多少个城市，A标识从编号为A的城市出发，B标识目的城市  
	string strInput;  
	strInput.length();  
	getline(cin , strInput);  
	  
	vector<int> InputVec = stringToVec(strInput);  
	  
	  
	cityCount = InputVec[0];  
	citySrc = InputVec[1];  
	cityDst = InputVec[2];  
	  
	//输入路径是否连接  
	for (int j = 0 ; j < cityCount ; j++)  
	{  
		string temp;  
		getline(cin , temp);  
		PathVec.push_back(stringToVec(temp));  
	}  
	vector<int> exceptCity;  
	int result = GetCountOfPath(citySrc , cityDst , exceptCity);  
	cout << result <<endl;  
}  