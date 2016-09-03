
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// void getlength(int s, vector<int>& nums, int left, int right, int &length);
// int minSubArrayLen(int s, vector<int>& nums) {
//     int n = nums.size();
//     int length = n;
//     int sum = accumulate(nums.begin(), nums.end(), 0);
//     if(nums.empty() || sum < s) return 0;
//     int left = 0;
//     int right = n - 1;
//     getlength(s, nums, left, right, length);
//     return length;
// }
// void getlength(int s, vector<int>& nums, int left, int right, int &length){
//     if(left >= right) return;
//     int sum = 0;
//     for(int i = left; i <= right; ++i){
//         sum += nums[i];
//     }
//     if(sum >= s) length = min(length, right - left + 1);
//     int mid = left + (right - left) >> 1;
//     getlength(s, nums, left, mid, length);
//     getlength(s, nums, mid + 1, right, length);
// }

// int main(){
//     vector<int> nums = {2,3,1,2,4,3};
//     int leng = minSubArrayLen(7, nums);
//     cout << leng;
// }

//TLE Time Limit Exceeded O(n3) 蛮力法
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int length = n;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(nums.empty() || sum < s) return 0;
        int left = 0;
        for(int left = 0;left < n - 1; ++left){
            for(int right = left + 1; right < n; ++right){
                int sum = 0;
                for(int i = left; i <= right; ++i) sum += nums[i];
                if(sum >= s){
                    length = min(length, right - left + 1);
                    break;
                }
            }
        }
        return length;
    }
};

//O(n)  8ms
int minSubArrayLen(int s, vector<int>& nums) {
    int firstPos = 0, sum = 0, minLength = INT_MAX;
    for(int i = 0; i<nums.size(); i++) {
        sum += nums[i];
        while(sum >= s) {
            minLength = min(minLength, i - firstPos + 1);
            sum -= nums[firstPos++];
        }
    }
    return minLength == INT_MAX? 0 : minLength;
}
