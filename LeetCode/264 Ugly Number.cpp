// Ugly Number

// class Solution {
// public:
//     bool isUgly(int num) {
//         if(num <= 0) return false;
//         while(num % 2 == 0) num /= 2;
//         while(num % 3 == 0) num /= 3;
//         while(num % 5 == 0) num /= 5;
//         return num == 1 ? true : false;
//     }
// };

// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 
// 10 ugly numbers.

// Note that 1 is typically treated as an ugly number.
#include <iostream>
#include <vector>
#include <cstdlib> 
using namespace std;

class Solution {
public:
    int threeMin(int a, int b, int c){
        return min(a, min(b,c));
    }
    int nthUglyNumber(int n) {
        vector<int> ugly(n,0);
        ugly[0] = 1;
        int i1=0, i2=0, i3=0;
        for(int i=1;i<n;++i){
        	cout<<ugly[i1]<<" "<<ugly[i2]<<" "<<ugly[i3]<<endl;
            int next = threeMin(ugly[i1]*2, ugly[i2]*3, ugly[i3]*5);
            ugly[i] = next;
            while(ugly[i1]*2 <= next) ++i1;
            while(ugly[i2]*3 <= next) ++i2;
            while(ugly[i3]*5 <= next) ++i3;
        }
        return ugly[n-1];
    }
};

int main(){
	Solution st;
	int n = 10;
	cout<<st.nthUglyNumber(n);
}
