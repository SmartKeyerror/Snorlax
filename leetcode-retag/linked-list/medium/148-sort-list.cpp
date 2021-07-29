
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 进阶：
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 * 
 * 对于链表来说，比较方便的就是归并排序
 */

class Solution {
private:
    ListNode *splitListWithMid(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode *prev = nullptr;
        ListNode *slow = head, *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 断开原有链表
        prev->next = nullptr;
        return slow;
    }

    ListNode *merge(ListNode *L1, ListNode *L2) {
        ListNode *dummy = new ListNode();
        ListNode *current = dummy;

        ListNode *l1 = L1, *l2 = L2;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        if (l1 != nullptr) current->next = l1;
        if (l2 != nullptr) current->next = l2;

        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *mid = splitListWithMid(head);

        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);

        return merge(left, right);
    }
};
