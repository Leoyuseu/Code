#include <iostream>
using namespace std;

int func(int x){
    int count=0;
    while (x)
    {
        count++;
        x=x&(x-1);//与运算
    }
    return count;
}

int main() {
	int i;
	cin >> i;
	cout << func(i);
}