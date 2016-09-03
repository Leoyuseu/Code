// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// click to show corner cases.

// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

#include<string>
#include<algorithm>
#include<stack>
#include<vector> 
#include<iostream>
#include<sstream>
using namespace std;

//leetcode
class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')) {
        	cout<<tmp<<endl;
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};


//my solution 
string simplifyPath(string path) {
    string result;
    if(path.empty()) return result;
    stack<char> stk;
    for(int i=0;i<path.size();++i){
        if(path[i]=='/') {
            if(!stk.empty() && stk.top()=='/') continue;
            else stk.push('/');
        }
        else if(path[i]=='.') {
            while(!stk.empty()) stk.pop();
        }
        else{
            stk.push(path[i]);
        }    
    }
    if(result.empty()) return "/";
    if(stk.size()>1 && stk.top()=='/') stk.pop();
    while(!stk.empty()){
        result.push_back(stk.top());
        stk.pop();
    }
    if(!result.empty()) reverse(result.begin(),result.end());
    return result;
}

int main(){
	string s="/a/./b/..//c/";
	Solution st;
	string result=st.simplifyPath(s);
	cout<<result;
}
