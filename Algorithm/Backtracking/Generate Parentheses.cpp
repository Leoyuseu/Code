// Given n pairs of parentheses, write a function to generate all 
// combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// "((()))", "(()())", "(())()", "()(())", "()()()"

#include <vector>
#include <string>
#include <stack>
//#include <utility> //swap
#include <iostream>
#include <algorithm> //find
using namespace std;

//concise solution 0ms
class Solution {
public:
   vector<string> result;

   void helper(string str, int left, int right){
       if(left == 0 && right == 0)  result.push_back(str);
       if(left!=0)                  helper(str+'(', left-1, right);
       if(right!=0 && right > left) helper(str+')', left, right-1);
   }    

   vector<string> generateParenthesis(int n) {
       helper("",n,n);
       return result;
   }
};
////when n >= 5 time limit exceeded <TLE>
//class Solution {
//public:
//    vector<string> generateParenthesis(int n) {
//        vector<string> ans;
//        if(n < 1) return ans;
//        string s(n, '(');
//        s += string(n, ')');
//        generate(n, ans, s, 0);
//        return ans;
//    }
//    
//private:
//    void generate(int n, vector<string> &ans, string &s, int index){
//        if(index >= 2*n){
//            if(isValid(s)){
//            	if(find(ans.begin(), ans.end(), s) == ans.end())
//	                ans.push_back(s);
//	            return;
//            }
//            else return;
//        }
//        //backtracking 思路来自于 permutations序列，TLE 
//        for(int i = index; i < 2*n; ++i){
//            swap(s[index], s[i]);
//            generate(n, ans, s, index + 1);
//            swap(s[index], s[i]);
//        }
//    }
//    
//    bool isValid(string s){
//        stack<char> stk;
//        stk.push(s[0]);
//        for(int i = 1; i < s.size(); ++i){
//            if(s[i] == '(') stk.push(s[i]);
//            else{
//                if(!stk.empty() && stk.top() == '(') {  //!stk.empty() 缺少程序出错
//                	stk.pop();
//				}
//                else stk.push(s[i]);
//            }
//        }
//        return stk.empty() ? true : false;
//    }
//};

int main(){
	int n = 6;
	Solution st;
	vector<string> svec = st.generateParenthesis(n);
	for(auto s : svec){
		cout << s <<endl;
	}		
	cout<<svec.size(); 
	return 0;
}
