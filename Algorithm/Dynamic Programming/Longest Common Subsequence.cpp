#include <string>
#include <iostream>
using namespace std;

int main(){
	string str1 = "educational";//"ABCBDAB";// "educational";
	string str2 = "advantage";//"BDCABA"; //"advantage";
	string lcs = "";
	int m = str1.size();
	int n = str2.size();
	int arr[50][50] = {{0,0}};  //arr[0][0] = 0  //不可以用arr[m][n],除非动态数组 
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			if(str1[i-1] == str2[j-1]){
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else{
				if(arr[i][j-1] > arr[i-1][j]) arr[i][j] = arr[i][j - 1];  //大的
				else arr[i][j] = arr[i-1][j];
			}
		}
	}
	
	for(int i = 0; i <= m; ++i){
		for(int j = 0; j <= n; ++j){
			cout<< arr[i][j] << " ";
		}
		cout<<endl;
	}
	
	for(int i = m, j = n; i >= 1 && j >= 1;){
		if(str1[i-1] == str2[j-1]){
			lcs = str1[i-1] + lcs;
			--i, --j;
		}
		else{
			//if(arr[i][j-1] >= arr[i-1][j])的区别,结果是dana，没有等号结果是data 
			if(arr[i][j-1] > arr[i-1][j]) --j;     
			else --i;
		}
	} 
	cout<<lcs;
	return 0;
}
