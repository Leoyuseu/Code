//KMP

//有一个文本串S，和一个模式串P，现在要查找P在S中的位置
#include <iostream>
#include <string>
#include<vector> 
using namespace std;

//**************暴力匹配算法 最坏O(s.size()*p.size());******************
int ViolentMatch(string &s, string &p) {
	if (s.size() < p.size()) return -1;
//	第一种
//	for (int i = 0; i < s.size(); ++i){
//		int j = 0;
//		while(j < p.size()){
//			if (s[i] != p[j]) {
//				i = i - j + 1;
//				break;
//			}
//			else {
//				++i, ++j;
//			}
//		}
//		if(j == p.size()) {
//			return i - j;
//		} 
//	}
//同第一种，循环优化
	int i = 0, j = 0;
	while (i < s.size() && j < p.size()) {
		if(s[i] == p[j]){
			++i;
			++j;
			cout << "i:" <<i<<"  "<< "j:"<<j<<endl;
		}
		else{
			i = i - j + 1;   //不匹配则使i回溯到原来的i的下一个
			j = 0;			 //模式串复位
		}
	}
	if(j == p.size())  return i - j;

//第二种，consice
// 	int i = 0;
// 	for(; i < s.size() - p.size() + 1; ++i){
// 		int j = 0; 
// 		for(; j < p.size(); ++j){
// 			if(s[i+j] != p[j]) break;
// 		}
// 		if(j == p.size()) {
// 			return i;
// 			break;
// 		}
// 	}

	return -1;
}

//***************************KMP*************************************
void getNext(string &p, vector<int> &next) {
	next[0] = -1;
	int k = -1, j =0;
	while(j < p.size() - 1){
		if (-1 == k || p[j] == p[k]) {  
            ++k;  
            ++j;        
			if (p[j] != p[k])  
	            next[j] = k;  
            else    
				next[j] = next[k];  
	    }  
	    else k = next[k];
	}
}
int KmpMatch(string &s, string &p, const vector<int> &next) {
	int i = 0, j = 0;
	while (i < s.size() && j < p.size()) {
		if(-1 == j || s[i] == p[j]){
			++i, ++j;
			cout << "i:" <<i<<"  "<< "j:"<<j<<endl;	
		}
		else {
			j = next[j];
		}
	}
	if(j = p.size()) return i - j;
	else return -1;
}


int main() {
	string s = "i am a waiti string waiting for searching";
	string p = "waiting";
	vector<int> next(p.size(), 0);
	getNext(p, next);
	for(auto n:next){
		cout<<n<<" ";
	}
	cout<<endl;
	//cout << "BF found at: " << ViolentMatch(s, p) <<endl;
	cout << "KMP found at: " << KmpMatch(s, p, next) <<endl;
}
