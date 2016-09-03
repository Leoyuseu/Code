// 给定一个数，比如20
// 然后再给定几个数字 1 3 5 7 8
// 1  3  5  7  8
// 0  0  1  1  1 
// 因为5+7+8=20

#include<iostream>
#include<string>
using namespace std;
int find(int m,int num[],bool l[],int n)
{
	if(m==0)
		return 1;
	if((m>0&&n<0)||m<0)
		return 0;
	if(find(m-num[n],num,l,n-1))
	{
		l[n]=true;
		return 1;                   //这步需要返回1
	}
	else
		return find(m,num,l,n-1);
}
int main()
{  
	int num[100],m,n=-1;
	cin>>m;
	while(cin>>num[++n]);
	bool *l=new bool[n];
	for(int i=0;i<n;i++)
		l[i]=false;
	if(find(m,num,l,n-1))
	{
		for(int i=0;i<n;i++)
			cout<<l[i]<<" ";
		cout<<endl;
	}
	else
		cout<<"NO"<<endl;
    delete []l;
	return 0;	
}
