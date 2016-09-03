// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
// for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify 
// repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that 
// occur more than once in a DNA molecule.

// For example,

// Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

class Solution {
public:
    vector<strin
// Return:
// ["AAAAACCCCC", "CCCCCAAAAA"].

#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm> 
using namespace std;
g> findRepeatedDnaSequences(string s) {
        //Memory Limit Exceeded
        vector<string> result;
        if(s.size()<=10) return result;
        unordered_set<string> sset;
        for(int i=0;i<s.size()-10;++i){
            string temp=s.substr(i,10);
            if(sset.find(temp)!=sset.end()){
                result.push_back(temp);
            }
            sset.insert(temp);
        }
        for(auto s:sset){
        	cout<<s<<endl;
		}
		cout<<"result:";
        return result;

        //Time Limit Exceeded
        vector<string> result;
        if(s.size()<=10) return result;
        vector<string> sset;
        for(int i=0;i<s.size()-10;++i){
            string temp=s.substr(i,10);
            if(find(sset.begin(),sset.end(),temp)!=sset.end()){
                result.push_back(temp);
            }
            else sset.push_back(temp);
        }
        return result;

    // 事实证明，还是可以用哈希表，直接建立一个string的哈希表太大了！
    // 因为string的每一位都只有四种可能，用一个int位来代替一个10位的string，
    // ACGT分别代表两位00 01 10 11，即
    // 用一个20位的int值表示10位的string
    // 再用hash来建立int的表进行查找～即可
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int i,foo_i;
        string foo,bar;
        unordered_set<int> A;
        int size=s.length();
        if(size<=10)
            return res;
        for(i=0;i+10<=size;i++){
            foo=s.substr(i,10);
            foo_i=str2num(foo);
            if(A.find(foo_i)==A.end()){
                A.insert(foo_i);
            }
            else{
                if(find(res.begin(),res.end(),foo)==res.end())
                res.push_back(foo);
            }
        }
        return res; 
    }
    int str2num(string A){
        int i,res=0;
        for(i=0;i<10;i++){
            if(A[i]=='A')
                res+=0;
            else if(A[i]=='C')
                res+=1;
            else if(A[i]=='T')
                res+=2;
            else if(A[i]=='G')
                res+=3;
            res=res<<2;
        }
        return res;
    }

};

//看不懂
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        char  hashMap[1048576] = {0};
        vector<string> ans;
        int len = s.size(),hashNum = 0;
        if (len < 11) return ans;
        for (int i = 0;i < 9;++i)
            hashNum = hashNum << 2 | (s[i] - 'A' + 1) % 5;
        for (int i = 9;i < len;++i)
            if (hashMap[hashNum = (hashNum << 2 | (s[i] - 'A' + 1) % 5) & 0xfffff]++ == 1)
                ans.push_back(s.substr(i-9,10));
        return ans;
    }
};

int main(){
	string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution st;
	vector<string> result=st.findRepeatedDnaSequences(s);
	for(auto s:result)
		cout<<s<<endl;
}
