// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2
// 考察hash_table O(N)或者夹逼O(nlgn)   
vector<int> twoSum(vector<int> &numbers, int target){
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for(int i = 0 ; i < numbers.size() ; ++ i)
        hash[numbers[i]]=i+1;
    for (int i = 0; i < numbers.size(); ++ i) {
        int numberToFind = target - numbers[i];
        //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
            if(hash[numberToFind] != i + 1){
                result.push_back(hash[numberToFind]);
                result.push_back(i + 1);            
                return result;
            }
        }            
        //hash[numbers[i]] = i;   //number was not found. Put it in the map.
    }
    return result;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> v = numbers;  //不改变给的数组值
        sort(v.begin(), v.end());
        int left = 0;
        int right = v.size() - 1;
        int middle;
        while (left < right) {   //夹逼找值
            int middle = v[left] + v[right];
            if (middle == target) break;
            if (middle < target) 
                ++left; 
            else 
                --right;
        }
        int result_index1;
        int result_index2;
        for (int i=0;i<v.size();++i) {
            if (numbers[i] == v[left]) { 
                result_index1 = i; 
                break;
            }
        }
        for (int i=(int)v.size()-1;i >= 0;--i) {
            if (numbers[i] == v[right]) {
                result_index2 = i; 
                break; 
            }
        }
        if (result_index1 > result_index2) 
            swap(result_index1,result_index2);
        vector<int> result {result_index1 + 1, result_index2 + 1};
        return result;
    }
};