#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std; 

class Solution {
public:
    map<int, string> numwords = {{1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"},
        {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, 
        {17, "Seventeen"}, {18, "Eighteen"},{19, "Nineteen"} 
    };
    map<int, string> twowords = {{2, "Twenty"}, {3, "Thirty"} , {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"},
        {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} 
    };
    
    string hundNum(int num){
        string hunds("");
        
        if(num == 0){
            return hunds;
        }
        
        if(num / 100){
            hunds = hunds + numwords[num / 100 ]+ " " + "Hundred ";
        }
        num = num - (num / 100) * 100;
        if(num == 0){
            return hunds;
        }
        else if(num < 20){
            hunds = hunds + numwords[num]+ " ";
            return hunds;
        }
        else{
            hunds = hunds + twowords[num / 10]+ " ";
            if(num % 10){
                hunds = hunds +numwords[num % 10]+ " ";
            }
            return hunds;
        }
    }
    
    string numberToWords(int num) {
        string res = "";
        vector<int> inums;
        if(num == 0) return "Zero";

        //重点环节，拆分数字
        string nums = to_string(num);
        for(int i = nums.size() - 1; i >= 0; ){
            if(i-2 >= 0){
                inums.push_back(stoi(nums.substr(i-2, 3)));
            }
            else inums.push_back(stoi(nums.substr(0, i + 1)));
            i = i-3;
        }
        
		for(int i = 0; i < inums.size(); ++i){
            string temp = hundNum(inums[i]);
            if(!temp.empty()){
            	switch (i){
                case 0 :
                    break;
                case 1 :
                    temp += "Thousand ";
                    break;
                case 2:
                    temp += "Million ";
                    break;
                case 3:
                    temp += "Billion ";
                    break;
            	}
			}
            res = temp + res;
        }
        res.erase(res.end() - 1);
        return res;
    }
};

int main(){
	int num = 100010001;
	Solution st;
	string s = st.numberToWords(num);
	cout<<s;
}


class Solution {
public:
    string hundredStr(int num){
        vector<string> arr1={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> arr2={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string ret;
        ret=num%100<20?arr1[num%100]:arr2[(num%100)/10]+(num%10?" "+arr1[num%10]:"");
        if(num>99)ret=arr1[num/100]+" Hundred"+(num%100?" "+ret:"");
        return ret;
    }
    string numberToWords(int num) {
        string ret;
        vector<string> strarr={"Thousand","Million","Billion"};
        ret=hundredStr(num%1000);
        for(int i=0;i<3;i++){
            num/=1000;
            ret=num%1000?hundredStr(num%1000)+" "+strarr[i]+" "+ ret:ret;
        }
        while(ret.back()==' ')ret.pop_back();
        return ret.empty()?"Zero":ret;
    }
};