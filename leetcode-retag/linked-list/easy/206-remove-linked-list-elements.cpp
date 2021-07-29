


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 * 经典链表实现问题，因为头结点可能会发生变化，因此使用 dummy head。
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;

        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *current = head, *prev = dummy;

        while (current != nullptr) {
            if (current->val == val) {
                prev->next = current->next;

                current->next = nullptr;
                delete current;
                
                current = prev->next;
            } else {
                prev = prev->next;
                current = current->next;
            }
        }

        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};