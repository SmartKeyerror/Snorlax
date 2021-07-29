


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
 * 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[4,5,1,2,3]
 * 
 * 假如链表长度为 n 的话，那么不管 k 的大小是多少，最终的结果只有 n 个可能。以 [1, 2, 3, 4, 5] 为例:
 * 
 * k = 0, [1, 2, 3, 4, 5]
 * k = 1, [5, 1, 2, 3, 4]
 * k = 2, [4, 5, 1, 2, 3]
 * k = 3, [3, 4, 5, 1, 2]
 * k = 4, [2, 3, 4, 5, 1]
 * k = 5, [1, 2, 3, 4, 5]
 * 
 * 所以，k % n 的结果就是 rotate 的那个分界点。
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;

        // 求出链表长度
        int n = 0;
        ListNode *current = head;
        while (current != nullptr) {
            n ++;
            current = current->next;
        }

        int rotate = k % n;

        // 此时什么都不用做
        if (rotate == 0) return head;

        // 假设原链表被分割成 A-B 两部分，此时 B 的长度就是 rotate, A 的长度就是 n - rotate，最终的结果就是 B->A
        current = head;
        for (int i = 0; i < n - rotate - 1; i++) {
            current = current->next;
        }

        ListNode *newHead = current->next;
        current->next = nullptr;

        current = newHead;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = head;
        return newHead;
    }
};