//Partition List 
// Given a linked list and a value x, partition it such that all nodes 
// less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each 
// of the two partitions.

// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.

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
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0), node2(0);
        ListNode *p1 = &node1;
        ListNode *p2 = &node2; 
        while(head){
            if(head->val < x){
                p1->next = head;
                p1 = p1->next;
            }
            else{
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p1->next = node2.next;
        p2->next = NULL;
        return node1.next;
    }
};