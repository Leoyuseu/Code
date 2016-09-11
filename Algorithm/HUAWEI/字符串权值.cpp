// 字符串权值
// 输入两个字符串（都是字母） a到z每个字母有一个权值（-26）不区分大小
// 写哪个字母分配哪个权值由你决定 字符串的权值就是字符串中所有字母的权值之和。    
// 现要求自行分配权值使得两个字符串的权值之差最大 输出最大权值之差
// （提示：先把字符串中的相同字母去掉，再分配权值） 
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a,int b)           //升序排列
{
	return a>b;
}
int chazhi(string &s1,string &s2,const vector<int> &v1,const vector<int> &v2)
{
	int m1=s1.size();
	int m2=s2.size();
	int n1=0,n2=0;
	for(int i=0;i<m1;i++)
	{
		n1+=(26-i)*v1[i];
		n2+=(i+1)*v2[i];
	}
	return n1-n2;
}
int main(int argc,char *argv[])
{
    string str1,str2,s1,s2,t1,t2;
	cin>>str1>>str2;
	t1=str1;
	t2=str2;
	int m;
    vector<int> visit1(26,0);
	vector<int> visit2(26,0);
	for(int i=0;i<str1.size();i++)      //去掉1，2中相同的字母，注意等数去除
	{
		m=t2.find(str1[i]);          //假如1中有个a，2中有2个a，那么1中需保留一个a
		if(m<0)
		{   
			if(isupper(str1[i]))
				visit1[str1[i]-65]++;
			else
				visit1[str1[i]-97]++;
			s1.push_back(str1[i]);
		}
		else
			t2.erase(m,1);
	}
	for(int i=0;i<str2.size();i++)
	{
		m=t1.find(str2[i]);
		if(m<0)
		{
			 
			if(isupper(str2[i]))
				visit2[str2[i]-65]++;
			else
				visit2[str2[i]-97]++;
			s2.push_back(str2[i]);
		}
		else
			t1.erase(m,1);
	}
	sort(visit1.begin(),visit1.end(),cmp);
	sort(visit2.begin(),visit2.end(),cmp);
	int a=chazhi(s1,s2,visit1,visit2);
	int b=chazhi(s2,s1,visit2,visit1);
	int c=a>=b?a:b;
	cout<<c<<endl;
	return 0;
}
