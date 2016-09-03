//Longest Substring Without Repeating Characters

//±©Á¦ÆÆ½â168ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=0;
        string substr;
        int n=s.size();
        if(s.empty())
            return 0;
        int max=1;
        for(int i=0;i<n;++i){
            substr.push_back(s[i]);
            for(int j=i+1;j<n;++j){
                auto found=substr.find(s[j]);
                if(found==string::npos){
                    substr.push_back(s[j]);
                    ++max;
                }
                else{
                    size=max>size?max:size;
                    substr.clear();
                    max=1;
                    break;
                }
            }
        }
        size=max>size?max:size;
        return size;
    }
};

//12ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0,cur=0;
        string str;
        for(int i=0;i<s.size();++i)
        {
            int pos=str.find(s[i]);
            if(pos!=string::npos)
                {
                    length=max(length,(int)str.size());
                    str.erase(str.begin(),str.begin()+pos+1);
                }
            str.push_back(s[i]);    
        }
        return max(length,(int)str.size());
    }
};