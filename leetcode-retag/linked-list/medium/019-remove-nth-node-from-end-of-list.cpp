
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
 * 
 * 首先，使用双指针的方式找到倒数第 N 个节点，以及第 N 个节点前面的那个节点。
 * 
 * 同时，由于 head 指针可能会被删除，所以使用 dummy 来完成
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *prev = dummy, *current = head, *aux = head;

        for (int i = 0; i < n; i++) {
            aux = aux->next;
        }

        while (aux != nullptr) {
            prev = current;
            current = current->next;
            aux = aux->next;
        }

        prev->next = current->next;
        current->next = nullptr;
        delete current;

        ListNode *newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};