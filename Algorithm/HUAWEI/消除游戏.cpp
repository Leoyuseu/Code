// 消除类游戏很多，一般横、竖、斜有连续三个及以上相同就可以消除，为降低难度，本题只需要考虑一维的横消除即可，
// 即在给定的一组数字中（个，用例保证只有个），如果有连续三个及以上的数字相同，则将这些数字消除，
// 同时如果前一次消除后导致后面连在一起的也有三个及以上的数字相同，需继续消除，最终输出不能消除的剩余的数字，如果所有数字都消除，则输出none
// 输入: 输入一组数字：
//     1 1 1 2 3 4 4 4 3 5 5 5 3 6 7 
// 输出: 剩除没有消除的数字：
//     2 6 7
// 样例输入: 1 1 1 2 3 4 4 4 3 5 5 5 3 6 7 
// 样例输出: 2 6 7 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string nums;  //用string可以使内部多种字符，包括数字和字母等
	cout << "消了它:";
	cin >> nums;
	vector<char> nums_erased;
	for (string::size_type i = 0; i < nums.size(); ++i){
		if (nums_erased.size() < 2)      //注意是小于2，如果条件size<3则已有两个元素时还会继续push
			nums_erased.push_back(nums[i]);
		else {
			vector<char>::iterator iter = nums_erased.end();
			if (nums[i] == *(--iter) && nums[i] == *(--iter)){
				nums_erased.pop_back();
				nums_erased.pop_back();
			}
			else
				nums_erased.push_back(nums[i]);
		}
	}
	if (nums_erased.size() == 0)
		cout << "all clear!";
	else{
		cout << "消消乐：";
		for (vector<char>::iterator iter = nums_erased.begin(); iter != nums_erased.end(); ++iter)
			cout << *iter;
	}
}
