// 某城市电话号码由三部分组成，分别是：
// 地区码：空白或者三位数字；
// 前缀：非0开头的三位数字
// 后缀：4位数字
// 假定被测程序能接受一切符合上述规定的电话号码，输出0
// 拒绝一切不符合规定的电话号码，输出1.
// 请编写程序实现上述描述的功能.


// 测试用例结果:	
// 测试用例数量	10
// 失败数量	1
// 异常数量	0
// 1	


#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main(){
	string area = "", pre, back;
	int output = 0;
	cin >> area;
	cin >> pre;
	cin >> back;
	if((area.size() !=3 && !area.empty()) || pre.size() != 3 || back.size() != 4) 
		output = 1;
	else {
		if(!area.empty()){
			for(int i = 0;i < 3 ; ++i){
				if(!isdigit(area[i])) 
					output = 1;
			}
		}
		for(int i = 0;i < 3 ; ++i){
			if(!isdigit(pre[i])) 
			output = 1;
		}
		for(int i = 0;i < 4 ; ++i){
			if(!isdigit(back[i])) 
			output = 1;
		}
		if(pre[0] - '0' == 0) 
			output = 1;
	}
	cout << output << endl;
	return 0;
} 
