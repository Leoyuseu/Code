// MergeSortedLists.cpp : Defines the entry point for the console application.
//

// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#include "stdafx.h"
#include "..\Utilities\List.h"

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL) return pHead2;
    if(pHead2 == NULL) return pHead1;

    ListNode* pMergedHead = NULL;

    if(pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }

    return pMergedHead;
}

//leetcode concise
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *pre=new ListNode(0);
        ListNode *n=new ListNode(0);
        pre->next=n;
        if(!l1) return l2;
        if(!l2) return l1;
        while(l1&&l2){
            if(l1->val<l2->val){
                ListNode *nd=new ListNode(l1->val);
                n->next=nd;
                n=nd;
                l1=l1->next;
            }
            else if(l2->val<l1->val){
                ListNode *nd=new ListNode(l2->val);
                n->next=nd;
                n=nd;
                l2=l2->next;
            }
            else if(l1->val==l2->val){
                ListNode *nd=new ListNode(l1->val);
                n->next=nd;
                n=nd;
                nd=new ListNode(l1->val);
                n->next=nd;
                n=nd;
                l1=l1->next;
                l2=l2->next;
            }
        }
        if(l1) n->next=l1;
        if(l2) n->next=l2;
        return pre->next->next;
    }
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    dummy.next = l1;
    ListNode *cur = &dummy;

    while(l2)
    {
        while(cur->next && cur->next->val<=l2->val) cur = cur->next; // if the current list, l1, has a smaller value, then move cur forward
        l1 = cur->next; // otherwise, switch l1 and l2
        cur->next = l2;
        l2 = l1;
    }
    return dummy.next;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

    if(NULL == l1) return l2;
    if(NULL == l2) return l1;

    ListNode* head=NULL;    // head of the list to return

    // find first element (can use dummy node to put this part inside of the loop)
    if(l1->val < l2->val)       { head = l1; l1 = l1->next; }
    else                        { head = l2; l2 = l2->next; }

    ListNode* p = head;     // pointer to form new list

    // I use && to remove extra IF from the loop
    while(l1 && l2){
        if(l1->val < l2->val)   { p->next = l1; l1 = l1->next; }
        else                    { p->next = l2; l2 = l2->next; }
        p=p->next;
    }

    // add the rest of the tail, done!
    if(l1)  p->next=l1;
    else    p->next=l2;

    return head;
}

// ====================测试代码====================
ListNode* Test(char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);
    
    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, NULL);

    DestroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = Test("Test5", NULL, NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

