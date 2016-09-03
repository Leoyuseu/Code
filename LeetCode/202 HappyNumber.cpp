#include<iostream>
#include<math.h>
#include<set>
using namespace std; 
	
bool isHappy(int n) {
    int max=0
    while(max!=1){
        max=0;
        while(n!=0){
            max+=pow(n%10,2);
            n/=10;
        }
        n=max;
        cout<<max<<" ";
        if(max==4)  
            return false;
    }
    return true;
}
    
int main(){
	//int n=7;
	for(int i=1;i<1000;i++) {
		cout<<isHappy(i);
		cout<<endl;
	}
	return 0;
}