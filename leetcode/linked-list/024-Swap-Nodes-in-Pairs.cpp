

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return nullptr;
        
        // 用一个哨兵节点省去对头结点的特殊处理
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // prev 表示要交换顺序的两个节点的之前一个节点
        ListNode *prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode *node1 = prev->next, *node2 = node1->next, *tail = node2->next;

            node2->next = node1;
            prev->next = node2;
            node1->next = tail;

            prev = node1;
        }

        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
