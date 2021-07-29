
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 * 
 * L0 → L1 → … → Ln-1 → Ln 
 * 
 * 请将其重新排列后变为：
 * 
 * L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 * 
 * 能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        stack<ListNode *> st;

        ListNode *current = head;

        while (current != nullptr) {
            st.push(current);
            current = current->next;
        }

        current = head;

        int n = st.size();
        for (int i = 0; i < n / 2; i++) {
            ListNode *tail = st.top();
            st.pop();

            ListNode *next = current->next;
            current->next = tail;
            tail->next = next;

            current = next;
        }

        current->next = nullptr;
    }
};