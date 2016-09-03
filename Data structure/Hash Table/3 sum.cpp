// Given an array S of n integers, are there elements a, b, c in S 
// such that a + b + c = 0? Find all unique triplets in the array
// which gives the sum of zero.

// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},
// 不适合使用hash_table，当出现元素重复时用哈希表就不是很方便了。
//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i){
            int second=i+1;
            int third=nums.size()-1;
            while(second<third){
                int sum=nums[i]+nums[second]+nums[third];
                if(sum > 0) --third;
                else if(sum < 0) ++second;
                else {
                    vector<int> temp={nums[i],nums[second],nums[third]};
                    result.push_back(temp);
                    while (second<third && nums[second] == temp[1]) second++;
                    while (second<third && nums[third] == temp[2]) third--;
                }
                
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;
            while (front < back) {
                int sum = num[front] + num[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {	
                    vector<int> triplet={num[i],num[front],num[back]};
                    res.push_back(triplet);
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;
        }
        return res;
    }
};

// ************************threeSumClosest********************************

// Sort the vector and then no need to run O(N^3) algorithm 
// as each index has a direction to move.

// The code starts from this formation.

// ----------------------------------------------------
// ^  ^                                               ^
// |  |                                               |
// |  +- second                                     third
// +-first
// if nums[first] + nums[second] + nums[third] is smaller than the target, 
// we know we have to increase the sum. so only choice is moving the second index forward.

// ----------------------------------------------------
// ^    ^                                             ^
// |    |                                             |
// |    +- second                                   third
// +-first
// if the sum is bigger than the target, we know that we need to reduce the sum. 
// o only choice is moving 'third' to backward. of course if the sum equals to 
// target, we can immediately return the sum.

// ----------------------------------------------------
// ^    ^                                          ^
// |    |                                          |
// |    +- second                                third
// +-first
// when second and third cross, the round is done so start next round by 
// moving 'first' and resetting second and third.

// ----------------------------------------------------
//   ^    ^                                           ^
//   |    |                                           |
//   |    +- second                                 third
//   +-first
// while doing this, collect the closest sum of each stage by calculating and 
// comparing delta. Compare abs(target-newSum) and abs(target-closest). 
// At the end of the process the three indexes will eventually be gathered 
// at the end of the array.

// ----------------------------------------------------
//                                          ^    ^    ^
//                                          |    |    `- third
//                                          |    +- second
//                                          +-first
// if no exactly matching sum has been found so far, the value in closest
// will be the answer.

int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return 0;
    int closest = nums[0]+nums[1]+nums[2];
    sort(nums.begin(), nums.end());
    for(int first = 0 ; first < nums.size()-2 ; ++first) {
        if(first > 0 && nums[first] == nums[first-1]) continue;
        int second = first+1;
        int third = nums.size()-1;            
        while(second < third) {
            int curSum = nums[first]+nums[second]+nums[third];
            if(curSum == target) return curSum;
            if(abs(target-curSum)<abs(target-closest)) {
                closest = curSum;
            }
            if(curSum > target) {
                --third;
            } else {
                ++second;
            }
        }
    }
    return closest;
}