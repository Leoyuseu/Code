#include<string>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

//recursive solution
int evalRPN(vector<string> &n) {
    string s = n.back(); 
    n.pop_back();
    if ( s== "*" || s=="/" || s=="+" || s == "-" ){
        int r2 = evalRPN(n);
        int r1 = evalRPN(n);
        if ( s=="*") return r1*r2;
        if ( s=="/") return r1/r2;
        if ( s=="+") return r1+r2;
        if ( s=="-") return r1-r2;
    }
    else
        return stoi(s);
}

//USE A STACK
//int evalue(int lhs,char op,int rhs){
//    switch (op) {
//        case '+':
//            return lhs+rhs;
//        case '-':
//            return lhs-rhs;
//        case '*':
//            return lhs*rhs;
//        case '/':
//            return lhs/rhs;
//    }
//}
//int evalRPN(vector<string>& tokens) {
//    stack<int> stk;
//    for(auto it=tokens.begin();it!=tokens.end();++it){
//        if(*it=="+"||*it=="-"||*it=="*"||*it=="/"){
//            int rhs=stk.top();
//            stk.pop();
//            int lhs=stk.top();
//            stk.pop();
//            char op=(*it)[0];
//            int res=evalue(lhs,op,rhs);
//            stk.push(res);
//        }
//        else{
//            stk.push(stoi(*it));
//        }
//    }
//    return stk.top();
//}

int main(){
	vector<string> tokens{"2", "1", "+", "3", "*"};
	int result=evalRPN(tokens);
	cout<<result;
	
}
