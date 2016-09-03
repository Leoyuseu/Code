#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        string curWord = beginWord;
        int count = 1;
        if(wordDict.empty()) return 0;
        if(wordDict.find(beginWord) != wordDict.end()){
            wordDict.erase(beginWord);
        }
        while(!wordDict.empty()){
            bool found = false;
            for(string word : wordDict){
                if(word.size() == curWord.size()){
                    int dif = 0;
                    for(int i = 0; i < word.size(); ++i){
                        if(word[i] != curWord[i]) ++dif;
                    }
                    if(dif == 1){
                        ++count;
                        if(word ==endWord) return count;
                        else{
                            curWord = word;
                            cout << curWord <<endl;
                            wordDict.erase(word);
                            
                            for(auto word:wordDict){
                            	cout<<word<<"  ";
							}
							cout << endl;
							
                            found = true;
                            break;
                        }
                    }
                }
            }
            if(!found) return 0;
        }
        return 0;
    }
};

int main() {
	string beginWord = "hot";
	string endWord = "dog";
	unordered_set<string> wordDict = {"hot","dog","cog","dot"};
	Solution st;
	int res = st.ladderLength(beginWord, endWord, wordDict);
	cout << res;
}


