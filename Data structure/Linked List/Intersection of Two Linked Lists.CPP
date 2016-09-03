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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1=headA;
        ListNode *q1=headB;
        int la=0;
        int lb=0;
        while(p1){
            ++la;
            p1=p1->next;
        }
        while(q1){
            ++lb;
            q1=q1->next;
        }
        ListNode *p2=headA;
        ListNode *q2=headB;
        if(la>lb){
            for(int i=0;i<la-lb;++i)
                p2=p2->next;
        }
        else{
            for(int i=0;i<lb-la;++i)
                q2=q2->next;
        }
        while(p2!=q2){
            p2=p2->next;
            q2=q2->next;
        }
        return p2==NULL?NULL:p2;
    }
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    if (p1 == NULL || p2 == NULL) return NULL;
    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        if (p1 == p2) return p1;
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
    return p1;
}
//SAME BUT MORE CONCISE
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *ptrA = headA, *ptrB = headB;
    while (ptrA != ptrB) { 
        ptrA = ptrA ? ptrA->next : headB;
        ptrB = ptrB ? ptrB->next : headA;
    }
    return ptrA;
}


//cycles O(N) time, O(1) memory
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    for (ListNode *cur = headA; cur;) {
        unsigned long *ptr = (unsigned long *)&cur->next;
        cur = cur->next;
        *ptr |= 1;
    }

    ListNode *result = nullptr;
    for (ListNode *cur = headB; cur; cur = cur->next) {
        unsigned long ptr = (unsigned long)cur->next;
        if (ptr & 1) {
            result = cur;
            break;
        }
    }

    for (ListNode *cur = headA; cur; cur = cur->next) {
        unsigned long *ptr = (unsigned long *)&cur->next;
        *ptr &= (~0ULL << 1);
    }

    return result;
}