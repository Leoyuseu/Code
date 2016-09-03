// 不适用STL的unordered_map，自己定义哈希表
// 创建一个长为256的数组，每个字母根据其ASC2码作为数组的下标
// 对应数组中的一个数字，key键值是下标，数组中存储的是每个字符出现的次数      

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

char FirstNotRepeatingChar(char* pString) { 
	if(pString == NULL) {
		return '\0';     //空字符不能返回 ‘’
	}
	// 建立哈希表
	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for(unsigned int i = 0; i < tableSize; ++i) {
		hashTable[i] = 0;
	}
	char *pHashKey = pString;
	while(*pHashKey != '\0') { 
		++hashTable[*pHashKey];
		++pHashKey;
	}
	pHashKey = pString;
	while(*pHashKey != '\0') { 
		if(hashTable[*pHashKey] == 1) {
			return *pHashKey;
		}
		++pHashKey;
	}
	return '\0';
}

char FirstNotRepeatingChar(string s){
	if(s.empty()) return '\0';

	vector<int> hashTable(256, 0);

	for(int i = 0; i < s.size(); ++i) {
		hashTable[s[i]]++;
	}
	for(int i = 0; i < s.size(); ++i) {
		if(hashTable[s[i]] == 1){
			return s[i];
		} 
	}
	return '\0';
}

int main() {
	// char input[100];
	// cin >> input;
	string s;
	cin >> s;
	cout << FirstNotRepeatingChar(s);
}