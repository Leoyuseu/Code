// Given an array of integers, find if the array contains any duplicates. 
// Your function should return true if any value appears at least twice in the array, 
// and it should return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {      
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size(); 
    }
};


// Given an array of integers and an integer k, find out whether there 
// there are two distinct indices i and j in the array such that nums[i] = nums[j] 
// and the difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        auto it=unique(temp.begin(),temp.end());
        if(it==temp.end())
            return false;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()&&m[nums[i]]>=i-k)
                return true;
            m[nums[i]]=i;
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()||k<1)
            return false;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        auto it=unique(temp.begin(),temp.end());
        if(it==temp.end())
            return false;
        for(auto it1=nums.begin();it1!=nums.end()-1;++it1){
            auto it2=find(it1+1,nums.end(),*it1);
            if(it2!=nums.end()){
                if(it2-it1<=k){
                    return true;
                }
            }
        }
        return false;
    }
};