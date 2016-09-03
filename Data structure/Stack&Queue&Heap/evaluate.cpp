#include<iostream>
#include<string>
#include<stack>
#include<cctype>

using namespace std;

char orderBetween(char top, char exp)
{
	if (top == '+' ||top == '-') //+-一样，*/一样
	{
		switch (exp)
		{
		case '+':
			return '>';
			break;
		case '-':
			return '>';
			break;
		case '*':
			return '<';
			break;
		case '/':
			return '<';
			break;
		case 'E':
			return '>';
			break;
		}
	}
	if (top=='*'||top == '/')
	{
		switch (exp)
		{
		case '+':
			return '>';
			break;
		case '-':
			return '>';
			break;
		case '*':
			return '>';
			break;
		case '/':
			return '>';
			break;
		case 'E':
			return '>';
			break;
		}
	}
	if (top == 'E')
		return '=';
}

float calcu(float lhs, char op,float rhs)
{
	switch (op)
	{
	case '+':
		return lhs + rhs;
		break;
	case '-':
		return lhs - rhs;
		break;
	case '*':
		return lhs * rhs;
		break;
	case '/':
		return lhs / rhs;
		break;
	}
}

int main()
{
	stack<float> opnd;
	stack<char> optr;
	string exp;
	cout << "input the expression:";
	getline(cin, exp);

	while (!optr.empty())
	{
		auto p = exp.begin();
		if (isdigit(*p))
			opnd.push(*p-'0');   //推入数字而不是字符常量
		else
		{
			if ((orderBetween(optr.top(), *p)) == '>')
			{	
				float popnd2 = opnd.top();      //opnd.pop()返回值为void，不能直接使用
				opnd.pop();
				float popnd1 = opnd.top();     //注意操作数的出栈顺序
				opnd.pop();
				char op = optr.top();
				optr.pop();
				opnd.push((calcu(popnd1, op, popnd2)));
				p++;
			}
			else if ((orderBetween(optr.top(), *p)) == '=')
			{
				optr.pop();
				p++;
			}
			else
			{
				optr.push(*p);
				p++;
			}
		}
	}
	float result = opnd.top();
	cout << "The answer is:" << result <<endl;

	return 0;
}