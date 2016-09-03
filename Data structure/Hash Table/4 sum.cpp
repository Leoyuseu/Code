

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//accept in 168ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> solu;
        if(nums.size()<4) return result; 
        sort(nums.begin(),nums.end());
        for(int first=0;(first+2)<nums.size()-1;++first){
            for(int last=nums.size()-1;last>(first+2);--last){
                int run1=first+1;
                int run2=last-1;
                while(run1<run2){
                    if(nums[first]+nums[run1]+nums[run2]+nums[last]==target){
                        solu={nums[first],nums[run1],nums[run2],nums[last]};
                        result.push_back(solu);
                        ++run1;
                        --run2;
                    }
                    else if(nums[first]+nums[run1]+nums[run2]+nums[last]<target) {
                        ++run1;
                    }
                    else {
                        --run2;
                    }
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};

//AC in 68ms
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.size()<4) return res;
        std::sort(num.begin(),num.end());
        for (int i = 0; i < num.size()-3; i++) {
            int target_3 = target - num[i];
            for (int j = i + 1; j < num.size()-2; j++) {
                int target_2 = target_3 - num[j];
                int front = j + 1;
                int back = num.size() - 1;
                while(front < back) {
                    int two_sum = num[front] + num[back];
                    if (two_sum < target_2) front++;
                    else if (two_sum > target_2) back--;
                    else {
                        vector<int> quadruplet={num[i],num[j],num[front],num[back]};
                        res.push_back(quadruplet);
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                    }
                }
                // Processing the duplicates of number 2
                while(num[j + 1] == num[j]) ++j;
            }
            // Processing the duplicates of number 1
            while (num[i + 1] == num[i]) ++i;
        }
        return res;
    }
};

int main(){
    vector<int> nums={-3,-1,0,2,4,5};
    target=2;
}