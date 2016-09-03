// PrintListInReversedOrder.cpp : Defines the entry point for the console application.
void PrintListReversingly_Iteratively(ListNode* pHead) {
    std::stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while(pNode != NULL) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty()) {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}

void PrintListReversingly_Recursively(ListNode* pHead) {
    if(pHead != NULL) {
        if (pHead->m_pNext != NULL) {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        printf("%d\t", pHead->m_nValue);
    }
}

void PrintListReversingly_vector(ListNode* pHead) {
    ListNode* pNode = pHead;
    std::vector<ListNode*> nodes;
    while (pNode != NULL){
        nodes.push_back(pNode);
        pNode = pNode->m_pNext;
    }
    for (auto it = nodes.rbegin(); it != nodes.rend();++it){
        printf("%d\t", (*it)->m_nValue);
    }
}