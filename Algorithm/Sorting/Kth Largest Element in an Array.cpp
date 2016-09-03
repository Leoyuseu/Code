;// Well, this problem has a naive solution, which is to sort 
// the array in descending file:///E:/EESEUorder and return the k-1-th element. 

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end(),greater<int>());
    return nums[k-1];
}

// However, sorting algorithm gives O(nlogn) complexity. 
// Suppose n = 10000 and k = 2, then we are doing a lot of unnecessary operations. 
// In fact, this problem has at least two simple and faster solutions.

// Well, the faster solution has no mystery. It is also closely related to sorting. 
// I will give two algorithms for this problem below, one using quicksort
// (specifically, the partition subroutine) and the other using heapsort.

// ********************Quicksort**************************
// In quicksort, in each iteration, we need to select a pivot and 
// then partition the array into three part

// In fact, the above partition puts elements smaller than the pivot 
// before the pivot and thus the pivot will then be the k-th smallest element 
// if it is at the k-1-th position. Since the problem requires us to find 
// the k-th largest element, we can simply modify the partition to 
// put elements larger than the pivot before the pivot. That is, after partition, 
// the array becomes [5, 6, 4, 3, 1, 2]. Now we know that 3 is the 4-th largest element. 
// If we are asked to find the 2-th largest element, then we know it is left to 3. 
// If we are asked to find the 5-th largest element, then we know it is right to 3. 
// So, in the average sense, the problem is reduced to approximately half of 
// its original size, giving the recursion T(n) = T(n/2) + O(n) 
// in which O(n) is the time for partition. This recursion, once solved, 
// gives T(n) = O(n) and thus we have a linear time solution. 
// Note that since we only need to consider one half of the array, 
// the time complexity is O(n). If we need to consider both the two halves of the array, 
// like quicksort, then the recursion will be T(n) = 2T(n/2) + O(n) 
// and the complexity will be O(nlogn).

// Of course, O(n) is the average time complexity. In the worst case, 
// the recursion may become T(n) = T(n - 1) + O(n) and the complexity will be O(n^2).
// Now let's briefly write down the algorithm before writing our codes.

// Initialize left to be 0 and right to be nums.size() - 1;
// Partition the array, if the pivot is at the k-1-th position, return it (we are done);
// If the pivot is right to the k-1-th position, update right to be 
// the left neighbor of the pivot;
// Else update left to be the right neighbor of the pivot.
// Repeat 2.
// Now let's turn it into code.

class Solution { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};


// **************************Heapsort*************************
// Well, this problem still has a tag "heap". If you are familiar with heapsort, 
// you can solve this problem using the following idea:
// Build a max-heap for nums, set heap_size to be nums.size();
// Swap nums[0] (after buding the max-heap, it will be the largest element) 
// with nums[heap_size - 1] (currently the last element). 
// Then decrease heap_size by 1 and max-heapify nums (recovering its max-heap property) at index 0;
// Repeat 2 for k times and the k-th largest element will be stored finally at nums[heap_size].
// Now I paste my code below. If you find it tricky, 
// I suggest you to read the Heapsort chapter of Introduction to Algorithms, 
// which has a nice explanation of the algorithm. 
// My code simply translates the pseudo code in that book :-)

class Solution {
public:   
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--)
            max_heapify(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[0], nums[heap_size - 1]);
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[heap_size];
    }
private:
    int heap_size;
};


// If we are allowed to use the built-in priority_queue, 
// the code will be much more shorter :-)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop(); 
        return pq.top();
    }
};


//using STL multiset--Red-Black tree
typedef multiset<int,less<int>> intset;
void findKthLargest(vector<int> &nums,int k,intset &Kthset){
    if(k<1||nums.size<k) return;
    for(auto num:nums){//iter=nums.begin();iter!=nums.end();++iter){
        if(Kthset.size()<k) Kthset.insert(num);
        else{
            auto top=Kthset.begin();
            if(num>*(Kthset.begin())){
                Kthset.erase(top);
                Kthset.insert(num);
            }
        }
    }
}