#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(INT_MIN);
    ListNode *prev, *cur, *next;

    for (auto p = head; p; p = next) {
        next = p->next;
        // invariant: list headed by dummy.next is sorted
        for (prev = &dummy, cur = prev->next; cur && p->val > cur->val; prev = cur, cur = cur->next)
            ;
        prev->next = p;
        p->next = cur;
    }
    return dummy.next;
}


ListNode* insertionSortList(ListNode* head) {
    ListNode* new_head = new ListNode(0);
    new_head -> next = head;
    ListNode* pre = new_head;
    ListNode* cur = head;
    while (cur) {
        if (cur -> next && cur -> next -> val < cur -> val) {
            while (pre -> next && pre -> next -> val < cur -> next -> val)
                pre = pre -> next;
            /* Insert cur -> next after pre.*/
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = temp;
            /* Move pre back to new_head. */
            pre = new_head;
        }
        else cur = cur -> next;
    }
    ListNode* res = new_head -> next;
    delete new_head;
    return res;
}

    //*****my own wrong solution*****
    // ListNode *pos=head->next;
    //     ListNode *help=new ListNode(INT_MIN);
    //     help->next=head;
    //     while(pos){
    //         ListNode *pre=help;
    //         ListNode *insert=pos;
    //         while(pos!=pre->next){
    //             if(pre->val<=pos->val&&pos->val<pre->next->val){
    //                 //pre->next->next=pos->next;
    //                 ListNode *prepos=pre;
    //                 while(prepos->next!=pos){
    //                     prepos=prepos->next;
    //                 }
    //                 prepos->next=insert->next;
    //                 insert->next=pre->next;
    //                 pre->next=insert;
    //                 pos=prepos->next;
    //                 break;
    //             }
    //             pre=pre->next;
    //         }
    //         pos=pos->next;
    //     }
    // return help->next;
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

}