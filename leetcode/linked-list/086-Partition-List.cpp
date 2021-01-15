

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 题目要求将一个链表根据给定的 x 值分成两部分，前半部分均小于 x，后半部分均大于 x ，并且保持节点间的相对顺序
 * 
 * 有点儿向快排中的 Partition，但是由于链表的特殊性质，我们无法向操作数组那样操作链表。
 * 
 * 可以将这个链表主动的拆成两部分，一部分小于 x 的节点组合一个链表，一部分大于 x 的节点组成一个链表，然后再把这两个链表重新组装起来。
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller_dummy = new ListNode(0), *smaller_next = smaller_dummy;
        ListNode *greater_dummy = new ListNode(0), *greater_next = greater_dummy;

        ListNode *current = head;
        while (current) {
            if (current->val < x) {
                smaller_next->next = current;
                smaller_next = smaller_next->next;
            }
            else {
                greater_next->next = current;
                greater_next = greater_next->next;
            }
            current = current->next;
        }

        smaller_next->next = greater_dummy->next;
        greater_next->next = nullptr;

        ListNode *newHead = smaller_dummy->next;
        delete smaller_dummy, greater_dummy;

        return newHead;
    }
};
