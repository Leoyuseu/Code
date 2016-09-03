#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

string countAndSay(int n) {
	string result;
	string nstr;
	map<int, string> num{ { 1, "one" }, { 2, "two" }, { 3, "three" }, 
							 { 4, "four" }, { 5, "five" },{ 6, "six" },
							 { 7, "seven" }, { 8, "eight" }, { 9, "nine" }, { 0, "zero" } };
	while (n != 0){
		nstr.push_back(n % 10 + '0');
		n /= 10;
	}
	//reverse(nstr.begin(), nstr.end());
	int count = 1;
	for (auto it1 = nstr.rbegin(); it1!=nstr.rend(); ++it1){
		for (auto it2 = it1 + 1; it2!=nstr.rend(); ++it2){
			if (*it2 == *it1){
				++count;
				++it1;
			}
			else
				break;
		}
		string s = num[count] + " " + *it1 + (count>1 ? "s" : "")+" ";
		result.append(s);
		s.clear();
		count = 1;
	}
	return result;
}

int main(){
	int n;
	cin >> n;
	string s = countAndSay(n);
	cout << s;
}