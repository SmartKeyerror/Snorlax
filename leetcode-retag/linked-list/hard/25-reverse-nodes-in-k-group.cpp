
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 进阶：
 * 你可以设计一个只使用常数额外空间的算法来解决此问题吗？
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * K 个一组反转链表，那么我们可以将其分成两部分: 反转链表， 以及数 K 个元素
 */
class Solution {
private:
    ListNode *reverseLinkedList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *prev = nullptr, *current = head, *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        if (k == 0 || k == 1) return head;

        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *prev = dummy, *current = head;

        while (current != nullptr) {
            ListNode *start = current;
            
            for (int i = 0; i < k - 1 && current != nullptr; i++) 
                current = current->next;
            
            if (current == nullptr) break;

            ListNode *next = current->next;

            // 断开原有连接
            current->next = nullptr;
            // 反转
            ListNode *reversed = reverseLinkedList(start);

            // 连接
            prev->next = reversed;
            start->next = next;

            prev = start;
            current = next;
        }
        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};