// 输入1个数字和多个字符，中间均以空格隔开。假设数字取值为m（范围1~9），
// 后面字符个数为n。假设n个字符围成一圈，从第一个字母开始循环报数，
// 当数到m以后，第m个字母就出列，直到这n个字母全部出列。最后，按照出列的
// 顺序输出这些字母，中间仍以空格隔开。取值范围：m为1到9， 字符个数n大于1小于20。

// 测试用例数量	8
// 失败数量	1
// 异常数量	0
// testcase3	

#include <iostream>
#include <string>
#include <cctype>

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
	if(dummy->next == NULL) return 0;
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


#include <cstdio>  
#include <string>  
#include <malloc.h>  
using namespace std;  
  
typedef struct list  
{  
    char c;  
    list *next;  
}List;  
  
int main()  
{  
    char input[100];  
    int i,length,total = 0;  
    List *head, *p, *q;  
    head = (List*)malloc(sizeof(List));  
    p = q = head;  
    gets(input);  
    length = strlen(input);  
    head->c = input[0];  
    for(i = 2;i<length;i+=2)  
    {  
        p = (List*)malloc(sizeof(List));  
        p->c = input[i];  
        q->next = p;  
        q = p;  
        total++;  
    }  
    p->next = head->next;  
   
    p = head->next;  
    while(total!=1)  
    {  
        for(i=1;i<(head->c)-'0'-1;i++)  
        {  
            p = p->next;  
        }  
        printf("%c",p->next->c);  
        q = p->next;  
        p->next = p->next->next;  
        free(q);  
        p = p->next;  
        total--;  
        printf(" ");  
    }  
    printf("%c",p->c);  
    return 0;  
}  