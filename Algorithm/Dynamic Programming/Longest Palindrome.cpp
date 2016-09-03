//Longest Palindrome

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string &s){
	int left = 0, right = s.size() - 1;
	while (left < right) {
		if (s[left++] != s[right--]) return false;
	}
	return true;
}

//暴力枚举法 O(N^3)
string findLongestPalindrome1(string &s) {
	int size = s.size();
	int maxLength = 0;
	int start = 0;
	for (int i = 0; i < size - 1; ++i){
		for(int j = i + 1; j < size; ++j){
			string sub = s.substr(i, j - i + 1);
			if (isPalindrome(sub)) {
				if (sub.size() > maxLength){
					maxLength = sub.size();
					start = i;
				}
			}
		}
	}
	if (maxLength > 2) return s.substr(start, maxLength);
	else return NULL;
}

//动态规划 额外空间：O(N^2) 时间复杂度:O(N^2)
//P[i,j]=0表示子串[i,j]不是回文串
//if(s[i] == s[j]) p[i,j] = p[i+1,j-1];
string findLongestPalindrome2(string &s) {
	int size = s.size();
	int maxLength = 0;
	int start = 0;
	bool P[50][50]={false};
	//初始条件，p[n][n] = true, 判断p[n][n+1]
	for(int i = 0; i < size; i++){
        P[i][i] = true;  
        if(i < size - 1 && s[i] == s[i + 1]) {  
            P[i][i+1] = true;  
            start = i;  
            maxLength = 2;  
        }  
	}  
	for(int len=3; len < size; len++) {
		for(int i=0;i<=size-len;i++){  
	        int j=i+len-1;
	        if(P[i+1][j-1] && s[i] == s[j]) {  
                P[i][j]=true;                  
                maxLength=len;  
                start=i;  
           }  
        }  
    }
    if (maxLength > 2) return s.substr(start, maxLength);
	else return NULL;
}

//中心拓展  O(N^2)
string findLongestPalindrome3(string &s) {
	int size = s.size();
	int maxLength = 0;
	int start = 0;
	//最大长度为奇数
	for (int i = 0; i < size; ++i) {
		int j = i - 1, k = i + 1; 
		while(j >= 0 && k < size && s[j] == s[k]){
			if (k - j + 1 >maxLength){
				maxLength = k - j + 1;
				start = j;
				cout << "jisubp: " << s.substr(j,maxLength) << endl;
			}
			--j, ++k;
		}
	}
	//最大长度为偶数
	for(int i = 0; i < size; ++i) {
		int j = i, k = i + 1;
		while(j >= 0 && k < size && s[j] == s[k]){
			if (k - j + 1 >maxLength){
				maxLength = k - j + 1;
				start = j;
				cout << "ousubp: " << s.substr(j,maxLength) << endl;
			}
			--j, ++k;
		}
	}
	if (maxLength > 2) return s.substr(start, maxLength);
	else return NULL;
}

//

int main(){
	string s = "abacddca";
	string ans = findLongestPalindrome2(s);
	cout << "Ans: " << ans << endl;
}
