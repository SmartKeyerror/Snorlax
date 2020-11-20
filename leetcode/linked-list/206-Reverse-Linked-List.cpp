

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 如果不使用递归的方式来反转一个链表的话，我们需要至少 3 个指针来完成这件事情:
 *  - prev: 从 NULL 指针开始，或者说从头指针之前的那个指针开始，表示前一个节点
 *  - current: 从头结点开始，表示当前需要处理的节点
 *  - next: 从头节点的下一个节点开始，用于维护链表的连接，使得我们在操作时不会使链表产生断裂
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (!head || !head->next)
            return head;
        
        ListNode *prev = nullptr, *current = head;

        while (current != nullptr) {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};
