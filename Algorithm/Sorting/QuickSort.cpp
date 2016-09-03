#include <iostream>  
using namespace std;

template <class T>
void show(T arr, int n){
	for (int i = 0; i<n - 1; i++){
		cout << arr[i] << ",";
	}
	cout << arr[n - 1] << endl;
}

//***************************************************
void QuickSort(int a[], int l, int r) {
	show(a, 9);
	if (l >= r) return;
	int i, j, temp;
	temp = a[l];
	i = l; j = r;
	while (i<j) {           //可改为for循环
		while (i<j&&temp<a[j])
			j--;
		a[i] = a[j];
		while (i<j&&temp>a[i])
			i++;
		a[j] = a[i];
	}
	a[i] = temp;

	QuickSort(a, l, i - 1);
	QuickSort(a, i + 1, r);    //递归
}


//**************************************************
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
void QuickSort(vector<int> &nums,int start,int end){
    if(start==end) return;
    int index=partition(nums,start,end);
    if(index>start)
        QuickSort(nums,start,index-1);
    if(index<end)
        QuickSort(nums,index+1,end);
} 


//*************************************************
void Qsort(int a[], int low, int high){
    if(low >= high){
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];
    while(first < last){
        while(first < last && a[last] >= key){
            --last;
        }
        a[first] = a[last];
        while(first < last && a[first] <= key){
            ++first;      
        a[last] = a[first];    
    }
    a[first] = key;
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}

void main()
{
	int inputNumber[] = { 2, 7, 5, 9, 1, 4, 6, 3, 8 };
	int count = 9;
	cout << "原始数组：" << endl;
	show(inputNumber, count);
	cout << "排序过程：" << endl;
	QuickSort(inputNumber, 0, count);
	cout << "排序结果：" << endl;
	show(inputNumber, count);
}