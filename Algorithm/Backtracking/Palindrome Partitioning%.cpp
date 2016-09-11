// Given a string s, partition s such that every substring of 
// the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]


class Solution {
public:
    void palPart (vector<vector<string>> &ans,vector<string> &temp,string s,int j){
        if(s.size()==0)
            return;
        if(j>s.size()-1){    //边界条件，很重要
            ans.push_back(temp);
            return;
        }
        int m,n,l;
        for(m=s.size()-1;m>=j;m--){
            l=j;
            n=m;
            while(l<n&&s[l]==s[n]){
                l++;
                n--;
            }//判断s(j,m)是不是回文
            if(l>=n){  //发现回文
                temp.push_back(s.substr(j,m-j+1));//子串入栈
                palPart(ans,temp,s,m+1);//遍历
                temp.pop_back();//遍历完毕，子串出栈
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromes;
        vector<string> temp;
        palPart(palindromes, temp, s, 0);
        return palindromes;
    }
};


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;

        vector<string> path;
        dfs(0, s, path, ret);

        return ret;
    }

    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};