// Reverse a linked list from position m to n. Do it in-place and in one-pass.
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
// return 1->4->3->2->5->NULL.
// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.

// (1) Create a new_head that points to head and use it to locate 
//     the immediate node before the m-th (node it is 1-indexed 
//     according to the problem statement) node, denoted as pre.
// (2) Set cur to be the immediate node after pre and at each time 
//     move a node after cur (denoted to be move) to be the 
//     immediate node after pre. Repeat this process for n - m times.

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* new_head = new ListNode(0);
    new_head -> next = head;
    ListNode* pre = new_head;
    /* Locate pre. */
    for (int i = 0; i < m - 1; i++) 
        pre = pre -> next;
    /* Reverse nodes after cur. */
    ListNode* cur = pre -> next;
    for (int i = 0; i < n - m; i++) {
        ListNode* move = cur -> next;
        cur -> next = move -> next;
        move -> next = pre -> next;
        pre -> next = move;
    }
    return new_head -> next;
} 

//recursive implementation
ListNode* reverse(struct ListNode *head,int n,int count,struct ListNode **ans)
{
    if(count==n)  // when nth node is reached store the address of next of nth node in ans 
    {
        *ans=head->next;
        return head;
    }

    // this is simple recursive code to reverse a linked list

    struct ListNode *temp=reverse(head->next,n,count+1,ans);
    head->next->next=head;
    head->next=NULL;
    return temp;
}
ListNode* reverseBetween(ListNode* head, int m, int n) {

    if(m==n)
        return head;

    int count=1;
    ListNode *temp=NULL,*p=head;

    while(count<m)  // Reach the mth node from head . temp is the prev node of p
    {
        count++;
        temp=p;
        p=p->next;
    }
    ListNode *ans;

    if(temp)   // reverse portion between m & n . when m=1 : temp=NULL 
        temp->next=reverse(p,n,m,&ans);
    else        // for cases where m=1 i.e. head is changed
        head=reverse(p,n,m,&ans);

    p->next=ans;  // ans contain the address of next node of n .
    return head;
}


// ReverseList.cpp 
ListNode* ReverseList(ListNode* pHead)
{
    //ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    while(pNode != NULL)
    {
        ListNode* pNext = pNode->m_pNext;

		//if (pNext == NULL)
		//	return pNode;//pReversedHead = pNode;

        pNode->m_pNext = pPrev;

        pPrev = pNode;
        //pNode = pNext;

		if (pNext == NULL)
			return pNode;//pReversedHead = pNode;
		pNode = pNext;
    }

    //return pReversedHead;
}

//my inplementation
ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *p1, *p2, *p3;
	p1 = head, p2 = p1->next;
	while (p2){
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = NULL;
	head = p1;
	return head;
}