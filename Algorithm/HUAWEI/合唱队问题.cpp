// 计算最少多少人出列后，其他人能排成合唱队，T1<T2<T3<T4>T5>T4>...TK.不能swap，顺序不变输出最少出列人数
#include<iostream>
#include<vector>
using namespace std;
int main(int argc,char *argv[])            //动态规划题，从少到多最优解
{
    int n,len,max=0;
	cin>>n;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++)
		cin>>h[i];
	vector<int> l(n+1);
	vector<int> r(n+1);
	for(int i=1;i<=n;i++)            //从左到右
	{
		l[i]=1;
		for(int j=1;j<i;j++)            
		{
            if(h[j]<h[i]&&l[i]<l[j]+1)
				l[i]=l[j]+1;
		}
	}
	for(int i=n;i>=1;i--)        //从右到左
	{
		r[i]=1;
		for(int j=n;j>n-i;j--)
		{
			if(h[j]<h[i]&&r[i]<r[j]+1)
				r[i]=r[j]+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		len=l[i]+r[i]-1;
		if(len>max)
			max=len;
	}
	int min=n-max;
	cout<<min<<endl;
	return 0;
}
