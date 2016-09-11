// Given a collection of numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(ans, nums, 0);
        return ans;
    }
    void permute(vector<vector<int>> &ans, vector<int>& nums, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            swap(nums[index], nums[i]);
            permute(ans, nums, index + 1 );
            swap(nums[index], nums[i]);
        }
    }
};