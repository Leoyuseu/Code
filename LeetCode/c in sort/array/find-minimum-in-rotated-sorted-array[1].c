int findMin(int* nums, int numsSize) {
    int start,end,mid;
    start = 0;
    end = numsSize - 1;

    while(start < end){
        mid = start + (end - start) / 2;
        if(nums[mid] > nums[end])
            start = mid + 1;
        else
            end = mid;
    }

    return nums[start];
}
