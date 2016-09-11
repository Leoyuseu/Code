//注意机试代码也加注释

#include <iostream>

using namespace std;

int main(){
	int n;
	int output = 1;
	cin >> n;
	int pre = 1;
	int curr = 2;
	while(curr <= n){
		if(curr == n){
			output = 2;
		}
		curr += pre;
		pre = curr - pre;
	}
	cout << output;
	return 0; 
}
