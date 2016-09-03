//兼职获得最多工资问题
//n份兼职 每m个连续做消耗1体力 共k体力

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> wage;
	for(int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		wage.push_back(temp);
	}
	vector<int> adj;
	for(int i = 0; i < n - m + 1; ++i){
		int ad = 0;
		for(int j = i; j < i + m; ++j){
			ad += wage[j];
		}
		adj.push_back(ad);
	}
	int len = adj.size();
	vector<int> temp = adj;
	vector<int> res;
	sort(temp.begin(),temp.end());
	res.push_back(temp[len - 1]);
	if(k == 1) {
		cout<<res[0];
		return 0;
	}
	for(int i = len - 2; i >= 0; --i){
		auto it1 = find(adj.begin(), adj.end(), res.back());
		auto it2 = find(adj.begin(), adj.end(), temp[i]);
		if((it1 > it2 && it1 - it2 >= m) || it1 < it2 && it2 - it1 >= m){
			res.push_back(temp[i]);
		}
		if(res.size() == k) break;
	}
	int moneyMax = 0;
	for(int i = 0; i < res.size(); ++i){
		moneyMax += res[i];
	}
	cout<<moneyMax;
	return 0;
} 
