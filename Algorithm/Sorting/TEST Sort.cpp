#include<iostream>
#include<vector>
#include<set>
#include<functional>
#include<queue>
using namespace std;

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
    for(auto num:nums) cout<<num<<" ";
	cout<<endl; 
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

int findKthSmallest(vector<int>& nums, int k) {
	int left = 0, right = nums.size() - 1;
	while (true) {
        int pos = partition(nums, left, right);
        if (pos == nums.size() - k) return nums[pos];
        if (pos > nums.size() - k) right = pos - 1;
        else left = pos + 1;
    }
}

void QuickSort(vector<int> &nums,int start,int end){
    if(start==end) return;
    int index=partition(nums,start,end);
    if(index>start)
        QuickSort(nums,start,index-1);
    if(index<end)
        QuickSort(nums,index+1,end);

} 


//red-black tree 
typedef multiset<int,less<int>> intset;
void findKthLargest(vector<int> &nums,int k,intset &Kthset){
    if(k<1||nums.size()<k) return;
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

//priority_queue
priority_queue<int> findKthsmallestpq(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++)
        pq.pop(); 
    return pq;
}

priority_queue<int, vector<int>, greater<int> > findKthlargestpq(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++)
        pq.pop(); 
    return pq;
//    for(auto num:nums){
//    	if(pq.size()<k) pq.push(num);
//    	else{
//    		auto top=pq.top();
//    		if(num>top){
//    			pq
//			}
//		}
//	}
}

int main(){	
    vector<int> nums={7,9,4,5,3,6,8,6,35,1264,652,741,315};
//    cout<<findKthLargest(nums,5)<<" "<<findKthSmallest(nums,4);
//    QuickSort(nums,0,12);
//	intset Kthset;	
//    findKthLargest(nums,7,Kthset);
//    for(auto num:Kthset){
//    	cout<<num<<"  ";
//	}
//	cout<<endl;
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int> > pq2;
	pq=findKthsmallestpq(nums,7);
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	pq2=findKthlargestpq(nums,7);
	while(!pq2.empty()){
		cout<<pq2.top()<<" ";
		pq2.pop();
	}
	cout<<endl; 
}
