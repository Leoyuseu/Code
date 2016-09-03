//hanoitower

#include <iostream>

using namespace std;

//DP
int hanoitower(int n) {
	if(n == 1) return 1;
	int hanoi = 1;
	while(n-- > 1){
		hanoi = 2 * hanoi + 1;
	}
	return hanoi;
}


int main() {
	int n;
	cin >> n;
	cout << hanoitower(n);
}
