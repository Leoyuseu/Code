#include <iostream>
#include <vector>
//#include <algorithm>   //swap
using namespace std;

void show(const vector<int> &ivec){
	for(auto it = ivec.begin() + 1; it !=ivec.end(); ++it){
		cout << *it <<" ";
	}
	cout << endl;
}

void heapAdjust(vector<int> &ivec, int pos, int end){   //调整堆
	int posnum = ivec[pos];
	for(int j = 2 * pos; j <= end; j *= 2){
		if(j < end && ivec[j] < ivec[j+1]){  //沿着值较大的孩子节点向下筛选,下沉  
			++j; //j为值较大的记录的下标  
		} 
		if(posnum >= ivec[j]){  
			break; //posnum应插入在更新之后的位置pos上
		}
		ivec[pos] = ivec[j];
		pos = j;
	}
	ivec[pos] = posnum;   //插入原来pos位置的数字
}

void heapsort(vector<int> &ivec){
	for(int i = ivec.size() / 2; i > 0; --i){
		heapAdjust(ivec ,i, ivec.size()-1);   //建立最大堆，让每个节点都是堆，因为大于n/2的点都是叶子节点，已是堆
		show(ivec);
	}
	cout<<endl;
	for(int i = ivec.size() - 1; i > 1; --i){
		swap(ivec[1], ivec[i]);
		heapAdjust(ivec, 1, i - 1);  //调整无序区
		show(ivec);
	}
}

int main(){
	vector<int> ivec = {0 ,2, 7, 5, 9, 1, 4, 6, 3 ,8};  //0占第0位作用，
								//如果从0开始存储数据，则左右孩子分别为2*i+1和2*i+2
	heapsort(ivec);
}
