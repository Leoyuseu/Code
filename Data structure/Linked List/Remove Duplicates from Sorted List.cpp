/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};

class Solution {
public：
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;

        ListNode* cur = head;
        while(cur->next != null) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            }
            else cur = cur->next;
        }
        return head;
    }
};

// Given a sorted linked list, delete all nodes that have duplicate numbers, 
// leaving only distinct numbers from the original list.

// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL) return head;
    ListNode *newhead=new ListNode(0);
    newhead->next=head;
    ListNode *pre=newhead;
    ListNode *cur=pre->next;
    ListNode *del;
    int flag=0;
    while(cur->next){
        if(cur->val==cur->next->val){
            del=cur->next;
            cur->next=cur->next->next;
            delete del;
            flag=1;
        }
        else{
            if(flag==1){
                del=cur;
                pre->next=cur->next;
                cur=cur->next;
                delete del;
                flag=0;
            }
            else{
                cur=cur->next;
                pre=pre->next;
            }
        }
    }
    if(flag==1){
        del=cur;
        pre->next=NULL;
        delete del;
    }
    ListNode *res=newhead;
    delete newhead;
    return res->next;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode fakeHead(0);
    fakeHead.next = head;
    ListNode* pre = &fakeHead;
    ListNode* p = pre->next;
    while (p ) {
        ListNode* pn = p->next;
        if (pn && p->val == pn->val) {
            while (pn && p->val == pn->val) {
                pn = pn->next;
            }
            p = pn;
            pre->next = p;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
    return fakeHead.next;
}

//recursive solution
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return 0;
    if (!head->next) return head;

    int val = head->val;
    ListNode* p = head->next;

    if (p->val != val) {
        head->next = deleteDuplicates(p);
        return head;
    } else {
        while (p && p->val == val) p = p->next;
        return deleteDuplicates(p);
    }
}