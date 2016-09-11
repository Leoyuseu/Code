// Given a set of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

//my wrong answer
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        deque<int> comb;
        if(candidates.empty()) return ans;
        candidates.erase(partition(candidates.begin(),candidates.end(),
                        [&target](int i){return i <= target;}),candidates.end());
        sort(candidates.begin(),candidates.end());
        combsum(candidates, target, ans, comb, 0);
        return ans;
    }
    void combsum(vector<int>& candidates, int target, vector<vector<int>>& ans,  
                 deque<int>& comb, int index){
        if(sunofcomb(comb) == target){
            vector<int> temp(comb.begin(), comb.end());
            ans.push_back(temp);
            return;
        }
        else if(sunofcomb(comb) > target){
            comb.pop_front();
            if(sunofcomb(comb) < target){
                comb.push_back(candidates[index]);
                combsum(candidates, target, ans, comb, index);
            }
            else
                ++index;
        }
    }
    int sunofcomb(deque<int> comb){
        int sum = 0;
        for(int num : comb){
            sum += num;
        }
        return sum;
    }
};




//Accepted 16ms c++ solution use backtracking for Combination Sum:
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, 
                        vector<std::vector<int> > &res, vector<int> &combination,
                        int begin) {
        if  (!target) {   //边界条件，很重要
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && 
                 target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);  //入栈
            // 遍历
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back(); //出栈
        }
    }
};

//Accepted 12ms c++ solution use backtracking for Combination Sum II:
class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
};

//Accepted 0ms c++ solution use backtracking for Combination Sum III:
class Solution {
public:
    std::vector<std::vector<int> > combinationSum3(int k, int n) {
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum3(n, res, combination, 1, k);
        return res;
    }
private:
    void combinationSum3(int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin, int need) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        else if (!need)
            return;
        for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i) {
            combination.push_back(i);
            combinationSum3(target - i, res, combination, i + 1, need - 1);
            combination.pop_back();
        }
    }
};