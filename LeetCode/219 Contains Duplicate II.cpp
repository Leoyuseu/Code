#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	vector<int> nums={1,1,3,1,1,3,2,1,4};
	//sort(nums.begin(),nums.end());
	auto it=unique(nums.begin(),nums.end());
	nums.resize(distance(nums.begin(),it));
	cout<<nums.size()<<endl;
	for(auto i:nums){
		cout<<i<<" ";
	}
	cout<<it-nums.begin();
	return 0;
} 
