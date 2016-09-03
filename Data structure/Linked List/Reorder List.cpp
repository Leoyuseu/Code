// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.

#include<iostream>
#include<deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//with a deque
void reorderList(ListNode* head) {
    if(head==NULL||head->next==NULL||head->next->next==NULL) return;
    deque<ListNode *> nodes;
    ListNode *node=head;
    while(node){
        nodes.push_back(node);
        node=node->next;
    }
    node=head;
    nodes.pop_front();
    while(!nodes.empty()){
        node->next=nodes.back();
        nodes.pop_back();
        node=node->next;
        if(!nodes.empty()){
            node->next=nodes.front();
            nodes.pop_front();
            node=node->next;
        }
    }
    node->next=NULL;
}

//with a stack
void reorderList(ListNode *head) {
    ListNode *mid, *end;
    stack<ListNode *> nodestack;
    mid = head;
    end = head;
    if(head == NULL || head->next==NULL || head->next->next == NULL) return;
    while(end->next!=NULL && end->next->next != NULL)
    {
        mid = mid->next;
        end = end->next->next;
    }
    ListNode *L1 = head;
    ListNode *L2 = mid->next;
    while(L2!=NULL)
    {
        nodestack.push(L2);
        L2=L2->next;
    }
    mid->next = NULL;
    while(!nodestack.empty())
    {
        L2 = nodestack.top();
        nodestack.pop();
        L2->next = L1->next;
        L1->next = L2;
        L1 = L2->next;
    }
    return;
}

//split, reverse the second half, and merge
void reorderList(ListNode *head) {
// use fast/slow points to find the second half of the list       
    ListNode *head1, *head2;
    ListNode *preNode, *curNode;

    if(!head || !(head->next) ){// if the list is empty or only has one element
        return;
    }
    else{
        head1 = head;
        head2 = head->next;

        // find the starting point of the second half
        while(head2 && head2->next)
        {
            head1 = head1->next;
            head2 = (head2->next)->next;
        }

        //reverse the second half
        head2 =head1->next; // the head of the second half
        head1->next =NULL;
        preNode = NULL;

        while(head2)
        {
            curNode = head2->next;
            head2->next = preNode;
            preNode= head2;
            head2 = curNode;
        }

        // merge the first half and the reversed second half
        head2 = preNode;
        head1 = head;

        while(head2)
        {
            curNode = head1->next;
            head1 = head1->next = head2;
            head2 = curNode;
        }

        return;
    }
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
	ListNode *node=p1;
	while(node){
		cout<<node->val<<" ";
		node=node->next;
	}
	cout<<endl;
	reorderList(p1);
	node=p1;
	while(node){
		cout<<node->val<<" ";
		node=node->next;
	}
}