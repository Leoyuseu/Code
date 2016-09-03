// 75	Sort Colors

void sortColors(vector<int>& nums) {
    int n0=count(nums.begin(),nums.end(),0);
    int n1=count(nums.begin(),nums.end(),1);
    int n2=count(nums.begin(),nums.end(),2);
    nums.clear();
    nums.insert(nums.begin(),n2,2);
    nums.insert(nums.begin(),n1,1);
    nums.insert(nums.begin(),n0,0);
}

void sortColors(vector<int>& nums) {
    if(nums.size()<2)   return;
    int n = nums.size();
    int i=-1, k=n;
    for(int j=0; j<k; j++){
        while(i<j && j<k && nums[j]!=1){
            if(nums[j]==0)  swap(nums[i+1], nums[j]), i++;
            else    swap(nums[k-1], nums[j]), k--;
        }
    }
}

void sortColors(vector<int>& nums) {
    int front = 0, end = nums.size() - 1;
    for(int j = 0; j < nums.size(); j++)
    {
        int pivot = nums[j];
        // make all numbers less than pivot move to left, 
        // and numbers bigger than pivot to the right.
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < pivit)
            {
                swap(nums[i],nums[front]);
                front ++;
            }
            else if (nums[i] > pivot)
            {
                swap(nums[i],nums[end]);
                end--;
            }
            if(front == end || end <= i){break;}
        }
        front = 0;
        end = nums.size() - 1;
    }
}

void sortColors(vector& nums) {
    int sz = nums.size();
    int curr=0, l=-1,r=sz;
    while(curr<r){
        // 0: <=l
        // 1: l< <curr
        // 2: r<=
        // unsort: curr<= <r
        if(nums[curr]==0) swap(nums[++l], nums[curr++]);

        else if(nums[curr] == 1) curr++;
        else swap(nums[curr], nums[--r]);
    }
}