#include<iostream>
using namespace std;

class stock
{
private:
	int money;
	int price[12];
public:
	stock();
	void show();
	~stock(){}
};

stock::stock()                 //自动运行构造函数
{
	cout << "invest money:";
	cin >> money;
	for (int i = 0; i < 12; i++)
	{
		cout << "price of day " << i + 1 << ":";
		cin >> price[i];
	}
}
void stock::show()
{
	int max = 0, num, start, end, value, pos1, pos2;
	for (int i = 0; i<11; i++)
	{
		num = money / price[i];
		if (num >= 1)
		{
			start = num*price[i];
			for (int j = i + 1; j<12; j++)
			{
				end = num*price[j];
				value = end - start;
				if (value>max)
				{
					pos1 = i;
					pos2 = j;
					max = value;
				}
			}
		}
	}
	if (max == 0)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << "buy:"<<pos1 + 1 << " sell:" << pos2 + 1 << " earn:" << max << endl;
}
int main()
{
	int n;
	cout << "input exp number:";
	cin >> n;
	stock *a = new stock[n];        //创建多个stock对象，自动运行各自的构造函数
	for (int i = 0; i<n; i++)
	{
		a[i].show();
	}
	delete[]a;
	return 0;
}
