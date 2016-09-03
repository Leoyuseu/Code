#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// OJ没过
// string multiply(string num1, string num2) {
//    string sum(num1.size() + num2.size(), '0');

//    for (int i = num1.size() - 1; 0 <= i; --i) {
//        int carry = 0;
//        for (int j = num2.size() - 1; 0 <= j; --j) {
//            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
//            sum[i + j + 1] = tmp % 10 + '0';
//            carry = tmp / 10;
//        }
//        sum[i] += carry;
//    }

//    size_t startpos = sum.find_first_not_of("0");
//    if (string::npos != startpos) {
//        return sum.substr(startpos);
//    }
//    return "0";
// }
		
string multiply(string num1, string num2) {
    string res;
    vector<string> pows;
    int carry=0;
    string str;
    int n1=num1.size();
    int n2=num2.size();
    reverse(num1.begin(),num1.end());       //不需要用reverse,直接循环范围从size-1->0！！ 
    reverse(num2.begin(),num2.end());
    for(int i=0;i<n1;++i){
        str.append(i,'0');
        for(int j=0;j<n2||carry!=0;++j){
            if(j==n2){
                str.push_back(carry+'0');
                carry=0;
            }
            else{
            	int r=(num1[i]-'0')*(num2[j]-'0')+carry;
            	carry=r/10;
            	str.push_back(r%10+'0');
			}
        }
        pows.push_back(str);
        str.clear();
    }
    int n3=pows.size();
    int maxlength;
    int r=0;
    for(int i=0;i<n3;++i)
        maxlength=pows[i].size()>maxlength?pows[i].size():maxlength;
    for(int i=0;i<maxlength;++i){
        for(int j=0;j<n3;++j)
            r+=pows[j].size()>i?(pows[j][i]-'0'):0;
        r+=carry;
        res.push_back(r%10+'0');
        carry=r/10;
        r=0;
    }
    reverse(res.begin(),res.end());
    size_t startpos = res.find_first_not_of('0');
    if (string::npos != startpos) {
        return res.substr(startpos);
    }
    return "0";
}

int main(){
	string n1,n2;
	while(cin>>n1>>n2){
		string result=multiply(n1,n2);
		cout<<result<<endl;
	}
	return 0;
}
