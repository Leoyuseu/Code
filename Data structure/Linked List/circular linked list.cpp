#include<iostream>
#include<string>
#include<cctype>

using namespace std;

struct ListNode{
	char val;
    ListNode *next;
    ListNode(char x) : val(x), next(NULL) {}
};

int main(){
	string input;
	string output;
	getline(cin,input);
	if(input.size() < 3) return 0;
	int m = 0;
	if(isdigit(input[0])){ 
		m = input[0] - '0';
		if(m == 0) return 0;
	}
	else return 0;
	
	ListNode *dummy = new ListNode('0');
	ListNode *p = dummy;
	for(int i = 0; i < input.size(); ++i){
		if(isalpha(input[i])){
			ListNode *node = new ListNode(input[i]);
			p->next = node;
			p = p->next;
		}
	}
	p->next = dummy->next;
	ListNode *head = dummy->next;
	delete dummy;
	
	ListNode *del = p;
	p = head;
	if(!p) return 0;
	while(p->next != p){
		for(int i = 1; i < m - 1 ; ++i){
			p = p->next;
		}
		ListNode *del = p->next;
		cout << del->val << " "; 
		p -> next = p->next->next;
		p = p->next;
		delete del;
	}
	cout << p->val;
	delete p;
	return 0;
}