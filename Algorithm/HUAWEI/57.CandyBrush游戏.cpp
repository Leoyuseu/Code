// 描述: CandyBrush一款流行的消除游戏，在一个方阵中布满各种糖果，
// 任意交换两个糖果，如果交换后出现横向或者竖向有连续三个相同的情况，
// 则可以消除糖果并得分。
// 输入个字符组成的字符串（编号为到），表示×的方阵，每个字符表示不同
// 类型的糖果（区分大小写），判断是否有解，即交换某两个糖果后能够消除糖果。
// 举例，下面的方阵无解
// T M T M O
// X R U C q
// A B C X R
// U R M T O
// T Q C R A
// 下面的方阵交换(0, 2)和(1, 2)两个糖果后，能消除M
// T M T M O
// X R M C q
// A B C X R
// U R M T O
// T Q C R A
// 如果有解，则输出YES，同时输出所有交换方案中，被交换糖果最小编号，
// 比如：上面的方阵中，被交换的糖果，编号最小的为糖果“T”，编号为。
// 如果无解，则输出NO。
// 运行时间限制: 无限制
// 内存限制: 无限制
// 输入: 
// 输入个字符组成的字符串，不含空格，表示×的方阵
// 输出: 
// 如果有解，则输出YES，同时输出所有交换方案中，被交换糖果最小编号，
// 以空格隔开。如果无解，则输出NO。
 
// 样例输入: 
// TMTMOXRMCqABCXRURMTOTQCRA
// 样例输出: 
// YES 3
// 答案提示:  
// 输出最小糖果编号的意思，就是从左至右，从上到下遍历糖果，
// 找到第一个跟其他交换后能消除的糖果即可。

#include<iostream>
#include<string>
using namespace std;
char a[5][5];
void swap(int i,int j,int i1,int j1)
{
	char t;
	t=a[i][j];
	a[i][j]=a[i1][j1];
	a[i1][j1]=t;
}
int xiaochu()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2])
				return 1;
		}
	for(int i=0;i<5;i++)
		for(int j=0;j<3;j++)
		{
			if(a[j][i]==a[j+1][i]&&a[j][i]==a[j+2][i])
				return 1;
		}
	return 0;
}
int main()
{  
	string str;
	cin>>str;
	int n=0,flag,min;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			a[i][j]=str[n++];
	for(int i=0;i<5;i++)            //从左到右，从上到下，第一个满足的编号最小，直接终止程序
		for(int j=0;j<5;j++)
		{
			if(j+1<5)
			{
				swap(i,j,i,j+1);
				flag=xiaochu();
				if(flag==1)
				{
					min=i*5+j+1;
                    cout<<"YES"<<" "<<min<<endl;
					return 0;
				}
				swap(i,j,i,j+1);                //不符合时要交换回来，进行下次比较
			}
			if(i+1<5)
			{
				swap(i,j,i+1,j);
				flag=xiaochu();
				if(flag==1)
				{
					min=i*5+j+1;
                    cout<<"YES"<<" "<<min<<endl;
					return 0;
				}
				swap(i,j,i+1,j);
			}

		}
	cout<<"NO"<<endl;
	return 0;	
}
