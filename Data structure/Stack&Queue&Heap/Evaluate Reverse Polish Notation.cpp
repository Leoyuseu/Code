int evalRPN(vector<string> &n) {
    string s = n.back(); 
    n.pop_back();
    if ( s== "*" || s=="/" || s=="+" || s == "-" ){
        int r2 = evalRPN(n);
        int r1 = evalRPN(n);
        if ( s=="*") return r1*r2;
        if ( s=="/") return r1/r2;
        if ( s=="+") return r1+r2;
        if ( s=="-") return r1-r2;
    }
    else
        return stoi(s);
}

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <math.h>

using namespace std;

float calcu(float lhs, char op, float rhs)
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
	case '^':
		return pow(lhs, rhs);
		break;
	default:
		return 0;
		break;
	}
}

float calcu(float lhs)     //ÖØÔØcalcu´¦Àíµ¥Ä¿ÔËËã·û
{
	float times=1;
	for (int i = 1; i <= lhs; ++i)
		times *= i;
	return times;
}

bool Prior(char cOp1, char cOp2) //Ö»ÓÐ+¡ª*/Ê±ÓÅÏÈ¼¶Ö»ÓÐÁ½ÖÖÇé¿ö.cop1ÊÇ*or/ÇÒcop2ÊÇ+or-µÄÊ±ºòÓÅÏÈ¼¶ÊÇÇ°ÓÅÏÈ£¬·µ»Øtrue
{
	return (cOp1 == '*' || cOp1 == '/') && (cOp2 == '+' || cOp2 == '-');
}

string intopost(string infix)   //ºó×º±í´ïÊ½×ª»»³ÉÇ°×º±í´ïÊ½
{
	string postfix;
	stack<char> S;
	for (string::size_type i = 0; i < infix.size(); ++i)
	{
		if (isdigit(infix[i]))
			postfix.push_back(infix[i]);
		else if (infix[i] == '(')
			S.push(infix[i]);
		else if (infix[i] == ')')
		{
			while (S.top() != '(')
			{
				postfix.push_back(S.top());
				S.pop();
			}
			S.pop();       //°Ñ£¨µ¯³ö
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')              //(strchr("+-*/", infix[i]))    //infix[i]ÊÇ¼Ó¼õ³Ë³ýÖÐµÄÒ»¸öÊ±·µ»ØÎ»ÖÃÖ¸Õë£¬Ã»ÕÒµ½·µ»ØNULL
		{
			while (!S.empty() && S.top() != '('&&!Prior(infix[i], S.top()))
			{
				postfix.push_back(S.top());
				S.pop();
			}
			S.push(infix[i]);
		}
	}
	while (!S.empty())              //°ÑSµÄÄ©Î²Ê£ÏÂµÄÔËËã·ûÖðÒ»³öÕ»¼ÓÈëºó×º±í´ïÊ½
	{
		postfix.push_back(S.top());
		S.pop();
	}
	return postfix;
}

int main()
{
	string STRexp;
	string RPNexp;
	stack<float> opnd;
	cout << "input the STRexp:";
	getline(cin, STRexp);
	RPNexp = intopost(STRexp);
	cout << RPNexp << endl;

	for (string::size_type i = 0; i < RPNexp.size(); ++i)
	{
		if (isdigit(RPNexp[i]))
			opnd.push(RPNexp[i]-'0');   //×Ö·û±ä³ÉÊý×Ö
		else
		{
			float ropnd = opnd.top();
			opnd.pop();
			float lopnd = opnd.top();
			opnd.pop();
			opnd.push(calcu(lopnd, RPNexp[i], ropnd));
		}
	}
	float result = opnd.top();
	cout << "the result of RPN is:" << result;

	return 0;
}