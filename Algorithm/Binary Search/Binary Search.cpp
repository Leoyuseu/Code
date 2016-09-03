// Search for a Range 
// Given a sorted array of integers, find the starting and ending position 
// of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1, -1};
        if(find(nums.begin(), nums.end(), target) == nums.end()) return res;
        auto low = lower_bound(nums.begin(), nums.end(), target);
        auto high = upper_bound(nums.begin(), nums.end(), target);
        int lo = static_cast<int> (low - nums.begin());
        int hi = static_cast<int> (high - nums.begin() -1);
        res[0] = lo, res[1] = hi;
        return res;
    }
};

vector<int> searchRange(vector<int>& nums, int target) {
    int start = 0, end = nums.size(), mid, left, right;
    while (start < end) {
        mid = (start + end) / 2;
        if (nums[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }
    left = start;
    start = 0, end = nums.size();
    while (start < end) {
        mid = (start + end) / 2;
        if (nums[mid] > target)
            end = mid;
        else
            start = mid + 1;
    }
    right = start;
    return left == right ? vector<int> {-1,-1} : vector<int> {left,right-1};
}


#include<iostream>
using namespace std;

int BinarySearch(int array[],int n,int value){
	int left=0;
	int right=n-1;
	while(left <= right){    //注意是<=号
		int mid=left+((right-left)>>1);
		cout<<mid<<endl;
		if (array[mid]>value)
			right=mid-1;
		else if(array[mid]<value)
			left=mid+1;
		else
			return mid;
	}
	return -1;
}

//STL lower_bound & upper_bound
int lower_bound(int *array, int size, int key)
{
    int first = 0, middle;
    int half, len;
    len = size;
    while(len > 0) {
        half = len >> 1;
        middle = first + half;
        if(array[middle] < key) {     
            first = middle + 1;          
            len = len-half-1;       //在右边子序列中查找        
        }
        else
            len = half;            //在左边子序列（包含middle）中查找    
    }
    return first;
}

int upper_bound(int *array, int size, int key)
{
    int first = 0, len = size-1;
    int half, middle;
    while(len > 0){
        half = len >> 1;
        middle = first + half;
        if(array[middle] > key)     //中位数大于key,在包含last的左半边序列中查找。
            len = half;
        else{
            first = middle + 1;    //中位数小于等于key,在右半边序列中查找。
            len = len - half - 1;
        }
    }
    return first;
}


int main(){
	int n[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	cout<<"result:"<<BinarySearch(n,20,3);
	return 0;	
} 


