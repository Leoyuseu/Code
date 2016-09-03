#include<iostream> 
#include<algorithm>
#include<vector>
using namespace std;

//一行解决 
//return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size(); 

//bool containsDuplicate(vector<int>& nums) {
//	return unique(nums.begin(),nums.end())!=nums.end();
//		if(nums.size()<2)
//            return false;
//        for(auto it=nums.begin();it!=nums.end();++it){
//            auto found=find(nums.begin(),nums.end(),*it);
//            if(found!=nums.end()){
//                return true;
//            }
//        }
//        return false;	
//    }

int main(){
	vector<int> nums={1,2,3,1};
	cout<<(unique(nums.begin(),nums.end())!=nums.end())<<endl;
	for(auto i:nums)
		cout<<i<<" "; 
	return 0;
}   
