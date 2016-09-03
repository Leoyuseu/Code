#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<sstream>
using namespace std;

void reverseWords(string &s) {
    if(s.empty()) return;
    if(s.size()==1){ 
        if(s[0]==' ') {
            s.clear();
            return;
        }
        return;   
    }
    vector<string> words;
    string word;
    for(int i=0;i<s.size();++i){
        if(isspace(s[i])){
            if(!word.empty()){
                words.push_back(word);
                word.clear();
            }
        }
        else{
            word.push_back(s[i]);
        }
        if(i==s.size()-1&&(!word.empty())){
            words.push_back(word);
        }
    }
    s.clear();
    if(words.empty()) return;
    for(vector<string>::iterator it=words.begin();it!=words.end();++it){
        s=*it+" "+s;
    }
    //s=s+words[0];
    return;
}

// istringstream   8ms in place 空间复杂度是1
void reverseWords(string &s) {
   istringstream is(s);
   string tmp;
   //is >> s;
   s.clear();
   while(is >> tmp) s = tmp + " " + s;
   if(s[0] == ' ') s = "";
}

// STL 12ms  有所提升 
void reverseWords(string &s) {
   //
   vector<string> data;
   string word;
   stringstream ss(s);
   while(ss>>word) data.push_back(word);

   vector<string> rdata(data.rbegin(), data.rend());

   s = accumulate(rdata.begin(), rdata.end(), string(""),
       [](string s1, string s2){              //lamada表达式 
           if(s1.empty()) return s2;
           else return s1+" "+s2;     
       });
}

void reverseWords(string &s) {
   int len;
   {
       int cnt=0;
       int i=0;
       bool tell=false;
       while (s[cnt]!='\0'){
           if (s[cnt]==' '){
               if (tell) s[i++]=s[cnt],tell=false;
           }else s[i++]=s[cnt],tell=true;
           cnt++;
       }
       if (i!=0&&s[i-1]==' ') i--;
       len=i;
       if (cnt-i>0)s.erase(i,cnt-i);
   }
   int st=0;
   for (int i=0;i<=len;i++){
       if (i==len||s[i]==' '){
           int ed=i-1;
           while (ed-st>=1){
               swap(s[ed--],s[st++]);
           }
           st=i+1;
       }
   }
   int ed=len-1;st=0;
   while (ed-st>=1){
       swap(s[ed--],s[st++]);
   }
}


int main(){
	string s;
	getline(cin,s);
	reverseWords(s);
	if(!s.empty())
		cout<<s<<endl;
	cin>>s;
	int i=stoi(s);
	cout<<i<<endl;
	cout<<s.size();
}
