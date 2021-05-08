
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        // 遍历链表的同时每次左移一位即可
        int result = head->val;
        head = head->next;
        while (head != nullptr) {
            result = (result << 1 ) | head->val;
            head = head->next;
        }
        return result;
    }
};