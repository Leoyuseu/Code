// Given a set of distinct integers, nums, return all possible subsets.

// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:

// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        res.push_back({nums[0]});
        res.push_back({});
        for(int i=1; i < nums.size(); ++i){
            int curlen = pow(2, i);
            for(int j = 0; j < curlen; ++j){
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                sort(temp.begin(),temp.end());
                res.push_back(temp);
            }
        }
        // sort(res.begin(),res.end());   //去重
        // res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};

//backtracking
class Solution {
public:
    void subsets(vector<vector<int> >& out, const vector<int>& nums,vector<int>& picked_subset,int i)
    {
        if (i==nums.size())
        {
            out.push_back(picked_subset);
            return;
        }
        subsets(out,nums,picked_subset,i+1);
        picked_subset.push_back(nums[i]);
        subsets(out,nums,picked_subset,i+1);
        picked_subset.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > out;
        vector<int> picked_subset;
        subsets(out,nums,picked_subset,0);
        return out;
    }
};