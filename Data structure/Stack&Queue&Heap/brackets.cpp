#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int testnum;
	cin >> testnum;
	if (testnum <= 0 || testnum > 5){
		cerr << "测试数组需少于5组。" << endl;
		return 0;
	}
	stack<char> S;
	string brackets;
	vector<string> allbrackets;
	for (int i = 0; i <= testnum; i++){
		getline(cin, brackets);
		allbrackets.push_back(brackets);
		brackets.clear();
	}
	for (auto iter = allbrackets.begin(); iter < allbrackets.end(); ++iter){
		for (string::size_type i = 0; i < (*iter).size(); ++i) {
			if ((*iter)[i] == '{' || (*iter)[i] == '[' || (*iter)[i] == '(')
				S.push((*iter)[i]);
			else
			{
				if (((*iter)[i] == '}'&&S.top() == '{') || 
					((*iter)[i] == ']'&&S.top() == '[') || 
					((*iter)[i] == ')'&&S.top() == '('))
					S.pop();
				else
					S.push((*iter)[i]);
			}
		}
		cout << (S.empty() ? "Yes" : "No") << endl;
		while (!S.empty())
			S.pop();
	}
	return 0;
}