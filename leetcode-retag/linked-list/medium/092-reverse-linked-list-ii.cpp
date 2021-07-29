

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;

        ListNode *cur = head, *prev = nullptr;

        // 找到反转链表的起始点以及起始点之前的那一个节点
        for (int i = 0; i < m - 1; i++) {
            prev = cur;
            cur = cur->next;
        }

        // 保存两个指针，后续需要使用
        ListNode *start = prev, *tail = cur;

        ListNode *next = nullptr;
        for (int i = 0; i <= n - m; i++) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        if (start != nullptr) {
            start->next = prev;
        } else {
            head = prev;
        }

        tail->next = cur;
        return head;
    }
};
