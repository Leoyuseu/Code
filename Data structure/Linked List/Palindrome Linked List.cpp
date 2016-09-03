#include<iostream>
#include<stack>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//O(n) time, O(n) space 
bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL) return true;
    stack<ListNode*> halfnodes;
    ListNode *fast=head;
	ListNode *slow=head;
    while(fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
        if(!fast->next) break;        
    }
    slow=slow->next;
    while(slow){
        halfnodes.push(slow);
        slow=slow->next;
    }
    
    ListNode *pos=head;
    while(!halfnodes.empty()){
        if((halfnodes.top()->val)!=(pos->val)) return false;
		halfnodes.pop();
        pos=pos->next;
    }
    return true;
}


//O(n) time, O(1) space 
bool isPalindrome(ListNode* head) {
    if(!head) return true;
    ListNode* slow = head;
    ListNode* fast = slow->next;
    // separate
    while(fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = NULL;

    //reverse list
    ListNode* prev = NULL;
    ListNode* cur = head2;
    ListNode* next = NULL;
    while(head2) {
        next = head2->next;
        head2->next = prev;
        prev = head2;
        head2 = next;
    }

    //compare
    head2 = prev;
    while(head && head2) {
        if(head->val != head2->val)
            return false;

        head = head->next;
        head2 = head2->next;
    }
    return true;
}

int main(){
	ListNode *p1=new ListNode(1);
	ListNode *p2=new ListNode(2);
	ListNode *p3=new ListNode(3);
	ListNode *p4=new ListNode(4);
	ListNode *p5=new ListNode(5);
	p1->next=p2;
	p2->next=p3;
	p3->next=p4;
	p4->next=p5;
	cout<<isPalindrome(p1);
}
