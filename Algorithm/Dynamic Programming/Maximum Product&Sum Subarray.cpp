//****************������������г˻�****************
int maxProduct(int *a,int n){
	int start1=1,start2=1;    //�������������ֵ 
	int all=1;
	for(int i=0;i<n;++i){
		start1=a[i]*start1;
		start2=a[n-i-1]*start2;
		all=max(max(start1,start2),all);
		if(!start1) start1=1;
		if(!start2) start2=1;			
	}
	cout<<all; 
}


int maxProduct(int *a,int n){
	while(n--){
		start=a[n]*start;
		if(!start) start=1;
		all=max(start,all);
	}
	int max = INT_MIN; //��ʼֵΪ�������
 	int sum;
 	for(int i = 0; i < n; i++){
	   	sum = 1;
	   	for(int j = i; j < n; j++){
     		sum *= a[j];
     		if(sum > max)
       		max = sum;
   		}
 	}
 	cout<<max;
}


//***************����������������***************
int maxSubarray(int *a,int n){
	int a[8] = { -1, 2, 3, -10, 4, 7, -2, 5 };
	int n(8); //size(8);
	// �޷��������������ֵΪ��ֵ����� 
	int sum = 0;
	int max = 0;
	int cur = 0;
	while (cur < size){
		sum += a[cur++];
		if (sum>max)
			max = sum;
		else if (sum < 0)
			sum = 0;
	}
	cout << "maxSubarray:" << max;

// ����ö�� O(n2)
int maxSubarray(int *a,int n){
	int max = INT_MIN; //��ʼֵΪ�������
 	int sum;
 	for(int i = 0; i < n; i++){
	   	sum = 0;
	   	for(int j = i; j < n; j++){
     		sum += a[j];
     		if(sum > max)
       		max = sum;
	   	}
 	}
 	cout<<max<<" "<<INT_MIN<<" "<<INT_MAX;
	return 0;
}

//DP 1
int maxSubarray(int *a,int n){
	int start=a[n-1];
	int all=a[n-1];
	for(int i=n-2;i>=0;i--){
		start=max(a[i],a[i]+start);
		all=max(start,all);
	}
	cout<<all;
}
//DP 2 ��DP 1һ��
int maxSubarray(int *a,int n){
	int start=a[0];
	int all=a[0];
	for(int i=1;i<n;++i){
		start=max(start+a[i],a[i]);   //����a[i]�����һ������
		all=max(start,all);           //i֮ǰ����������
	}
	cout<<all;
}
