// 题目描述：请设计一个算法完成两个超长正整数的加法。 
// 要求实现函数：
//   void AddLongInteger(char * pcAddend, char * pcAugend, char * pcAddResult);
// 输入参数：
//         char * pcAddend：加数
//         char * pcAugend：被加数
//         char * pcAddResult：加法结果
// 返回值：无

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

void AddLongInteger(string pcAddend, string pcAugend, string &pcAddResult){
	int carry = 0;
	int addsize = pcAddend.size();
	int augsize = pcAugend.size();
	for(int i = 0; i < addsize; ++i){
		if(!isdigit(pcAddend[i]))
			return;
	}
	for(int i = 0; i < augsize; ++i){
		if(!isdigit(pcAugend[i]))
			return;
	}
	if(addsize == 0 && augsize != 0){
		pcAddResult = pcAugend;
		return;
	}
	if(addsize != 0 && augsize == 0){
		pcAddResult = pcAddend;
		return;
	}
	reverse(pcAddend.begin(),pcAddend.end());
	reverse(pcAugend.begin(),pcAugend.end());
	int tsize = addsize;
	if(addsize > augsize){
		for(int i = 0; i < addsize - augsize; ++i)
			pcAugend.push_back('0');
	}
	else if(addsize < augsize){
		for(int i = 0; i < augsize - addsize; ++i)
			pcAddend.push_back('0');
		tsize = augsize;	
	}
	for(int i = 0; i < tsize; ++i){
		int temp = (pcAddend[i] - '0') + (pcAugend[i] - '0') + carry;
		carry = temp / 10;
		int num = temp % 10;
		pcAddResult.push_back(num + '0');
	}
	if(carry)
		pcAddResult.push_back(carry + '0');	
	else{
		int i = pcAddResult.size() - 1;
		for(; i >= 0; --i){
			if(pcAddResult[i] != '0')
				break;
		}
		pcAddResult.erase(i+1, pcAddResult.size()-i);
	}
	reverse(pcAddResult.begin(), pcAddResult.end());
}

int main(){
	string pcAddend, pcAugend, pcAddResult;
	cin >> pcAddend;
	cin >> pcAugend;
	AddLongInteger(pcAddend, pcAugend, pcAddResult);
	cout << pcAddResult;
	return 0;
}
