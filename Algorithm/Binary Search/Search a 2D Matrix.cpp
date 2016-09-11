// Write an efficient algorithm that searches for a value 
// in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last 
// integer of the previous row.
// For example,

// Consider the following matrix:

// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        vector<int> nums;
        for(int i = 0; i < matrix.size(); ++i){
            // for(int j = 0; j < matrix[0].size(); ++j){
            //     nums.push_back(matrix[i][j]);
            // }
            // insert优于for循环
            nums.insert(nums.end(), matrix[i].begin(), matrix[i].end());
        }
        int left = 0, right =nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] > target) right = mid -1;
            else if(nums[mid] < target) left = mid + 1;
            else return true;
        }
        return false;
    }
};

// O(log(mn))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.empty()) || matrix[0].empty() return false;
	    int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
        // if(matrix.empty()) return false;
        // int row = matrix.size();
        // int column = matrix[0].size();
        // int leftRow = 0, rightRow = row - 1;
        // int leftColumn = 0, rightColumn = column - 1;
        // while(leftRow < rightRow || leftColumn < rightColumn){
        //     int midRow = (leftRow + rightRow) >> 1;
        //     int midColumn = (leftColumn + rightColumn) >> 1;
        //     cout << midRow <<" " << midColumn << endl; 
        //     if(matrix[midRow][midColumn] > target){
        //         if(midRow == 0 && midColumn == 0) return false;
        //         else if(midRow == 0){
        //             rightRow = midRow;
        //             rightColumn = midColumn - 1; 
        //         }
        //         else if(midColumn == 0){
        //             rightRow = midRow - 1;
        //             rightColumn = midColumn;
        //         }
        //         else{
        //             rightRow = midRow;
        //             rightColumn = midColumn - 1;
        //         }
        //     }
        //     else if(matrix[midRow][midColumn] < target){
        //         if(midRow == (row - 1) && midColumn == (column - 1)) return false;
        //         else if(midRow == (row - 1)){
        //             leftRow = midRow;
        //             leftColumn = midColumn + 1; 
        //         }
        //         else if(midColumn == (column - 1)){
        //             leftRow = midRow + 1;
        //             leftColumn = midColumn;
        //         }
        //         else{
        //             leftRow = midRow;
        //             leftColumn = midColumn + 1;
        //         }
        //     }
        //     else return true;
        // }
        // return false;
    }
};

int main(){
	vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	int target = 3;
	Solution st;
	cout << st.searchMatrix(matrix, target);
}
