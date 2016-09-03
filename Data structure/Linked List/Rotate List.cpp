// Given a list, rotate the list to the right by k places, where k is non-negative.
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode *node=head;
        int size=0;
        while(node->next){
            ++size;
            node=node->next;
        }
        ++size;
        k%=size;
        node->next=head;
        ListNode *newend=head;
        for(int i=0;i<size-k-1;++i){
            newend=newend->next;
        }
        ListNode *newhead=newend->next;
        newend->next=NULL;
        return newhead;
    }
};