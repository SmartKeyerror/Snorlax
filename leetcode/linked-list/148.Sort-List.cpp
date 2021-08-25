

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 */
class Solution {
private:
    // 合并两个有序链表
    ListNode *mergeSortedList(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode();
        ListNode *prev = dummy;

        ListNode *cur1 = l1, *cur2 = l2;

        // 由于链表的特殊性，这里首先将 l1 和 l2 都存在时的部分 merge 掉，剩余的部分可以直接挂到链表后面
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                prev->next = cur1;
                cur1 = cur1->next;
            } else {
                prev->next = cur2;
                cur2 = cur2->next;
            }
            prev = prev->next;
        }
        if (cur1 != nullptr) prev->next = cur1;
        if (cur2 != nullptr) prev->next = cur2;

        return dummy->next;
    }

    // 寻找链表的中间节点，并断开其原有连接
    ListNode *findMid(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = nullptr;
        ListNode *slow = head, *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        return slow;
    }

    ListNode *mergeSort(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *mid = findMid(head);

        ListNode *left = mergeSort(head);
        ListNode *right = mergeSort(mid);

        return mergeSortedList(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};