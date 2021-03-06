\chapter{排序}

\section{Merge Sorted Array} %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\label{sec:merge-sorted-array}


\subsubsection{描述}
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.


\subsubsection{分析}
无


\subsubsection{代码}
\begin{Code}
//LeetCode, Merge Sorted Array
// 时间复杂度O(m+n)，空间复杂度O(1)
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int ia = m - 1, ib = n - 1, icur = m + n - 1;
        while(ia >= 0 && ib >= 0) {
            A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
        }
        while(ib >= 0) {
            A[icur--] = B[ib--];
        }
    }
};
\end{Code}


\subsubsection{相关题目}
\begindot
\item Merge Two Sorted Lists，见 \S \ref{sec:merge-two-sorted-lists}
\item Merge k Sorted Lists，见 \S \ref{sec:merge-k-sorted-lists}
\myenddot


\section{Merge Two Sorted Lists} %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\label{sec:merge-two-sorted-lists}


\subsubsection{描述}
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


\subsubsection{分析}
无


\subsubsection{代码}
\begin{Code}
//LeetCode, Merge Two Sorted Lists
// 时间复杂度O(min(m,n))，空间复杂度O(1)
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        for (; l1 != nullptr && l2 != nullptr; p = p->next) {
            if (l1->val > l2->val) { p->next = l2; l2 = l2->next; }
            else { p->next = l1; l1 = l1->next; }
        }
        p->next = l1 != nullptr ? l1 : l2;
        return dummy.next;
    }
};
\end{Code}


\subsubsection{相关题目}
\begindot
\item Merge Sorted Array \S \ref{sec:merge-sorted-array}
\item Merge k Sorted Lists，见 \S \ref{sec:merge-k-sorted-lists}
\myenddot


\section{Merge k Sorted Lists} %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\label{sec:merge-k-sorted-lists}


\subsubsection{描述}
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.


\subsubsection{分析}
可以复用Merge Two Sorted Lists（见 \S \ref{sec:merge-two-sorted-lists}）的函数


\subsubsection{代码}
\begin{Code}
//LeetCode, Merge k Sorted Lists
// 时间复杂度O(n1+n2+...)，空间复杂度O(1)
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;

        // ListNode *p = lists[0];
        // for (int i = 1; i < lists.size(); i++) {
        //     p = mergeTwoLists(p, lists[i]);
        // }
        // return p;
        while(lists.size() > 1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
        }
        return lists.front();
    }

    // Merge Two Sorted Lists
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(-1);
        for (ListNode* p = &head; l1 != nullptr || l2 != nullptr; p = p->next) {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            if (val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return head.next;
    }
};
\end{Code}
//solution with priority_queue
class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }
        if (q.empty()) {
            return NULL;
        }
        ListNode* result = q.top();
        q.pop();
        if (result->next) {
            q.push(result->next);
        }
        ListNode* tail = result;            
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next) {
                q.push(tail->next);
            }
        }
        return result;
    }
};

\subsubsection{相关题目}
\begindot
\item Merge Sorted Array \S \ref{sec:merge-sorted-array}
\item Merge Two Sorted Lists，见 \S \ref{sec:merge-two-sorted-lists}
\myenddot


\section{Insertion Sort List} %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\label{sec:Insertion-Sort-List}


\subsubsection{描述}
Sort a linked list using insertion sort.


\subsubsection{分析}
无


\subsubsection{代码}
\begin{Code}
// LeetCode, Insertion Sort List
// 时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        //dummy.next = head;

        for (ListNode *cur = head; cur != nullptr;) {
            auto pos = findInsertPos(&dummy, cur->val);
            ListNode *tmp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }

    ListNode* findInsertPos(ListNode *head, int x) {
        ListNode *pre = nullptr;
        for (ListNode *cur = head; cur != nullptr && cur->val <= x;
            pre = cur, cur = cur->next)
            ;
        return pre;
    }
};
\end{Code}


\subsubsection{相关题目}
\begindot
\item Sort List, 见 \S \ref{sec:Sort-List}
\myenddot


\section{Sort List} %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\label{sec:Sort-List}


\subsubsection{描述}
Sort a linked list in $O(n log n)$ time using constant space complexity.


\subsubsection{分析}
常数空间且$O(nlogn)$，单链表适合用归并排序，双向链表适合用快速排序。本题可以复用 "Merge Two Sorted Lists" 的代码。


\subsubsection{代码}
\begin{Code}
// LeetCode, Sort List
// 归并排序，时间复杂度O(nlogn)，空间复杂度O(1)
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)return head;

        // 快慢指针找到中间节点
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 断开
        fast = slow;
        slow = slow->next;
        fast->next = NULL;

        ListNode *l1 = sortList(head);  // 前半段排序
        ListNode *l2 = sortList(slow);  // 后半段排序
        return mergeTwoLists(l1, l2);
    }

    // Merge Two Sorted Lists
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        for (ListNode* p = &dummy; l1 != nullptr || l2 != nullptr; p = p->next) {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            if (val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};
\end{Code}


\subsubsection{相关题目}
\begindot
\item Insertion Sort List，见 \S \ref{sec:Insertion-Sort-List}
\myenddot


\section{First Missing Positive} %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\label{sec:first-missing-positive}


\subsubsection{描述}
Given an unsorted integer array, find the first missing positive integer.

For example,
Given \fn{[1,2,0]} return \fn{3},
and \fn{[3,4,-1,1]} return \fn{2}.

Your algorithm should run in $O(n)$ time and uses constant space.


\subsubsection{分析}
本质上是桶排序(bucket sort)，每当\fn{A[i]!= i+1}的时候，将A[i]与A[A[i]-1]交换，直到无法交换为止，终止条件是 \fn{A[i]== A[A[i]-1]}。


\subsubsection{代码}
\begin{Code}
// LeetCode, First Missing Positive
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        bucket_sort(A, n);
        
        for (int i = 0; i < n; ++i)
            if (A[i] != (i + 1))
                return i + 1;
        return n + 1;
    }
private:
    static void bucket_sort(int A[], int n) {
        for (int i = 0; i < n; i++) {
            while (A[i] != i + 1) {
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;
                swap(A[i], A[A[i] - 1]);
            }
        }
    }
};
\end{Code}


\subsubsection{相关题目}
\begindot
\item Sort Colors, 见 \S \ref{sec:sort-colors}
\myenddot


\section{Sort Colors} %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\label{sec:sort-colors}


\subsubsection{描述}
Given an array with $n$ objects colored red, white or blue, sort them so that 
objects of the same color are adjacent, with the colors in the order red, 
white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

\textbf{Follow up:}

A rather straight forward solution is a two-pass algorithm using counting sort.

First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?


\subsubsection{分析}
由于0, 1, 2 非常紧凑，首先想到计数排序(counting sort)，但需要扫描两遍，不符合题目要求。

由于只有三种颜色，可以设置两个index，一个是red的index，一个是blue的index，两边往中间走。
间复杂度$O(n)$，空间复杂度$O(1)$。

第3种思路，利用快速排序里 partition 的思想，第一次将数组按0分割，第二次按1分割，
排序完毕，可以推广到$n$种颜色，每种颜色有重复元素的情况。


\subsubsection{代码1}
\begin{Code}
// LeetCode, Sort Colors
// Counting Sort
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void sortColors(int A[], int n) {
        int counts[3] = { 0 }; // 记录每个颜色出现的次数

        for (int i = 0; i < n; i++)
            counts[A[i]]++;

        for (int i = 0, index = 0; i < 3; i++)
            for (int j = 0; j < counts[i]; j++)
                A[index++] = i;

    }
};
\end{Code}


\subsubsection{代码2}
\begin{Code}
// LeetCode, Sort Colors
// 双指针，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void sortColors(int A[], int n) {
        // 一个是red的index，一个是blue的index，两边往中间走
        int red = 0, blue = n - 1;

        for (int i = 0; i < blue + 1;) {
            if (A[i] == 0)
                swap(A[i++], A[red++]);
            else if (A[i] == 2)
                swap(A[i], A[blue--]);
            else
                i++;
        }
    }
};
\end{Code}


\subsubsection{代码3}
\begin{Code}
// LeetCode, Sort Colors
// use partition()
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void sortColors(int A[], int n) {
        partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n,
                bind1st(equal_to<int>(), 1));
    }
};
\end{Code}


\subsubsection{代码4}
\begin{Code}
// LeetCode, Sort Colors
// 重新实现 partition()
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void sortColors(int A[], int n) {
        partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n,
                bind1st(equal_to<int>(), 1));
    }
private:
    template<typename ForwardIterator, typename UnaryPredicate>
    ForwardIterator partition(ForwardIterator first, ForwardIterator last,
            UnaryPredicate pred) {
        auto pos = first;

        for (; first != last; ++first)
            if (pred(*first))
                swap(*first, *pos++);

        return pos;
    }
};
\end{Code}


\subsubsection{相关题目}
\begindot
\item First Missing Positive, 见 \S \ref{sec:first-missing-positive}
\myenddot