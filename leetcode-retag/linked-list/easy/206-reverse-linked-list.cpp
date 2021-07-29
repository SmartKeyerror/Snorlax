

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 边界条件判断
        if (head == nullptr) return nullptr;

        ListNode *prev = nullptr, *current = head;
        ListNode *next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};
