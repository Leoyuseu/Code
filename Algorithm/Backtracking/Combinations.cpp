
//******************Combinations**********************
// Given two integers n and k, return all possible combinations of k numbers 
// out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

//use Subsets 60 ms--!
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
        return res;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<1) return res;
        vector<int> nums;
        for(int i = 1; i <= n; ++i){
            nums.push_back(i);
        }
        if(n < k) return res;
        else if(n == k){
            res.push_back(nums);
            return res;
        }
        res = subsets(nums);
        auto it = partition(res.begin(),res.end(),[&k](vector<int> &v){return v.size() == k;});
        res.erase(it,res.end());
        return res;
    }
};


// 8ms recursive backtracking
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> ret;
       if(n==0||k==0)return ret;
       vector<int> stack;
       combine(n, k,stack,ret, 1);
       return ret;
    }
private:
    void combine(int n, int k,vector<int> &stack,vector<vector<int>> &ret,int start) {
        if(0==k) {
            ret.push_back(stack);
            return;
        }
        for(int i=start;i<=n-k+1;i++){
            stack.push_back(i);
            combine(n, k-1,stack,ret, i+1);
            stack.pop_back();
        }
    }
};


//C(n,k) = C(n-1, k-1) + C(n-1,k)  16 ms
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (n < 1 || k <1 || k > n){
            return result;
        }
        result = combine(n-1, k-1);
        if(result.empty()){
            result.push_back(vector<int>{n});
        }
        else{
            for (vector<vector<int> >::iterator it = result.begin();it!= result.end(); it++){
                it->push_back(n);
            }
        }
        vector<vector<int> > result2 = combine(n-1, k);
        result. insert(result.end(), result2.begin(), result2.end());
        return result;
    }
};