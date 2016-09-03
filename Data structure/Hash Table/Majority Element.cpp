// Given an integer array of size n, find all elements that appear more than n/3 times. 
// The algorithm should run in linear time and in O(1) space.

class Solution {  // n/2
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }
};

// Moore Voting Algorithm
// A brilliant and easy-to-implement algorithm! It also runs very fast, about 20ms.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};


// ************n/3*****************
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> majnums;
        int n = nums.size();
        unordered_map<int, int> counts;
        for(int i = 0; i < n; ++i){
            if(++counts[nums[i]] > n/3){
                majnums.push_back(nums[i]);
            }
        }
        sort(majnums.begin(), majnums.end());
        majnums.erase(unique(majnums.begin(),majnums.end()), majnums.end());
        return majnums;
    }
};


// Hash Table

// The hash-table solution is very straightforward. We maintain a mapping from each element to its number of appearances. While constructing the mapping, we update the majority element based on the max number of appearances we have seen. Notice that we do not need to construct the full mapping when we see that an element has appeared more than n / 2 times.

// The code is as follows, which should be self-explanatory.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }
};
// Sorting

// Since the majority element appears more than n / 2 times, the n / 2-th element in the sorted nums must be the majority element. This can be proved intuitively. Note that the majority element will take more than n / 2 positions in the sorted nums (cover more than half of nums). If the first of it appears in the 0-th position, it will also appear in the n / 2-th position to cover more than half of nums. It is similar if the last of it appears in the n - 1-th position. These two cases are that the contiguous chunk of the majority element is to the leftmost and the rightmost in nums. For other cases (imagine the chunk moves between the left and the right end), it must also appear in the n / 2-th position.

// The code is as follows, being very short if we use the system nth_element (thanks for @qeatzy for pointing out such a nice function).

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    } 
};
// Randomization

// This is a really nice idea and works pretty well (16ms running time on the OJ, almost fastest among the C++ solutions). The proof is already given in the suggested solutions.

// The code is as follows, randomly pick an element and see if it is the majority one.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            if (counts > n / 2) return candidate;
        }
    }
};
// Divide and Conquer

// This idea is very algorithmic. However, the implementation of it requires some careful thought about the base cases of the recursion. The base case is that when the array has only one element, then it is the majority one. Moreover, this solution is relatively slow in practice.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return counts(nums, lm) > counts(nums, rm) ? lm : rm;
    }
    int counts(vector<int>& nums, int elem) {
        int cnt = 0;
        for (int i = 0; i < int(nums.size()); i++)
            if (nums[i] == elem) cnt++;
        return cnt;
    }
};
// Moore Voting Algorithm

// A brilliant and easy-to-implement algorithm! It also runs very fast, about 20ms.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};
// Bit Manipulation

// Another nice idea! The key lies in how to count the number of 1's on a specific bit. Specifically, you need a mask with a 1 on the i-the bit and 0 otherwise to get the i-th bit of each element in nums. The code is as follows.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
        } 
        return major;
    } 
};
