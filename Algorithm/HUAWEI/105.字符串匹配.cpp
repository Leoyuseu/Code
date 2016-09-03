// 描述：字符串匹配问题，给定两个字符串，求字符串2，在字符串1中的最先匹配结果。字符串2中可以存在'*'符号，且该符号可以代表任意字符，即字符串2中存在通配符。
// e.g. 输入：abcdefghabef, a*f
// 输出：abcdef
#include<iostream>
#include<string>
using namespace std;
int main(int argc,char *argv[])
{
    string str,str1,str2,re;
	int m=0,s,e,flag=1,i1;
	getline(cin,str);
	for(int i=0;i<str.size();i++)
	{
		if(str[i]==',')
		{
			str1=str2;
			str2.erase();
		}
		else
			str2.push_back(str[i]);
	}
	if(str2=="*")
	{
		cout<<str1<<endl;
		return 0;
	}
	for(int i=0;i<str1.size();i++)
	{   
		flag=1;
       if(str1[i]==str2[m])        //写入匹配成功字母串，遇*或者结尾结束
	   {
		   s=m;
		   i1=i;
		   while(str2[s]!='*'&&s<str2.size()&&i1<str1.size())    
		   {
			   if(str1[i1++]!=str2[s++])
			   {
				   flag=0;
				   break;
			   }
		   }
           if(flag==1)
		   {
			   e=s;
			   i=i1-1;                 //i要移到成功的最后一个字母
		   }
		   re.append(str1,i,e-m);  
		   m=s;
	   }
	   else if(str2[m]=='*')       //遇*一直到遇到str2下一个字母或者输到尾
	   {
		   for(int j=i;j<str1.size()&&(((m!=str2.size()-1)&&str1[j]!=str2[m+1])||m==str2.size()-1);j++)
		   {
			   re.push_back(str1[j]);
			   e=j;
		   }
		   i=e;               //i要移到与str2下个字母匹配的str1字符的前一个
		   m++;
	   }
	   else
		   m++;
	   if(m==str2.size())
		   break;               //第一次匹配成功就跳出
     
	}
	cout<<re<<endl;
	return 0;
}

