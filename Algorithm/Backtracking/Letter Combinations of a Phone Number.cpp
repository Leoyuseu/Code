#include<vector>
#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	void combine(vector<string> query, int i, string str, vector<string> &result){
		if (i == query.size()){
			result.push_back(str);
			str.clear();
			return;
		}
		string s = query[i];
		for (int j = 0; j<s.size(); ++j)
			combine(query, i + 1, str + s[j], result);
	}

	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.empty())
			return result;
		map<int, string> mp = { { 1, "" }, { 2, "abc" }, { 3, "def" }, { 4, "ghi" }, { 5, "jkl" },
		{ 6, "mno" }, { 7, "pqrs" }, { 8, "tuv" }, { 9, "wxyz" }, { 0, " " } };
		vector<string> query;
		for (auto i = 0; i<digits.size(); ++i)
			query.push_back(mp[digits[i] - '0']);
		string str;
		combine(query, 0, str, result);
		return result;
	}

 //****************hashing******************
 	vector<string> letterCombinations(string digits) {
        if (digits == "") return vector<string>{};
        unordered_map<char, string> hash{{'2', "abc"}, {'3', "def"}, 
                                        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
                                        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res[2];
        res[0].push_back("");
        bool last = 0;
        for (auto x : digits) {
            res[!last].clear();
            string str = hash[x];
            for (auto c : str) {
                for (auto x : res[last]) {
                    res[!last].push_back( x + c);
                }
            }
            last = !last;
        }
        return res[last];
    }
};

//DFS backtracking
vector<string> letterCombinations(string digits) {
    vector<string> str;//str for final resut
    string save;//save for temporary answer
    int convert[10] = {0, 3, 6, 9, 12, 15, 19, 22, 26};
    dfs(str, save, digits, 0, digits.size(), convert);
    return str;
}
void dfs(vector<string> &str, string save, string dig, 
    	 int now, int size, int *convert){
    if(now == size){
        str.push_back(save);
        return;
    }
    int tmp = dig[now] - '0' - 2;//change '2' to 0, '3' to 1...
    for(int i = convert[tmp]; i < convert[tmp+1]; i++){
        save.push_back('a' + i);//ex: a,b,c | d,e,f
        dfs(str, save, dig, now + 1, size, convert);
        save.pop_back();
	}
}



int mian(){
	string digitnum;
	cin >> digitnum;
	Solution st;
	auto str=st.letterCombinations(digitnum);
	for (auto sr : str){
		cout << sr << endl;
	}
	return 0;
}