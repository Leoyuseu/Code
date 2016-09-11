// Suppose a sorted array is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// Find the minimum element.

// You may assume no duplicate exists in the array.

class Solution {
public:
    int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
            int mid = (start+end)/2;
            if (num[mid]>=num[start]) {
                start = mid+1;
            } 
            else {
                end = mid;
            }
        }
        return num[start];
    }
};


//The array may contain duplicates.
class Solution {
public:
    int findMin(vector<int>& num) {
        int start=0, end = num.size()-1;
        while (start < end) {
            int mid = (start+end)/2;
            
            if (num[mid] > num[end]) {
                start = mid + 1;
            } 
            else if(num[mid] < num[end]){
                end = mid;
            }
            else --end;
        }
        return num[start];
    }
};

class Solution {
public:
    int findMin(vector<int>& num) {
        sort(num.begin(), num.end());
        return num[0];
    }
};