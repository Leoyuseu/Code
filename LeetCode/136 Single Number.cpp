//136 Single Number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(auto num:nums)
            result^=num;
        return result;
    }
};

int singleNumber(vector<int> &nums) {
  int result;
  if(nums.size()==1)  return nums[0];
  int count=0;
  count=accumulate(nums.begin(),nums.end(),0);
  sort(nums.begin(),nums.end());
  auto it=unique(nums.begin(),nums.end());
  nums.erase(it,nums.end());
  int count1=0;
  count1=2*accumulate(nums.begin(),nums.end(),0);
  result=count1-count;
  cout<<count<<" "<<count1<<endl;
  return result;
}

// Single Number II 
// Given an array of integers, every element appears three times 
// except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity. 
// Could you implement it without using extra memory?

class Solution {
public:
    int singleNumber(vector<int> nums) {
        int tempNum = 0;
        for (int i = 1; i < nums.size(); i++) {
            tempNum = nums[0] & (tempNum ^ nums[i]);
            nums[0] = tempNum | (nums[0] ^ nums[i]);
        }
        return nums[0];
    }
};


// Single Number III
// Given an array of numbers nums, in which exactly two elements 
// appear only once and all the other elements appear exactly twice. 
// Find the two elements that appear only once.
// For example:
// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
// Note:
// The order of the result is not important. So in the above example, 
// [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. 
// Could you implement it using only constant space complexity?

//28ms  O(n)  空间O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if(nums.size() < 2) return res;
        else if(nums.size() == 2) return nums;
        unordered_map<int, int> count;
        for(auto num:nums){
            ++count[num];
        }
        for(auto it = count.begin(); it != count.end(); ++it){
            if(it->second == 1){
                res.push_back(it->first);
                if(res.size() == 2){
                    return res;
                }
            }
        }
        return res;
    }
};

// O(n)  O(1)
class Solution{
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums){
            if ((num & diff) == 0) {// the bit is not set
                rets[0] ^= num;
            }
            else {// the bit is set      
                rets[1] ^= num;
            }
        }
        return rets;
    }
};

//688ms!!!  O(n2)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        if(nums.size() < 2) return res;
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            bool uni = false;
            for(int j = 0; j < size; ++j){
                if(i != j && nums[i] == nums[j]){
                    uni = true;
                    break;
                }
            }
            if(!uni){
                res.push_back(nums[i]);
                if(res.size() == 2) return res;
            }
        }
    }
};