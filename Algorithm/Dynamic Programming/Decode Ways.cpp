// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        if(s[0]=='0') return 0;
        int waysnum=1;
        for(int i=1;i<s.size();++i){
            if( ((s[i-1])=='1'&& ((1<=s[i]-'0')&&(9>=s[i]-'0'))) || (( (s[i-1])=='2') && ((1<=s[i]-'0')&&(6>=s[i]-'0')))){
                ++waysnum;
                cout<<"1wayschange"<<waysnum<<endl; 
            }
            if(s[i]=='0'&&(((s[i-1]-'0')>2)||s[i-1]=='0')) return 0;
            if(i>1){
                if((s[i]=='0')&&(1<=(s[i-1]-'0')&&(s[i-1]-'0')<=2)&&(1<=(s[i-2]-'0')&&(s[i-2]-'0')<=2))
                    --waysnum;
                    cout<<"2wayschange"<<waysnum<<endl; 
            }
        }
        return waysnum;
    }
};


//****************DP solution**************
int numDecodings(string s) {
    if (!s.size() || s.front() == '0') return 0;
    // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
    int r1 = 1, r2 = 1;
    for (int i = 1; i < s.size(); i++) {
        // zero voids ways of the last because zero cannot be used separately
        if (s[i] == '0') r1 = 0;
        // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
            r1 = r2 + r1;
            r2 = r1 - r2;
        }
        // one-digit letter, no new way added
        else {
            r2 = r1;
        }
    }
    return r1;
}

int main(){
    Solution st;
    string s="121";
    cout<<st.numDecodings(s);
}
