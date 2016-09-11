// 渡口问题：
//   同类车辆先来先上，客车优于货车，客车上了4辆后才可以上货车，客车不足4辆可用货车补充。
//   客车为0，货车为1
//   输入：5  00101 输出：01324

#include<iostream>
#include<string>
using namespace std;
int main(int argc,char *argv[])
{   
	int n,bus_num=0,tru_num=0;
	cin>>n;
	int *in=new int[n];
	int *out=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
		if(0==in[i])
			bus_num++;
	}
	tru_num=n-bus_num;
	if(0==bus_num||0==tru_num)            //只有一种车的情况
	{
		for(int i=0;i<n;i++)            //后面的常规算法已考虑特殊情况了，为了逻辑清楚才另写的
			out[i]=i;
	}
	else if(bus_num<=4)                    //客车小于等于4辆时情况
	{   
		int m1=0;
		for(int i=0;m1<bus_num;i++)
		{
			if(0==in[i])
				out[m1++]=i;		  
		}
	    for(int i=0;i<n;i++)
		{
			if(1==in[i])
				out[m1++]=i;
		}

	}
	else
	{
		int m2=0,b=bus_num,pos1=-1,pos2=-1,i1,i2,flag=0;
		while(m2<n)
		{  
		   flag=0;
		   i1=pos1;                           //老犯这种错误，pos1变了，循环里坐标就变了
		   i2=pos2;
           for(int i=i1+1;i<n;i++)
		   {
			   if(4==flag||b==0)
				   break;
			   if(0==in[i])
			   {
				   out[m2++]=i;
				   pos1=i;
				   flag++;
				   b--;
			   }
		   }
		   for(int i=i2+1;i<n;i++)                 //起始点是大于上次的终止点
		   {
			   if(0==in[i]&&i>pos1)
				   break;
                if(1==in[i])
				{
					out[m2++]=i;
					pos2=i;
				}
		   }
		}

	}
	for(int i=0;i<n;i++)
		cout<<out[i]<<" ";
	cout<<endl;
	delete []in;
	delete []out;
	return 0;
}
