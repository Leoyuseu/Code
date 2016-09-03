#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int num;
	int output = 0;
	cin >> num;
	string snum;
	while(num){
		snum.push_back(num % 10 + '0');
		num /= 10;
	}
	for(size_t i = 0; i < snum.size() - 1; ++i){
		// for(size_t j = i + 1; j < snum.size(); ++j){
		// 	string str = snum.substr(i, j - i);
		// 	size_t pos = snum.find(str);
		// 	if(pos != i && pos != snum.size()){
		// 		output = 1;
		// 		cout << output;
		// 		return 0;
		// 	}
		// }
		string str = snum.substr(i, 2);
		size_t pos = snum.find(str);
		if(pos != i && pos != snum.size()){
			output = 1;
			cout << output;
			return 0;
		}
	}
	cout << output;
	return 0;
}
