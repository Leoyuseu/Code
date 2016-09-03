// 将中文数字的拼音字符串转为最终的数字；每个字拼音的首字母大写，比如：JiuWanJiuQianJiuBaiJiuShiJiu表示九万九千九百九十九，即阿拉伯数字，。
// 你当然记得每个数字的汉语拼音，但是还是提示你一下，Ling、Yi、Er、San、Si、Wu、Liu、Qi、Ba、Jiu、Shi、Bai、Qian、Wan。
// 为简单起见，我们要处理的数字在万以内，不含负数，十、百、千、万等单位前面一定有数字，如YiShi表示。
// 输入: 中文数字的拼音字符串 
// 输出: 阿拉伯数字 
// 样例输入: SanBaiLingSan
// 样例输出: 303

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cctype>
using namespace std;

int main(){
	map<string, int> chinum = { { "Ling", 0 }, { "Yi", 1 }, { "Er", 2 }, { "San", 3 },
	{ "Si", 4 }, { "Wu", 5 }, { "Liu", 6 }, { "Qi", 7 }, { "Ba", 8 }, {"Jiu",9},
	{ "Shi", 10 }, { "Bai", 100 }, { "Qian", 1000 }, {"Wan",10000} };
	string pingying;
	vector<string> oneping;
	string value;
	
	int num = 0;
	cout << "输入拼音：";
	getline(cin,pingying);
	int length = pingying.size();
	
	int flag = 1;
	while (flag){
		value.push_back(pingying[0]);
		for (int i = 1; i < length; ++i){
			if (islower(pingying[i])){
				value.push_back(pingying[i]);
			}
			else{
				oneping.push_back(value);
				value.clear();
				value.push_back(pingying[i]);
			}
		}
		flag = 0;
		oneping.push_back(value);
	}
	int nums = oneping.size();
	for (vector<string>::iterator iter = oneping.begin(); iter < oneping.end()-1; ++iter){
		//cout << *iter << endl;        //打印oneping向量验证转换准确性
		if (chinum[*(iter + 1)]>9)//加上这句保证算法准确，如2052,3003等
num += (chinum[*iter]*chinum[*++iter]);
	}
	num += chinum[*(oneping.end()-1)];
	cout <<"译为数字："<< num << endl;
	return 0;
}
