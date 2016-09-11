#include<iostream>
#include<string>
#include<bitset>
using namespace std;
string GenerteCDKey(unsigned num1,unsigned num2,unsigned um_third);

string StringReverse(const string& str);

string GenrateCheck(const string& str);

void FormatPrint(const string& str);

int main()
{
	unsigned num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	string CDKey = GenerteCDKey(num1, num2, num3);
	FormatPrint(CDKey);
}
string GenerteCDKey(unsigned num1, unsigned num2, unsigned num3)
{
	const string charset = "23456789ABCDEFGHJKLMNPQRSTUVWXYZ";
	bitset<16> bit1(num1), bit2(num2), bit3(num3);
	string str_cicle = bit1.to_string() + bit2.to_string() + bit3.to_string();
	string reverse_string = StringReverse(str_cicle);
	bitset<48> bit_cicle(str_cicle);
	bitset<5> bit_loop;
	size_t index;
	string CDKey_left = "",CDKey="";
	for (size_t loop = 0; loop < 14; ++loop)
	{
		for (size_t i = loop*5; i < (loop*5+5);++i)
			bit_loop[i%5] = bit_cicle[i%48];
		index = bit_loop.to_ulong();	
		CDKey_left += charset[index];
	}
	CDKey = CDKey_left + GenrateCheck(CDKey_left);
	return CDKey;
}
string StringReverse(const string& str)
{
	string reverse(48, '0');
	size_t index = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		reverse[47-index] = str[i];
		++index;
	}
	return reverse;
}
string GenrateCheck(const string& str)
{
	const string charset = "23456789ABCDEFGHJKLMNPQRSTUVWXYZ";
	unsigned sum = 0;
	for (int i = 0; i < str.size(); ++i)
		sum += str[i];
	bitset<10> bitset_sum(sum);
	bitset<5> bitset_check_one;
	bitset<5> bitset_check_two;
	for (size_t i = 0; i < 5; ++i)
	{
		bitset_check_one[i] = bitset_sum[i];
		bitset_check_two[i] = bitset_sum[i + 5];
	}
	size_t index_one = bitset_check_one.to_ulong(), index_two = bitset_check_two.to_ulong();
	string check_str = "";
	check_str += charset[index_one];
	check_str += charset[index_two];
	return check_str;
}
void FormatPrint(const string& str)
{
	string out_str="";
	for (size_t index = 0; index < 16;++index)
	{
		out_str += str[index];
		if (index % 4 == 3&&index!=15)
			out_str += '-';
	}
	cout << out_str << endl;
}
